//
//  SceneManager.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/15/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#include "SceneManager.h"

SceneManager::SceneManager(initializer)
{
    
}

SceneManager::~SceneManager()
{
    
}

void SceneManager::setCurrentScene(scene::Scene *nextScene)
{
    currentScene.reset(nextScene);
}

scene::Scene * SceneManager::getCurrentScene()
{
    return currentScene.get();
}
