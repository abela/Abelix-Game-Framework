//
//  Line.hpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/21/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include <stdio.h>
#include "GameSprite.h"

namespace gameobject
{
    class Line : public GameSprite
    {
        public:
        Line() = default;
        Line(char *texturePath,utils::Point3D<float> a, utils::Point3D<float> b, utils::Point3D<float> c);
        ~Line();
        void setPoints(const utils::Point3D<float> point_a,const utils::Point3D<float> point_b);
    protected:
        void Draw(float deltaTime) override;
    private:
        utils::Point3D<float> point_a;
        utils::Point3D<float> point_b;
    };
}

#endif /* Line_h */
