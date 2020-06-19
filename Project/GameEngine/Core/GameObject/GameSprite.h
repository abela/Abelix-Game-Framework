//
//  GameSprite.hpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef GameSprite_hpp
#define GameSprite_hpp

#include <stdio.h>
#include "GameObject.h"

namespace gameobject {
    class GameSprite : public GameObject
    {
    public:
        GameSprite() = default;
        GameSprite(char *path,utils::Point3D<float>position);
        ~GameSprite();
    protected:
        virtual void CompileShaders() override;
        void Draw(float deltaTime) override;
    private:
        void LoadTexture(char *path);
        GLuint _mainTexture;
        GLuint _texCoordSlot;
        GLuint _textureUniform;
    };
}

#endif /* GameSprite_hpp */
