//
//  ExamplesManager.cpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "ExamplesManager.h"
#include "FlappyBirdGameScene.h"
#include "Application.h"
#include "FlappyBirdGameScene.h"
#include "AvoiderGameScene.h"


namespace examples {
    ExamplesManager::ExamplesManager(initializer)
    {
        
    }
    ExamplesManager::~ExamplesManager()
    {
        
    }
    //
    // run game - with spme example game
    //
    void ExamplesManager::RunExample(examples::Examples currentExample)
    {
        switch (currentExample) {
            case kFlappyBirdExample:
                App.StartGame(scene::BaseScene<flappybird::FlappyBirdGameScene>::GetNewScene());
                break;
            case kAvoiderExample:
                break;
            case kBubblePopExample:
                break;
            case kAsteroidsExample:
                break;
            default:
                break;
        }
    }
    
    void ExamplesManager::Update(float deltaTime)
    {
        // update application - our application main game loop
        App.Update(deltaTime);
    }
}
