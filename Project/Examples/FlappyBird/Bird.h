//
//  MainCharacter.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/10/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef MainCharacter_hpp
#define MainCharacter_hpp

#include <stdio.h>
#include <memory>
#include "GameSprite.h"
#include "CirclePhysicsBody.h"

namespace flappybird {

    class Bird : public gameobject::GameSprite, public physics::ICollisionEventListener
    {
    public:
        Bird() = default;
        //
        Bird(utils::Point3D<float>position,
                      utils::Point3D<float> size,
                      utils::Point3D<float> color);
        //
        ~Bird();
        
        void Update(float deltaTime) override;
        void TouchDownInput(float posX, float posY);
        utils::Point3D<float> GetPosition() const override;
        void SetPosition(utils::Point3D<float> position) override;
        
        // register collision listener event
        void OnCollisionEnter(physics::PhysicsBody *otherBody) override;
        //
        bool IsDead() const;
        //
        void Reset();
        //
    private:
        utils::Point3D<float> startPosition;
        float jumpImpulse;
        bool isDead;
        physics::CirclePhysicsBody *m_physicsBody;
        void Jump();
        void createPhysicsBody();
        //
    };
}



#endif /* MainCharacter_hpp */
