//
//  GameScene.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <memory>
#include "Scene.h"
#include "GameObject.h"
#include "Camera.h"
#include "Bird.h"
#include "Pipe.h"
#include "PipesManager.h"
#include "Car.h"

namespace flappybird
{
    class FlappyBirdGameScene : public scene::Scene, public scene::BaseScene<FlappyBirdGameScene>
    {
    public:
        
        FlappyBirdGameScene();
        ~FlappyBirdGameScene();
        void Update(float deltaTime) override;
        static FlappyBirdGameScene *newScene();
    protected:
        void LoadScene() override;
        void UnloadScene() override;
        void OnTouchDown(float pointX, float pointY) override;
        void OnTouchUp(float pointX, float pointY) override;
        void OnTouchMove(float pointX, float pointY) override;
    private:
        //
        void restart();
        //
        std::unique_ptr <flappybird::Bird> m_mainCharacter;
        std::unique_ptr <flappybird::PipesManager> m_pipesManager;
        //
        std::unique_ptr <flappybird::Pipe> m_floor;
        std::unique_ptr <flappybird::Pipe> m_ceilling;
        //
    };
}


#endif /* GameScene_hpp */
