//
//  GameObject.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "GameObject.h"
#include "ShaderManager.h"
#include <stddef.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <sys/types.h>
#include <OpenGLES/gltypes.h>

namespace gameobject {
    
    GameObject::GameObject(utils::Point3D<float>position, utils::Point3D<float> size, utils::Point3D<float> color)
    {
        this->position = position;
        this->size = size;
        this->color = color;
        //
        CompileShaders();
    }
    
    GameObject::GameObject(utils::Point3D<float>pos)
    {
        this->position = pos;
        CompileShaders();
    }
    
    GameObject::~GameObject()
    {
        glDeleteBuffers(1, &m_vertexBuffer);
        glDeleteBuffers(1, &m_indexBuffer);
    }
    
    void GameObject::SetPosition(utils::Point3D<float> position)
    {
        this->position = position;
    }
    void GameObject::SetRotation(float rotation)
    {
        this->rotation = rotation;
    }
    void GameObject::SetScale(float scale)
    {
        this->scale = scale;
    }
    
    void GameObject::SetSize(utils::Point3D<float> size)
    {
        this->size = size;
    }
    
    void GameObject::SetColor(utils::Point3D<float> color)
    {
        this->color = color;
    }
    
    utils::Point3D<float> GameObject::GetSize() const
    {
        return size;
    }
    
    utils::Point3D<float> GameObject::GetPosition() const
    {
        return position;
    }
    
    utils::Point3D<float> GameObject::GetColor() const
    {
        return color;
    }
    
    float GameObject::GetRotation() const
    {
        return rotation;
    }
    
    float GameObject::GetScale() const
    {
        return scale;
    }
    
    void GameObject::CompileShaders()
    {
        // read shader attributes
        m_aPosition = glGetAttribLocation(ShaderManagerInstance.GetUnlitColorProgram(), utils::Constants::SHADER_ATTRIB_POSITION_VAR);
        m_aColor = glGetAttribLocation(ShaderManagerInstance.GetUnlitColorProgram(), utils::Constants::SHADER_ATTRIB_COLOR_VAR);
        m_uModelview = glGetUniformLocation(ShaderManagerInstance.GetUnlitColorProgram(), utils::Constants::SHADER_UNIFORM_MATRIX_VAR);
    }
    
    void GameObject::Update(float deltaTime)
    {
        SetModelView();
        Draw(deltaTime);
    }
    void GameObject::Draw(float deltaTime)
    {
        glUseProgram(ShaderManagerInstance.GetUnlitColorProgram());
        // Define geometry
        GLfloat square[] = {
            -size.X, -size.Y, -size.Z,
            size.X, -size.Y, -size.Z,
            -size.X, size.Y, -size.Z,
            size.X, size.Y, -size.Z};
        
        // define color
        GLfloat colors[] = {
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
        };
        //
        glVertexAttribPointer(m_aPosition, 3, GL_FLOAT, GL_FALSE, 0, square);
        glVertexAttribPointer(m_aColor, 3, GL_FLOAT, GL_TRUE, 0, colors);
        glEnableVertexAttribArray(m_aPosition);
        glEnableVertexAttribArray(m_aColor);
        // Draw
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    
    
    void GameObject::SetModelView()
    {
        utils::SMatrix4x4<float> modelview;
        memset( modelview.m_mat, 0, sizeof(float) * 16 );
        modelview.MakeIdentity();
        modelview.SetPosition(position);
        //
        glUniformMatrix4fv(m_uModelview, 1, false, modelview.m_mat);
    }
}
