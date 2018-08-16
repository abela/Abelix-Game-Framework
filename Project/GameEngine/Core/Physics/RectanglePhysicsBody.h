//
//  RectanglePhysicsBody.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef RectanglePhysicsBody_hpp
#define RectanglePhysicsBody_hpp

#include <stdio.h>
#include "PhysicsBody.h"
namespace physics
{
    class RectanglePhysicsBody : public PhysicsBody
    {
    public:
        //
        struct AABB
        {
            utils::Point3D<float> min;
            utils::Point3D<float> max;
        };
        //
        void InitAABB(utils::Point3D<float> size);
        //
        AABB GetAABB();
        //
        RectanglePhysicsBody();
        ~RectanglePhysicsBody();
        //
        void SetSize(utils::Point3D<float> size);
        utils::Point3D<float> GetSize();
        //
    private:
        utils::Point3D<float> size;
        AABB aabb;
    };
}
#endif /* RectanglePhysicsBody_hpp */
