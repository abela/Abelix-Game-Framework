//
//  GameManager.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <memory>

#include "Updater.h"
#include "Scene.h"
#include "Utils.h"
#include "PhysicsEngine.h"
#include <mutex>

#define App game::Application::Instance()

namespace game {
     
    class Application : public IUpdater, public utils::Singleton<Application>
    {
    public:
        Application(initializer);
        virtual ~Application();
        //
        void Update(float deltaTime) override;
        

        float deltaTime = 0.0;
        //
        void OnApplicationTouchInputDown(float touchX, float touchY);
        //
        void OnApplicationTouchInputUp(float touchX, float touchY);
        //
        void OnApplicationTouchInputMove(float touchX, float touchY);
        //
        void StartGame(scene::Scene *startingScene);
        //
        void RestartGame();
        //
    private:
        // we alwasys have some current scene in memory
        std::unique_ptr <scene::Scene> m_currentScene;
        //
        scene::SceneTypes currentSceneType;
        //
        // replace current scene
        void ReplaceScene(scene:: Scene *nextScene);
        //
        //
    };
}


#endif /* GameManager_hpp */

