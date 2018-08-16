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
    // alternative of static inheritance, i.e. static virtual functions
    template <typename T>
    struct SceneStaticFuncs
    {
         T* (*getScene)(void);
    };
    
    
    template <typename T>
    class SceneBase
    {
    public:
        SceneStaticFuncs<T> sceneStruct;
        void FillPointers() {
            sceneStruct.getScene = &T::GetNewScene;
        }
        SceneBase() {
            FillPointers();
        }
    };

    class Scene : public IScene, public SceneBase<Scene>
    {
    public:
        Scene();
        virtual ~Scene();
        void Update(float deltaTime) override;
        static Scene *GetNewScene();
    protected:
        void LoadScene() override;
        void UnloadScene() override;
        //
        std::unique_ptr <game::Camera> m_mainCamera;
    };

}
#endif /* Scene_hpp */
