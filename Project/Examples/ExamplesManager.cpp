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
#include "CaravanGameScene.h"


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
            case kCaravanExample:
                App.StartGame(scene::BaseScene<caravangame::CaravanGameScene>::GetNewScene());
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
