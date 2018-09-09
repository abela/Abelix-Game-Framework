//
//  Car.cpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Car.h"

namespace avoider {
    //
    Car::Car(utils::Point3D<float>position,
             utils::Point3D<float> size,
             utils::Point3D<float> color) : gameobject::GameSprite("car.png",position)
    {
        SetSize(size);
        SetColor(color);
    }
    //
    Car::~Car()
    {
        
    }
}
