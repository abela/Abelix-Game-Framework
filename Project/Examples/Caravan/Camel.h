//
//  MainCharacter.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Camel_hpp
#define Camel_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include "GameSprite.h"
#include "CircleObstacle.h"
#include "Line.h"

namespace caravangame {

    class Camel : public gameobject::GameSprite
    {
    public:
        //
        Camel(utils::Point3D<float>position,
                      utils::Point3D<float> size,
                      utils::Point3D<float> color,
                        utils::Point3D<float>targetPosition);
        void UpdateWithCirclesArray(std::vector<std::unique_ptr<CircleObstacle>> &circles,float deltaTime);
        ~Camel();
        void updateDestination(float xPos, float yPos);
        //
    private:
        float avoidanceForce;
        bool moving;
        utils::Point3D<float> startPosition;
        utils::Point3D<float> prevPosition;
        float moveSpeed;
        utils::Point3D<float>targetPosition;
        void moveToTarget(std::vector<std::unique_ptr<CircleObstacle>> &circles);
        std::vector<std::unique_ptr<gameobject::Line>> pathToDraw;
        void drawPath(float deltaTime);
        //
    };
}



#endif /* Camel_hpp */
