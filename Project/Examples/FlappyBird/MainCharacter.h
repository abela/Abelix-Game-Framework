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
#include "GameObject.h"
#include "CirclePhysicsBody.h"

namespace flappybird {

    class MainCharacter : public gameobject::GameObject, public physics::ICollisionEventListener
    {
    public:
        MainCharacter() = default;
        //
        MainCharacter(utils::Point3D<float>position,
                      utils::Point3D<float> size,
                      utils::Point3D<float> color);
        //
        ~MainCharacter();
        
        void Update(float deltaTime) override;
        void TouchDownInput(float posX, float posY);
        utils::Point3D<float> GetPosition() const override;
        void SetPosition(utils::Point3D<float> position) override;
        
        // register collision listener event
        void OnCollisionEnter(physics::PhysicsBody *otherBody) override;
        //
    protected:
        void Draw(float deltaTime) override;
    private:
        float jumpImpulse;
        bool isDead;
        std::unique_ptr <physics::CirclePhysicsBody> m_physicsBody;
        void Jump();
        //
    };
}



#endif /* MainCharacter_hpp */
