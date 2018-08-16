//
//  PhysicsEngine.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef PhysicsEngine_hpp
#define PhysicsEngine_hpp

#include <stdio.h>
#include "Updater.h"
#include <memory>
#include <vector>
#include "PhysicsBody.h"
#include "Utils.h"

#define PhysicsEngineInstance physics::PhysicsEngine::Instance()

namespace physics {
    
   
    class PhysicsEngine : public game::IUpdater, public utils::Singleton<PhysicsEngine>
    {
    public:
        PhysicsEngine(initializer);
        ~PhysicsEngine();
        
        void Update(float deltaTime) override;
        
        void CreateBody(PhysicsBody *body);
        
        void Restart();
    protected:
        
    private:
        //
        bool CircleToBoxCollisionIntersection(PhysicsBody *circleBody,PhysicsBody *boxBody);
        //
        float globalGravity;
        std::vector<PhysicsBody*> m_bodies;
        void WorldCollisionListener();
    };
    
}
#endif /* PhysicsEngine_hpp */
