//
//  CirclePhysicsBody.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef CirclePhysicsBody_hpp
#define CirclePhysicsBody_hpp

#include <stdio.h>
#include "PhysicsBody.h"
namespace physics
{
    class CirclePhysicsBody : public PhysicsBody
    {
    public:
        //
        CirclePhysicsBody();
        ~CirclePhysicsBody();
        //
        void SetRadius(float radius);
        float GetRadius();
        //
    private:
        float radius;
    };
}
#endif /* CirclePhysicsBody_hpp */
