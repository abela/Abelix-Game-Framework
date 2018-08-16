//
//  GameScene.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "GameScene.h"
#include <iostream>
#include "GameObject.h"
#include "MainCharacter.h"
#include "Scene.h"


namespace flappybird
{
    GameScene::GameScene() : m_mainCharacter(new flappybird::MainCharacter(utils::Point3D<float>(0,0,-4.0),
                                                                           utils::Point3D<float>(0.5f,0.5f,0.5f),
                                                                           utils::Point3D<float>(0.0,0.0,1.0))),
                                            m_floor(new flappybird::Pipe(utils::Point3D<float>(0,9,-5),
                                                                         utils::Point3D<float>(8,0.5f,0.5f),
                                                                         utils::Point3D<float>(1,0.0,0.0))),
                                            m_ceilling(new flappybird::Pipe(utils::Point3D<float>(0,-9,-5),
                                                                         utils::Point3D<float>(8,0.5f,0.5f),
                                                                         utils::Point3D<float>(1,0.0,0.0))),
                                            m_pipesManager(new flappybird::PipesManager())
    {
        std::cout<<"creating game scene object"<<std::endl;
        LoadScene();
        //
    }
    
    GameScene * GameScene::GetNewScene()
    {
        return new GameScene();
    }
    
    GameScene::~GameScene()
    {
        std::cout<<"destroying game scene"<<std::endl;
        UnloadScene();
    }
    // custom scene initializer
    void GameScene::LoadScene()
    {
        Scene::LoadScene();
    }
    // custom scene deinitializer
    void GameScene::UnloadScene()
    {
        Scene::UnloadScene();
        m_pipesManager.reset();
    }
    void GameScene::Update(float deltaTime)
    {
        // draw every scene object
        Scene::Update(deltaTime);
        //
        if(m_mainCharacter)
            m_mainCharacter->Update(deltaTime);
        //
        if(m_pipesManager)
            m_pipesManager->Update(deltaTime);
        
        if(m_floor)
            m_floor->Update(deltaTime);
        
        if(m_ceilling)
            m_ceilling->Update(deltaTime);
        //
    }
    void GameScene::OnTouchDown(float pointX, float pointY)
    {
        // handle input in main character
        if(m_mainCharacter)
            m_mainCharacter->TouchDownInput(pointX,pointY);
    }
    
}
