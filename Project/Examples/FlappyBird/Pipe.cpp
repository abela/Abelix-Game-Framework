//
//  Pipe.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Pipe.h"
#include "PhysicsEngine.h"
#include <iostream>

namespace flappybird {
    
    Pipe::Pipe(utils::Point3D<float>position,
               utils::Point3D<float> size,
               utils::Point3D<float> color) : gameobject::GameSprite("pipe.png",position),
        m_physicsBody(new physics::RectanglePhysicsBody())
    {
        SetSize(size);
        SetColor(color);
        // initialize physics body
        m_physicsBody->physicsBodyType = physics::PhysicsBodyType::kBox;
        m_physicsBody->SetUsesGravity(false);
        m_physicsBody->SetMass(10.0);
        m_physicsBody->SetPosition(position);
        m_physicsBody->SetCollisionEventListener(this);
        m_physicsBody->SetStatic(true);
        m_physicsBody->InitAABB(size);
        m_physicsBody->SetSize(size);
        PhysicsEngineInstance.CreateBody(m_physicsBody.get());
        std::cout<<"creating pipe Object"<<std::endl;
    }
    
    Pipe::~Pipe()
    {
        m_physicsBody->SetDestroyed(true);
        //m_physicsBody.reset();
        std::cout<<"destroying pipe object"<<std::endl;
    }
    
    void Pipe::SetPosition(utils::Point3D<float> position)
    {
        m_physicsBody->SetPosition(position);
    }
    
    utils::Point3D<float> Pipe::GetPosition() const
    {
        return m_physicsBody->GetPosition();
    }
    
    void Pipe::Update(float deltaTime)
    {
        GameSprite::Update(deltaTime);
        position = m_physicsBody->GetPosition();
    }
    
    void Pipe::Draw(float deltaTime)
    {
        GameSprite::Draw(deltaTime);
    }
    
    void Pipe::OnCollisionEnter(physics::PhysicsBody *otherBody)
    {
        color.Set(1, 0, 0);
    }
}
