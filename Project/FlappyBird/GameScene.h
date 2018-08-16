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
#include "MainCharacter.h"
#include "Pipe.h"
#include "PipesManager.h"

namespace flappybird
{
    class GameScene : public scene::Scene, public scene::SceneBase<GameScene>
    {
    public:
        
        GameScene();
        ~GameScene();
        void Update(float deltaTime) override;
        static GameScene *GetNewScene();
    protected:
        void LoadScene() override;
        void UnloadScene() override;
        void OnTouchDown(float pointX, float pointY) override;
    private:
        std::unique_ptr <flappybird::MainCharacter> m_mainCharacter;
        std::unique_ptr <flappybird::PipesManager> m_pipesManager;
        //
        std::unique_ptr <flappybird::Pipe> m_floor;
        std::unique_ptr <flappybird::Pipe> m_ceilling;
        //
    };

}


#endif /* GameScene_hpp */
