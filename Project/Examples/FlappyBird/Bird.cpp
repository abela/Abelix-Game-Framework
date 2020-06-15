//
//  MainCharacter.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Bird.h"
#include "Utils.h"
#include <iostream>
#include <stddef.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <sys/types.h>
#include <OpenGLES/gltypes.h>
#include <math.h>
#include "PhysicsEngine.h"
#include "Application.h"
#include "FlappyBirdGameScene.h"

namespace flappybird {
    
    Bird::Bird(utils::Point3D<float>position,
                                 utils::Point3D<float> size,
                                 utils::Point3D<float> color) :
    gameobject::GameSprite("bird.png",position), m_physicsBody(new physics::CirclePhysicsBody()), isDead(false), jumpImpulse(35)
    {
        SetSize(size);
        SetColor(color);
        // initialize physics body
        m_physicsBody->physicsBodyType = physics::PhysicsBodyType::kCircle;
        m_physicsBody->SetUsesGravity(true);
        m_physicsBody->SetMass(0.5);
        m_physicsBody->SetStatic(false);
        m_physicsBody->SetPosition(position);
        m_physicsBody->SetCollisionEventListener(this);
        m_physicsBody->SetRadius(size.X);
        //
        PhysicsEngineInstance.CreateBody(m_physicsBody.get());
        //
        std::cout<<"creating main character"<<std::endl;
    }
    
    Bird::~Bird()
    {
        std::cout<<"destroying main character"<<std::endl;
    }
    
    // override the Getposition, get physics body position
    utils::Point3D<float>Bird::GetPosition() const
    {
        return m_physicsBody->GetPosition();
    }
    
    void Bird::SetPosition(utils::Point3D<float> position)
    {
        m_physicsBody->SetPosition(position);
    }
    
    void Bird::Update(float deltaTime)
    {
        GameSprite::Update(deltaTime);
        //
        // every physics based object's position depends on the physics body simulation position
        // so we need to reassign actual gameobject's position from physics body position
        position = m_physicsBody->GetPosition();
    }
    
    void Bird::Jump()
    {
        m_physicsBody->ApplyImpulse(utils::Point3D<float>(0.0,jumpImpulse,0.0));
    }
    
    // tpuch input for main character
    void Bird::TouchDownInput(float posX, float posY)
    {
        if(isDead)
            return;
        Jump();
    }
    
    // 
    void Bird::OnCollisionEnter(physics::PhysicsBody *otherBody)
    {
        if(isDead == false)
        {
            std::cout<<"collision to pipe"<<std::endl;
            isDead = true;
            App.RestartGame(scene::BaseScene<flappybird::FlappyBirdGameScene>::GetNewScene());
        }
    }
    
}
