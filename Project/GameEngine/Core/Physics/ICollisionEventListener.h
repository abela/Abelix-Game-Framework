//
//  IPhysicsEventListener.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/11/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef IPhysicsEventListener_hpp
#define IPhysicsEventListener_hpp

#include <stdio.h>


namespace physics {
    class PhysicsBody;
    class PhysicsEngine;
    class ICollisionEventListener
    {
    public:
        virtual ~ICollisionEventListener() {}
        virtual void OnCollisionEnter(PhysicsBody *otherBody) = 0;
        // reserved for future use
        //virtual void OnCollisionExit(PhysicsBody *otherBody) = 0;
        //virtual void OnTriggerEnter(PhysicsBody *otherBody) = 0;
        //virtual void OnTriggerExit(PhysicsBody *otherBody) = 0;
    };

}

#endif /* IPhysicsEventListener_hpp */
