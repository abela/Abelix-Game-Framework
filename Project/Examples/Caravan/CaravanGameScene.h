//
//  CaravanGameScene.hpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#ifndef CaravanGameScene_h
#define CaravanGameScene_h

#include <stdio.h>
#include "Scene.h"
#include "CircleRandomizer.h"
#include "Camel.h"
#include "Line.h"

namespace caravangame
{
    class CaravanGameScene : public scene::Scene, public scene::BaseScene<CaravanGameScene>
    {
    public:
        CaravanGameScene();
        ~CaravanGameScene();
        void Update(float deltaTime) override;
        static CaravanGameScene *newScene();
        void LoadScene() override;
        void UnloadScene() override;
        void OnTouchDown(float pointX, float pointY) override;
    private:
        std::unique_ptr<CircleRandomizer> circleRandomizer;
        std::unique_ptr<gameobject::GameSprite> startPoint;
        std::unique_ptr<gameobject::GameSprite> endPoint;
        std::unique_ptr<Camel> mainCharacter;
        void drawCircleObstacles();
        void randomizeStartAndEnd();
    };
}
#endif /* CaravanGameScene_hpp */
