//
//  PhysicsEngine.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "PhysicsEngine.h"
#include <iostream>
#include "Application.h"
#include "RectanglePhysicsBody.h"
#include "CirclePhysicsBody.h"
#include <algorithm>

namespace physics
{
    // initialize physics engine with global gravity const
    PhysicsEngine::PhysicsEngine(initializer) : globalGravity(utils::Constants::GLOBAL_GRAVITY_CONST)
    {
        std::cout<<"creating physics engine"<<std::endl;
    }
    
    PhysicsEngine::~PhysicsEngine()
    {
    }
    
    void PhysicsEngine::Restart()
    {
        m_bodies.clear();
    }
    
    // updat every physics body that we culd watch
    // if some object is destroyed it physics body destroyed flag
    // so we manage the list and update it from this function 
    void PhysicsEngine::Update(float deltaTime)
    {
        WorldCollisionListener();
        for(int i =0;i<m_bodies.size();i++)
        {
            if(m_bodies[i]!=nullptr)
            {
                if(m_bodies[i]->IsDestroyed())
                {
                    m_bodies.erase(m_bodies.begin() + i);
                    return;
                }
                else m_bodies[i]->Update(deltaTime);
            }
        }
    }
    void PhysicsEngine::CreateBody(PhysicsBody *body)
    {
        m_bodies.emplace_back(body);
    }
    
    bool PhysicsEngine::CircleToBoxCollisionIntersection(PhysicsBody *circleBody,PhysicsBody *boxBody)
    {
        bool inside = false;
        //
        // cast to circle and rectangle
        CirclePhysicsBody *circlePhysicsBody = static_cast<CirclePhysicsBody*>(circleBody);
        RectanglePhysicsBody *rectanglePhysicsBody = static_cast<RectanglePhysicsBody*>(boxBody);
        //
        if(circlePhysicsBody->GetPosition().X > rectanglePhysicsBody->GetPosition().X - rectanglePhysicsBody->GetSize().X - circlePhysicsBody->GetRadius()&&
           circlePhysicsBody->GetPosition().X < rectanglePhysicsBody->GetPosition().X + rectanglePhysicsBody->GetSize().X + circlePhysicsBody->GetRadius()&&
           circlePhysicsBody->GetPosition().Y > rectanglePhysicsBody->GetPosition().Y - rectanglePhysicsBody->GetSize().Y - circlePhysicsBody->GetRadius() &&
           circlePhysicsBody->GetPosition().Y < rectanglePhysicsBody->GetPosition().Y + rectanglePhysicsBody->GetSize().Y + circlePhysicsBody->GetRadius())
        {
            inside = true;
        }
        //
        return inside;
    }
    
    // collision listener
    // very simple collision listener - just iterate through all bodies and detect all possible intersection
    void PhysicsEngine::WorldCollisionListener()
    {
        
        for(int i = 0;i<m_bodies.size();i++)
        {
            for(int j = 1;j<m_bodies.size();j++)
            {
                // avoid collision check for two static bodies
                if(m_bodies[i]->IsStatic() && m_bodies[j]->IsStatic())
                    continue;
                // detect each type of collision:
                // circle vs rect
                // there are many cases - rect to rect, circle to rect, and etc
                // but we need only circle to rect, becase only character can collide to pipes
                switch (m_bodies[i]->physicsBodyType)
                {
                    case PhysicsBodyType::kCircle:
                    {
                        switch (m_bodies[j]->physicsBodyType)
                        {
                            case PhysicsBodyType::kBox:
                            {
                                
                                if(CircleToBoxCollisionIntersection(m_bodies[i],m_bodies[j]))
                                {
                                    // call collision event only once
                                    if(m_bodies[i]->IsInCollision() == false || m_bodies[j]->IsInCollision() == false)
                                    {
                                        m_bodies[i]->SetIsInCollision(true);
                                        m_bodies[j]->SetIsInCollision(true);
                                        ICollisionEventListener *circleCollisionEvent = static_cast<ICollisionEventListener*>(m_bodies[i]->GetCollisionEventListener());
                                        ICollisionEventListener *rectangleCollisionEvent = static_cast<ICollisionEventListener*>(m_bodies[j]->GetCollisionEventListener());
                                        // rise collision enter events on both sides
                                        circleCollisionEvent->OnCollisionEnter(m_bodies[j]);
                                        rectangleCollisionEvent->OnCollisionEnter(m_bodies[i]);
                                    }
                                    //
                                }
                            }
                                break;
                            /*case PhysicsBodyType::kCircle:
                                break;*/
                            default:
                                break;
                            
                        }
                    }
                        break;
                    /*case PhysicsBodyType::kBox:
                    {
                        switch (m_bodies[j]->physicsBodyType)
                        {
                            case PhysicsBodyType::kCircle:
                                break;
                            case PhysicsBodyType::kBox:
                                break;
                                
                            default:
                                break;
                        }
                    }*/
                    default:
                        break;
                }
            }
        }
    }
}
