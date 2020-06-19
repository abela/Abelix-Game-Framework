//
//  Circle.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#include "CircleObstacle.h"
#include <iostream>
namespace caravangame
{
    CircleObstacle::CircleObstacle(float radius,
                                   utils::Point3D<float>position,
                                   utils::Point3D<float>color) : gameobject::GameSprite("circle.png",position)
    {
        this->radius = radius;
        avoidanceThreshold = (float)radius * 2.0f;
        std::cout<<"circle Obstacle:"<<radius<<std::endl;
        SetSize(utils::Point3D<float>(radius,radius,radius));
        SetColor(color);
    }
    CircleObstacle::~CircleObstacle()
    {
    }

    float CircleObstacle::getRadius() const
    {
        return radius;
    }
    
    float CircleObstacle::getAvoidanceThreshold() const
    {
        return avoidanceThreshold;
    }
}
