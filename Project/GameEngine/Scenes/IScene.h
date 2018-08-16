//
//  IScene.h
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef IScene_h
#define IScene_h

#include "Updater.h"


namespace scene {
    
    
    // enum for scenes in game
    enum SceneTypes
    {
        kMenuScene,
        kGameScene
    };
    
    
    // basic blueprint of scene
    // each scene has load, unload and draw methods
    class IScene : public game::IUpdater
    {
    public:
        virtual ~IScene() {}
        static IScene *GetNewScene();
        virtual void OnTouchDown(float pointX, float pointY) = 0;
    protected:
        virtual void LoadScene() = 0;
        virtual void UnloadScene() = 0;
    };
}



#endif /* IScene_h */
