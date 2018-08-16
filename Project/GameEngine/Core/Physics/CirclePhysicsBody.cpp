//
//  CirclePhysicsBody.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "CirclePhysicsBody.h"
#include <iostream>

namespace physics
{
    CirclePhysicsBody::CirclePhysicsBody() : physics::PhysicsBody()
    {
        
    }
    
    CirclePhysicsBody::~CirclePhysicsBody()
    {
        
    }
    
    void CirclePhysicsBody::SetRadius(float radius)
    {
        this->radius = radius;
    }
    float CirclePhysicsBody::GetRadius()
    {
        return radius;
    }
}

