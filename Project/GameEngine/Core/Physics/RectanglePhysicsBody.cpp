//
//  RectanglePhysicsBody.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "RectanglePhysicsBody.h"

namespace physics {
    
    RectanglePhysicsBody::RectanglePhysicsBody()
    {
        
    }
    RectanglePhysicsBody::~RectanglePhysicsBody()
    {
        
    }
    
    void RectanglePhysicsBody::InitAABB(utils::Point3D<float> size)
    {
        aabb.min.X = -size.X;
        aabb.min.Y = -size.Y;
        
        aabb.max.X = size.X;
        aabb.max.Y = size.Y;
        
    }
    //
    RectanglePhysicsBody::AABB RectanglePhysicsBody::GetAABB()
    {
        return aabb;
    }
    //
    void RectanglePhysicsBody::SetSize(utils::Point3D<float> size)
    {
        this->size = size;
    }
    //
    utils::Point3D<float> RectanglePhysicsBody::GetSize()
    {
        return size;
    }
    
}
