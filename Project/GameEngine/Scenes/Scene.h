//
//  Scene.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <memory>
#include "IScene.h"
#include "Camera.h"




namespace scene
{
    template <typename T>
    class BaseScene
    {
    public:
        static T *GetNewScene()
        {
            return T::newScene();
        };
    };

    class Scene : public IScene, public BaseScene<Scene>
    {
    public:
        Scene();
        ~Scene();
        void Update(float deltaTime) override;
        static Scene *newScene();
        void LoadScene() override;
        void UnloadScene() override;
        void OnTouchDown(float pointX, float pointY) override;
        void OnTouchUp(float pointX, float pointY) override;
        void OnTouchMove(float pointX, float pointY) override;
        
    protected:
        //
        std::unique_ptr <game::Camera> m_mainCamera;
    };

}
#endif /* Scene_hpp */
