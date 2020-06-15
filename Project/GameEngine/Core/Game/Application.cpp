//
//  GameManager.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Application.h"
#include <iostream>
#include "FlappyBirdGameScene.h"
#include "PhysicsEngine.h"
#include "SceneManager.h"

namespace game
{
    Application::Application(initializer)
    {
        std::cout<<"creating application object"<<std::endl;
    }
    
    Application::~Application()
    {
        std::cout<<"destroying application object"<<std::endl;
    }
    
    void Application::Update(float deltaTime)
    {
        // update physics engine
        PhysicsEngineInstance.Update(deltaTime);
        
        // update current scene
        if(SceneManager::Instance().getCurrentScene())
            SceneManager::Instance().getCurrentScene()->Update(deltaTime);
    }
    
    void Application::StartGame(scene::Scene *startingScene)
    {
        SceneManager::Instance().setCurrentScene(startingScene);
    }
    
    // just replace currentscene with the same scene
    void Application::RestartGame(scene::Scene *nextScene)
    {
        // reset physics engine
        PhysicsEngineInstance.Restart();
        
        SceneManager::Instance().setCurrentScene(scene::BaseScene<flappybird::FlappyBirdGameScene>::GetNewScene());
    }
    
    void Application::OnApplicationTouchInputDown(float touchX, float touchY)
    {
        // handle input on current scene
        if(SceneManager::Instance().getCurrentScene())
            SceneManager::Instance().getCurrentScene()->OnTouchDown(touchX, touchY);
    }
    
    void Application::OnApplicationTouchInputUp(float touchX, float touchY)
    {
        // handle input on current scene
        if(SceneManager::Instance().getCurrentScene())
            SceneManager::Instance().getCurrentScene()->OnTouchUp(touchX, touchY);
    }
    
    void Application::OnApplicationTouchInputMove(float touchX, float touchY)
    {
        // handle input on current scene
        if(SceneManager::Instance().getCurrentScene())
            SceneManager::Instance().getCurrentScene()->OnTouchMove(touchX, touchY);
    }
}
