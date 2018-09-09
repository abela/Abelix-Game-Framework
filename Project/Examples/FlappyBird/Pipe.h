//
//  Pipe.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Pipe_hpp
#define Pipe_hpp

#include <stdio.h>
#include "GameSprite.h"
#include "RectanglePhysicsBody.h"
#include "ICollisionEventListener.h"

namespace flappybird {
    class Pipe : public gameobject::GameSprite, public physics::ICollisionEventListener
    {
    public:
        Pipe(utils::Point3D<float>position,
             utils::Point3D<float> size,
             utils::Point3D<float> color);
        ~Pipe();
        void Update(float deltaTime) override;
        void OnCollisionEnter(physics::PhysicsBody *otherBody) override;
        void SetPosition(utils::Point3D<float> position) override;
         utils::Point3D<float> GetPosition() const override;
    protected:
        void Draw(float deltaTime) override;
    private:
        std::unique_ptr <physics::RectanglePhysicsBody> m_physicsBody;
    };
}



#endif /* Pipe_hpp */
