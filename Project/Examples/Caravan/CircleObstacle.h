//
//  Circle.hpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "GameSprite.h"
#include "CirclePhysicsBody.h"

namespace caravangame
{
    struct CircleObstacle  : public gameobject::GameSprite
    {
        CircleObstacle(float radius,utils::Point3D<float>position,utils::Point3D<float>color);
        ~CircleObstacle();
        float getRadius() const;
        float getAvoidanceThreshold() const;
    private:
        float radius;
        float avoidanceThreshold;
    };
}
#endif /* Circle_hpp */
