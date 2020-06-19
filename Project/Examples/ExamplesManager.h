//
//  ExamplesManager.hpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef ExamplesManager_hpp
#define ExamplesManager_hpp

#include <stdio.h>
#include "Utils.h"
#include "Updater.h"

namespace examples {
    typedef enum  {
        kFlappyBirdExample,
        kCaravanExample,
    } Examples;

    class ExamplesManager : public game::IUpdater, public utils::Singleton<ExamplesManager>
    {
    public:
        ExamplesManager(initializer);
        virtual ~ExamplesManager();
       
        void RunExample(examples::Examples currentExample);
        
        void Update(float deltaTime);
    };
}




#endif /* ExamplesManager_hpp */
