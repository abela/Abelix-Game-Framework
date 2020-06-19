//
//  CircleRandomizer.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#include "CircleRandomizer.h"
#include "GameSprite.h"
#include <random>

namespace caravangame
{
    CircleRandomizer::CircleRandomizer(int totalCircleCount, int planeWidth, int planeHeight)
    {
        createTestCircleObjects(totalCircleCount);
    }

    CircleRandomizer::~CircleRandomizer()
    {
        
    }

    void CircleRandomizer::Update(float deltaTime)
    {
        for (size_t i =0; i!=circles.size(); ++i) {
            circles[i]->Update(deltaTime);
        }
    }

    void CircleRandomizer::createTestCircleObjects(int count)
    {
        int gridRow = count / 2;
        int gridColumn = count / 2;
        float startX = -4;
        float startY =  5;
        float posX = startX;
        float posY = startY;
        float radius =  0.7f;
        float stepX =   2.5;
        float stepY =   2.5;
        utils::Point3D<float> color(1,0.5,1);
        for (size_t i = 0; i!=gridRow; ++i)
        {
            for (size_t j = 0; j!=gridColumn; ++j)
            {
                utils::Point3D<float> position(posX,posY, -4);
                circles.emplace_back(std::unique_ptr<CircleObstacle>(new CircleObstacle(radius,position,color)));
                posX+=stepX;
            }
            posY-=stepY;
            posX = startX;
        }
    }

    void CircleRandomizer::createRandomCircleObject(int planeWidth, int planeHeight)
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        
        std::uniform_int_distribution<> pos_x_random(-planeWidth/2, planeWidth/2);
        std::uniform_int_distribution<> pos_y_random(-planeHeight/2, planeHeight/2);
        
        std::uniform_int_distribution<> radius_random(1, 2);
        std::uniform_int_distribution<> color_random(0.5, 1);
        
        utils::Point3D<float> position(pos_x_random(eng),pos_x_random(eng),-0.4f);
        float radius = radius_random(eng);
        utils::Point3D<float> color(color_random(eng),color_random(eng),color_random(eng));
        
        circles.emplace_back(std::unique_ptr<CircleObstacle>(new CircleObstacle(radius,position,color)));
    }

    std::vector<std::unique_ptr<CircleObstacle>> &CircleRandomizer::getObstacles()
    {
        return circles;
    }
}
