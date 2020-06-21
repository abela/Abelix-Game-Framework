//
//  CaravanGameScene.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#include "CaravanGameScene.h"
#include <iostream>
#include <random>
namespace caravangame
{
CaravanGameScene::CaravanGameScene() : circleRandomizer(new CircleRandomizer(10,10,10)),
                                        mainCharacter(new Camel(utils::Point3D<float>(0,-8,-4.0),
                                                        utils::Point3D<float>(0.25f,0.25f,0.25f),
                                                        utils::Point3D<float>(0.0,1.0,0.0),
                                                                utils::Point3D<float>(1.0,7.0,-4.0))),
startPoint(new gameobject::GameSprite("circle.png",
                                      utils::Point3D<float>(0,-8,-4.0),
                                      utils::Point3D<float>(0.3f,0.3f,0.3f),
                                      utils::Point3D<float>(1,1,1))),

endPoint(new gameobject::GameSprite("circle.png",
                                    utils::Point3D<float>(-100,8.0,-4.0),
                                    utils::Point3D<float>(0.3f,0.3f,0.3f),
                                    utils::Point3D<float>(1,1,1)))
    {
        randomizeStartAndEnd();
    }
    CaravanGameScene::~CaravanGameScene()
    {
        UnloadScene();
    }
    void CaravanGameScene::Update(float deltaTime)
    {
        scene::Scene::Update(deltaTime);
        circleRandomizer->Update(deltaTime);
        startPoint->Update(deltaTime);
        endPoint->Update(deltaTime);
        mainCharacter->UpdateWithCirclesArray(circleRandomizer->getObstacles(), deltaTime);
    }
    CaravanGameScene *CaravanGameScene::newScene()
    {
        return new CaravanGameScene();
    }
    // custom scene initializer
    void CaravanGameScene::LoadScene()
    {
        Scene::LoadScene();
    }
    void CaravanGameScene::UnloadScene()
    {
        circleRandomizer.reset();
    }

    void CaravanGameScene::randomizeStartAndEnd()
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        std::uniform_real_distribution<> pos_x_random_1(-5.0f,5.0f);
        std::uniform_real_distribution<> pos_x_random_2(-5.0f,5.0f);
        
        startPoint->SetPosition(utils::Point3D<float>(pos_x_random_1(eng), -8.0f, -4.0f));
        endPoint->SetPosition(utils::Point3D<float>(pos_x_random_2(eng), 8.0f, -4.0f));
        
        mainCharacter->SetPosition(startPoint->GetPosition());
        
    }

    void CaravanGameScene::OnTouchDown(float pointX, float pointY)
    {
        randomizeStartAndEnd();
        mainCharacter->updateDestination(endPoint->GetPosition().X,endPoint->GetPosition().Y,startPoint->GetPosition().X);
    }
}
