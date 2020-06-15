//
//  SceneManager.hpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/15/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "Utils.h"
#include "Scene.h"

class SceneManager : public utils::Singleton<SceneManager>
{
public:
    SceneManager(initializer);
    ~SceneManager();
    
    void setCurrentScene(scene::Scene *nextScene);
    
    scene::Scene *getCurrentScene();
    
private:
    // we alwasys have some scene in memory
    std::unique_ptr<scene::Scene> currentScene;
};

#endif /* SceneManager_hpp */
