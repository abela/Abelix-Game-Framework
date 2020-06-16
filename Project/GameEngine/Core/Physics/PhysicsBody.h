//
//  PhysicsBody.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef PhysicsBody_hpp
#define PhysicsBody_hpp

#include <stdio.h>
#include "Updater.h"
#include "ICollisionEventListener.h"
#include "Utils.h"

namespace physics
{

 


    enum PhysicsBodyType{
        kBox,
        kCircle
    };
    

    class PhysicsBody : public game::IUpdater
    {
    public:
        //
        PhysicsBody();
        ~PhysicsBody();
        //
        //
        void CheckCollision(PhysicsBody *otherBody);
        //
        void Update(float deltaTime) override;
        //
        PhysicsBodyType physicsBodyType;
        //
        void SetDestroyed(bool destroyed);
        bool IsDestroyed();
        //
        void SetUsesGravity(bool usesGravity);
        bool UsesGravity();
        //
        utils::Point3D<float> GetPosition();
        void SetPosition(utils::Point3D<float> position);
        utils::Point3D<float> GetVelocity();
        void SetMass(float mass);
        float GetMass();
        //
        void ApplyImpulse(utils::Point3D<float> impulse);
        //m * (a - g) ^2 /2
        //
        void SetCollisionEventListener(ICollisionEventListener *userData);
        ICollisionEventListener *GetCollisionEventListener();
        //
        // if two bodies are static we ignore collision calculations
        void SetStatic(bool isStatic);
        bool IsStatic();
        //
        bool IsInCollision();
        void SetIsInCollision(bool isInCollision);
        //
    private:
        //
        utils::Point3D<float> m_position;
        utils::Point3D<float> m_velocity;
        float mass;
        bool isStatic;
        //
        bool destroyed;
        bool usesGravity;
        bool isInCollision;
        //
        ICollisionEventListener *collisionEventListener;
        void ApplyGravity(float globalGravity, float deltaTime);
        void UpdateVelocity(float deltaTime);
        //
    };
}
#endif /* PhysicsBody_hpp */
