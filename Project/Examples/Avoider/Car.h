//
//  Car.hpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "GameSprite.h"

namespace avoider {
    class Car : public gameobject::GameSprite
    {
    public:
        Car(utils::Point3D<float>position,
            utils::Point3D<float> size,
            utils::Point3D<float> color);
        ~Car();
    };
}

#endif /* Car_hpp */
