//
//  CaravanGameScene.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/17/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#include "CaravanGameScene.h"
#include <iostream>
namespace caravangame
{
CaravanGameScene::CaravanGameScene() : circleRandomizer(new CircleRandomizer(10,10,10)),
                                        mainCharacter(new Camel(utils::Point3D<float>(0,-8,-4.0),
                                                        utils::Point3D<float>(0.25f,0.25f,0.25f),
                                                        utils::Point3D<float>(0.0,1.0,0.0),
                                                                utils::Point3D<float>(1.0,7.0,-4.0)))
    {
        
    }
    CaravanGameScene::~CaravanGameScene()
    {
        UnloadScene();
    }
    void CaravanGameScene::Update(float deltaTime)
    {
        scene::Scene::Update(deltaTime);
        circleRandomizer->Update(deltaTime);
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

    void CaravanGameScene::OnTouchDown(float pointX, float pointY)
    {
        mainCharacter->updateDestination(pointX, pointY);
    }
}
