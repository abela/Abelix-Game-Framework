//
//  MainCharacter.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Camel.h"
#include "Utils.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <random>

#define RADIAN_TO_DEGREE_CONST 57.2958f
#define DEGREE_TO_RADIAN_CONST 0.0174533f

namespace caravangame {
    
    Camel::Camel(utils::Point3D<float>position,
                                 utils::Point3D<float> size,
                                 utils::Point3D<float> color,utils::Point3D<float>targetPosition) :
gameobject::GameSprite("circle.png",position), startPosition(position),moveSpeed(0.05f), targetPosition(targetPosition), moving(false), avoidanceForce(1.6f)
    {
        //
        SetSize(size);
        SetColor(color);
        std::cout<<"creating camel character"<<std::endl;
    }

    void Camel::UpdateWithCirclesArray(std::vector<std::unique_ptr<CircleObstacle>> &circles, float deltaTime)
    {
        GameSprite::Update(deltaTime);
        if(moving)
            moveToTarget(circles);
    }

    void Camel::moveToTarget(std::vector<std::unique_ptr<CircleObstacle>> &circles)
    {
        float deltaX = targetPosition.X - position.X;
        float deltaY = targetPosition.Y - position.Y;
        float angle = atan2(deltaY, deltaX);
        
        position.X+= moveSpeed * cos(angle);
        position.Y+= moveSpeed * sin(angle);
    
        for(size_t i =0;i!=circles.size();++i)
        {
            float obstacleThreshold = circles[i]->getAvoidanceThreshold();
            float distanceToObject = position.distanceTo(circles[i]->GetPosition());
            //
            utils::Point3D<float> distanceVectorToObstacle = circles[i]->GetPosition() - position;
            float distanceVectorToObstacleLength = distanceVectorToObstacle.length();
            //
            if(distanceToObject <= obstacleThreshold)
            {
                float thrasholdAndLengthDifference = obstacleThreshold - distanceVectorToObstacleLength;
                utils::Point3D<float> adjustmentVector = distanceVectorToObstacle;
                adjustmentVector.normalize(adjustmentVector.length());
                adjustmentVector = adjustmentVector.scalar(thrasholdAndLengthDifference * avoidanceForce);
                position-=(adjustmentVector * moveSpeed);
            }
        }
        
        float distanceToTarget = position.distanceTo(targetPosition);
        if(distanceToTarget<=0.1f)
            moving = false;
        
    }


    void Camel::updateDestination(float xPos, float yPos)
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        
        std::uniform_int_distribution<> pos_x_random(-8, 8);
        targetPosition = utils::Point3D<float>(pos_x_random(eng), 8, position.Z);
        moving = true;
        position = startPosition;
    }

    Camel::~Camel()
    {
        std::cout<<"destroying camel character"<<std::endl;
    }
}
