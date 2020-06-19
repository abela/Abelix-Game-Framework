//
//  CircleRandomizer.hpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#ifndef CircleRandomizer_hpp
#define CircleRandomizer_hpp

#include <stdio.h>
#include <vector>
#include "CircleObstacle.h"
namespace caravangame
{
    struct CircleRandomizer  : public game::IUpdater
    {
        CircleRandomizer(int totalCircleCount, int planeWidth, int planeHeight);
        ~CircleRandomizer();
        void Update(float deltaTime) override;
        std::vector<std::unique_ptr<CircleObstacle>> &getObstacles();
    private:
        std::vector<std::unique_ptr<CircleObstacle>> circles;
        void createRandomCircleObject(int planeWidth, int planeHeight);
        void createTestCircleObjects(int count);
    };
}

#endif /* CircleRandomizer_hpp */
