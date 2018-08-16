//
//  Updater.h
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/6/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Updater_h
#define Updater_h

// updater to create Updatable game mechanics for some game objects
// eery updatable game object should implement this class
namespace game {
    class IUpdater
    {
    public:
        virtual ~IUpdater(){};
        protected:
        virtual void Update(float deltaTime) = 0;
    };
}

#endif /* Updater_h */
