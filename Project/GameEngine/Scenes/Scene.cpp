//
//  Scene.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Scene.h"

namespace scene
{
    // each scene initializes default camera with default parameters, scene size, aspect ratio, near and far
    Scene::Scene() : m_mainCamera(new game::Camera(10.0, 9.0 / 16.0, 0.1, 100))
    {
        LoadScene();
    }
    Scene::~Scene()
    {
        UnloadScene();
    }
    
    void Scene::Update(float deltaTime)
    {
        // each scene renders camera an and UI layer (if we have it)
        if(m_mainCamera)
            m_mainCamera->Update(deltaTime);
    }
    void Scene::LoadScene()
    {
        //
    }
    void Scene::UnloadScene()
    {
        
    }
    Scene * Scene::GetNewScene()
    {
        return nullptr;
    }
}
