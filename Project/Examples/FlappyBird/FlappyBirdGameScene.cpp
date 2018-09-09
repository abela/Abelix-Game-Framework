//
//  GameScene.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "FlappyBirdGameScene.h"
#include <iostream>
#include "GameObject.h"
#include "Bird.h"
#include "Scene.h"


namespace flappybird
{
    FlappyBirdGameScene::FlappyBirdGameScene() : m_mainCharacter(new flappybird::Bird(utils::Point3D<float>(0,0,-4.0),
                                                                           utils::Point3D<float>(0.5f,0.5f,0.5f),
                                                                           utils::Point3D<float>(1.0,1.0,1.0))),
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
    
    FlappyBirdGameScene * FlappyBirdGameScene::GetNewScene()
    {
        return new FlappyBirdGameScene();
    }
    
    FlappyBirdGameScene::~FlappyBirdGameScene()
    {
        std::cout<<"destroying game scene"<<std::endl;
        UnloadScene();
    }
    // custom scene initializer
    void FlappyBirdGameScene::LoadScene()
    {
        Scene::LoadScene();
    }
    // custom scene deinitializer
    void FlappyBirdGameScene::UnloadScene()
    {
        Scene::UnloadScene();
        m_pipesManager.reset();
    }
    void FlappyBirdGameScene::Update(float deltaTime)
    {
        // draw every scene object
        Scene::Update(deltaTime);
        //
        m_mainCharacter->Update(deltaTime);
        m_pipesManager->Update(deltaTime);
        m_floor->Update(deltaTime);
        m_ceilling->Update(deltaTime);
        //
    }
    void FlappyBirdGameScene::OnTouchDown(float pointX, float pointY)
    {
        // handle input in main character
        m_mainCharacter->TouchDownInput(pointX,pointY);
    }
    
    void FlappyBirdGameScene::OnTouchUp(float pointX, float pointY)
    {
        
    }
    
    void FlappyBirdGameScene::OnTouchMove(float pointX, float pointY)
    {
        
    }
    
}
