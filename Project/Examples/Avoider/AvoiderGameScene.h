//
//  AvoiderGameScene.hpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef AvoiderGameScene_hpp
#define AvoiderGameScene_hpp

#include <memory>
#include <stdio.h>
#include "Scene.h"
#include "Car.h"
#include "Camera.h"
////

namespace avoider
{
    class AvoiderGameScene : public scene::Scene, public scene::SceneBase<AvoiderGameScene>
    {
    public:
        
        AvoiderGameScene();
        ~AvoiderGameScene();
        void Update(float deltaTime) override;
        static AvoiderGameScene *GetNewScene();
    protected:
        void LoadScene() override;
        void UnloadScene() override;
        void OnTouchDown(float pointX, float pointY) override;
        void OnTouchUp(float pointX, float pointY) override;
        void OnTouchMove(float pointX, float pointY) override;
    private:
        std::unique_ptr <avoider::Car> m_mainCharacter;
        //
    };
}
#endif /* AvoiderGameScene_hpp */
