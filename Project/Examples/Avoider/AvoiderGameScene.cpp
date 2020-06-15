//
//  AvoiderGameScene.cpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "AvoiderGameScene.h"
#include <iostream>

namespace avoider {
    AvoiderGameScene::AvoiderGameScene() : m_mainCharacter(new avoider::Car(utils::Point3D<float>(0,0,-4.0),
                                                                               utils::Point3D<float>(0.5f,0.5f,0.5f),
                                                                               utils::Point3D<float>(1.0,1.0,1.0)))
    {
        std::cout<<"creating game scene object"<<std::endl;
        LoadScene();
        //
    }
    
    AvoiderGameScene * AvoiderGameScene::newScene()
    {
        return new AvoiderGameScene();
    }
    
    AvoiderGameScene::~AvoiderGameScene()
    {
        std::cout<<"destroying game scene"<<std::endl;
        UnloadScene();
    }
    // custom scene initializer
    void AvoiderGameScene::LoadScene()
    {
        Scene::LoadScene();
    }
    // custom scene deinitializer
    void AvoiderGameScene::UnloadScene()
    {
        Scene::UnloadScene();
    }
    void AvoiderGameScene::Update(float deltaTime)
    {
        // draw every scene object
        Scene::Update(deltaTime);
        //
        if(m_mainCharacter)
            m_mainCharacter->Update(deltaTime);
        //
    }
    void AvoiderGameScene::OnTouchDown(float pointX, float pointY)
    {
        
    }
    
    void AvoiderGameScene::OnTouchUp(float pointX, float pointY)
    {
        
    }
    
    void AvoiderGameScene::OnTouchMove(float pointX, float pointY)
    {
        
    }
    
}
