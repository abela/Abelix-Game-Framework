//
//  PipesManager.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/12/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef PipesManager_hpp
#define PipesManager_hpp

#include <stdio.h>
#include <vector>
#include "Updater.h"
#include "Pipe.h"

namespace flappybird {
    class PipesManager : public game::IUpdater
    {
    public:
        PipesManager();
        ~PipesManager();
        
        void Update(float deltaTime) override;
        
       
        
    private:
        std::vector<std::unique_ptr<Pipe>> m_pipes;
        void GeneratePipe(float deltaTime);
        float pipesGenerateTimeCounter;
        float pipesGenerateTime;
        void MovePipes(float deltaTime);
        float pipesMoveSpeed;
         void Reset();
        float movingDimension;
    };
}


#endif /* PipesManager_hpp */
