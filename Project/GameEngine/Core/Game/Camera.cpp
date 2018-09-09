//
//  Camera.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/9/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include <iostream>
#include "Camera.h"
#include <string>
#include "ShaderManager.h"
#include "Utils.h"

namespace game
{
    Camera::Camera(float m_sceneSize, float m_aspectRatio, float m_near, float m_far)
    {
        this->m_sceneSize = m_sceneSize;
        this->m_aspectRatio = m_aspectRatio;
        this->m_near = m_near;
        this->m_far = m_far;
        //
        m_uProjection = glGetUniformLocation(ShaderManagerInstance.GetUnlitColorProgram(), utils::Constants::SHADER_UNIFORM_PROJ_MATRIX_VAR);
        //
        std::cout<<"creating camera object"<<std::endl;
        //
    }
    //
    Camera::~Camera()
    {
        std::cout<<"destroying camera object"<<std::endl;
    }
    
    void Camera::MakeOrtho(float left, float right, float top, float bottom, float near, float far, float* matrix, int size)
    {
        memset(matrix, 0, sizeof(float) * size);
        
        matrix[0] = 2.0f / (right - left); // [0][0]
        matrix[3] = -(right + left) / (right - left); // [0][3]
        
        matrix[5] = 2.0f / (top - bottom); // [1][1]
        matrix[7] = -(top + bottom) / (top - bottom); // [1][3]
        
        matrix[10] = -2.0f / (far - near); // [2][2]
        matrix[11] = -(far + near) / (far - near); // [2][3]
        matrix[15] = 1.0f; // [3][3]
    }
    
    
    void Camera::Update(float deltaTime)
    {
        GLfloat projection[16] = { 0 };
        //
        MakeOrtho(-m_sceneSize / 2,
                  m_sceneSize / 2,
                  m_sceneSize / 2 / m_aspectRatio,
                  -m_sceneSize / 2 / m_aspectRatio,
                  m_near,
                  m_far,
                  projection,
                  16);
        //
        glUniformMatrix4fv(m_uProjection, 1, false, projection);
    }
}
