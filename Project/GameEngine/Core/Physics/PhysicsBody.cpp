//
//  PhysicsBody.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "PhysicsBody.h"
#include <iostream>

namespace physics
{
    PhysicsBody::PhysicsBody() : destroyed(false), isInCollision(false), m_velocity(utils::Point3D<float>(0,0,0))
    {
        
    }
    PhysicsBody::~PhysicsBody()
    {
        std::cout<<"destroying physics body"<<std::endl;
    }
    
    void PhysicsBody::Update(float deltaTime)
    {
        ApplyGravity(utils::Constants::GLOBAL_GRAVITY_CONST,deltaTime);
        UpdateVelocity(deltaTime);
    }
    
    void PhysicsBody::ApplyImpulse(utils::Point3D<float> impulse)
    {
        m_velocity = impulse;
    }
    
    // every dynamic physics body stops sometimes
    void PhysicsBody::UpdateVelocity(float deltaTime)
    {
        if(usesGravity)
            m_velocity = utils::lerp(deltaTime, m_velocity, utils::Point3D<float>(0,0,0));
    }
    
    void PhysicsBody::ApplyGravity(float globalGravity, float deltaTime)
    {
        if(usesGravity)
        {
            //m * (a + g) /2
            float newPosY = mass * (m_velocity.Y + globalGravity) / 2 * deltaTime;
            utils::Point3D<float> newPosition(m_position.X,
                                              m_position.Y + newPosY,
                                              m_position.Z);
            m_position = newPosition;
        }
    }
    
    void PhysicsBody::SetDestroyed(bool destroyed)
    {
        this->destroyed = destroyed;
    }
    
    bool PhysicsBody::IsDestroyed()
    {
        return destroyed;
    }
    
    void PhysicsBody::SetUsesGravity(bool usesGravity)
    {
        this->usesGravity = usesGravity;
    }
    
    bool PhysicsBody::UsesGravity()
    {
        return usesGravity;
    }
    
    utils::Point3D<float> PhysicsBody::GetPosition()
    {
        return m_position;
    }
    
    void PhysicsBody::SetPosition(utils::Point3D<float> position)
    {
        this->m_position = position;
    }
    
    utils::Point3D<float> PhysicsBody::GetVelocity()
    {
        return m_velocity;
    }
    
    //
    void PhysicsBody::SetStatic(bool isStatic)
    {
        this->isStatic = isStatic;
    }
    
    bool PhysicsBody::IsStatic()
    {
        return isStatic;
    }
    
    void PhysicsBody::SetMass(float mass)
    {
        this->mass = mass;
    }
    float PhysicsBody::GetMass()
    {
        return mass;
    }

    void PhysicsBody::SetCollisionEventListener(ICollisionEventListener *userData)
    {
        this->collisionEventListener = userData;
    }
    
    ICollisionEventListener *PhysicsBody::GetCollisionEventListener()
    {
        return collisionEventListener;
    }
    
    bool PhysicsBody::IsInCollision()
    {
        return isInCollision;
    }
    void PhysicsBody::SetIsInCollision(bool isInCollision)
    {
        this->isInCollision = isInCollision;
    }
}
