//
//  MainCharacter.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "MainCharacter.h"
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

namespace flappybird {
    
    MainCharacter::MainCharacter(utils::Point3D<float>position,
                                 utils::Point3D<float> size,
                                 utils::Point3D<float> color) :
    gameobject::GameObject(position, size, color), m_physicsBody(new physics::CirclePhysicsBody()), isDead(false), jumpImpulse(35)
    {
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
    
    MainCharacter::~MainCharacter()
    {
        std::cout<<"destroying main character"<<std::endl;
    }
    
    // override the Getposition, get physics body position
    utils::Point3D<float>MainCharacter::GetPosition() const
    {
        return m_physicsBody->GetPosition();
    }
    
    void MainCharacter::SetPosition(utils::Point3D<float> position)
    {
        m_physicsBody->SetPosition(position);
    }
    
    void MainCharacter::Update(float deltaTime)
    {
        GameObject::Update(deltaTime);
        //
        // every physics based object's position depends on the physics body simulation position
        // so we need to reassign actual gameobject's position from physics body position
        position = m_physicsBody->GetPosition();
    }
    
    void MainCharacter::Draw(float deltaTime)
    {
        // draw simple circle with the radius based on physics body radius
        int numberofSides = 18;
        int numberOfVertices = numberofSides + 2;
        
        GLfloat Pi = 3.14f;
        
        GLfloat circleVerticesX[numberOfVertices];
        GLfloat circleVerticesY[numberOfVertices];
        GLfloat circleVerticesZ[numberOfVertices];
        
        for ( int i = 0; i < numberOfVertices; i++ )
        {
            circleVerticesX[i] = position.X + (m_physicsBody->GetRadius() * cos(2 * Pi * i / numberofSides)) - position.X;
            circleVerticesY[i] = position.Y + (m_physicsBody->GetRadius() * sin(2 * Pi * i / numberofSides)) - position.Y;
            circleVerticesZ[i] = position.Z;
        }

        // define color
        GLfloat colors[( numberOfVertices ) * 3];
        
        GLfloat allCircleVertices[( numberOfVertices ) * 3];
        
        for ( int i = 0; i < numberOfVertices; i++ )
        {
            allCircleVertices[i * 3] = circleVerticesX[i];
            allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
            allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
            //
            colors[i * 3] = color.X;
            colors[( i * 3 ) + 1] = color.Y;
            colors[( i * 3 ) + 2] = color.Z;
            //
        }
        glVertexAttribPointer(m_aPosition, 3, GL_FLOAT, GL_FALSE, 0, allCircleVertices);
        glVertexAttribPointer(m_aColor, 3, GL_FLOAT, GL_TRUE, 0, colors);
        //
        glEnableVertexAttribArray(m_aColor);
        glEnableVertexAttribArray(m_aPosition);
        
        // Draw
        glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
        //
    }
    
    void MainCharacter::Jump()
    {
        m_physicsBody->ApplyImpulse(utils::Point3D<float>(0.0,jumpImpulse,0.0));
    }
    
    // tpuch input for main character
    void MainCharacter::TouchDownInput(float posX, float posY)
    {
        if(isDead)
            return;
        Jump();
    }
    
    // 
    void MainCharacter::OnCollisionEnter(physics::PhysicsBody *otherBody)
    {
        if(isDead == false)
        {
            std::cout<<"collision to pipe"<<std::endl;
            isDead = true;
            App.RestartGame();
        }
    }
    
}
