//
//  Camera.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/9/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <OpenGLES/gltypes.h>
#include <OpenGLES/ES2/gl.h>
#include "Updater.h"

namespace game
{
    class Camera : public IUpdater {
        
    public:
        Camera(float m_sceneSize, float m_aspectRatio,float m_near, float m_far);
        ~Camera();
        void Update(float deltaTime) override;
    private:
        void MakeOrtho(float left, float right, float top, float bottom, float near, float far, float* matrix, int size);
        float m_sceneSize;
        float m_aspectRatio;
        float m_near;
        float m_far;
        GLuint m_uProjection;
    };
}


#endif /* Camera_hpp */
