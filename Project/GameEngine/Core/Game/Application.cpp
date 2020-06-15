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
        if(m_currentScene)
            m_currentScene->Update(deltaTime);
    }
    
    // replace any scene anytime
    void Application::ReplaceScene(scene:: Scene *nextScene)
    {
        m_currentScene.reset(nextScene);
    }
    
    void Application::StartGame(scene::Scene *startingScene)
    {
        ReplaceScene(startingScene);
    }
    
    // just replace currentscene with the same scene
    void Application::RestartGame()
    {
        // reset physics engine
        PhysicsEngineInstance.Restart();
        
        // reinstantiate game scene again
        ReplaceScene(scene::BaseScene<flappybird::FlappyBirdGameScene>::GetNewScene());
    }
    
    void Application::OnApplicationTouchInputDown(float touchX, float touchY)
    {
        // handle input on current scene
        if(m_currentScene)
            m_currentScene->OnTouchDown(touchX, touchY);
    }
    
    void Application::OnApplicationTouchInputUp(float touchX, float touchY)
    {
        // handle input on current scene
        if(m_currentScene)
            m_currentScene->OnTouchUp(touchX, touchY);
    }
    
    void Application::OnApplicationTouchInputMove(float touchX, float touchY)
    {
        // handle input on current scene
        if(m_currentScene)
            m_currentScene->OnTouchMove(touchX, touchY);
    }
}
