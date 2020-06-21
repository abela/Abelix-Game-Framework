//
//  Line.cpp
//  OpenGLEsGameFramework
//
//  Created by Abelix on 6/21/20.
//  Copyright © 2020 Giorgi Abelashvili. All rights reserved.
//
#include "Line.h"
#include "ShaderManager.h"
#include <CoreGraphics/CoreGraphics.h>
#include <UIKit/UIKit.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <sys/types.h>
#include <OpenGLES/gltypes.h>


namespace gameobject
{
    Line::Line(char *texturePath,utils::Point3D<float> a, utils::Point3D<float> b, utils::Point3D<float> c) : point_a(a), point_b(b)
    {
        GameSprite::LoadTexture(texturePath);
        GameSprite::CompileShaders();
        SetColor(c);
        GameSprite::SetPosition(utils::Point3D<float>(0,0,0));
    }
    Line::~Line()
    {
    }

    void Line::setPoints(const utils::Point3D<float> point_a,const utils::Point3D<float> point_b)
    {
        this->point_a = point_a;
        this->point_b = point_b;
    }

    void Line::Draw(float deltaTime)
    {
        glUseProgram(ShaderManagerInstance.GetUnlitTextureProgram());
        // Define geometry
        GLfloat line[] = {
            point_a.X,   point_a.Y,  point_a.Z,
            point_a.X,   point_a.Y,  point_a.Z,
            point_b.X,   point_b.Y,  point_b.Z,
            point_b.X,   point_b.Y,  point_b.Z
        };
        
        
        // define color
        GLfloat colors[] = {
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
            color.X, color.Y, color.Z,
        };
        
        GLfloat texCoords[] = {
            0,1,
            1,1,
            0,0,
            1,0,
        };
        //
        glVertexAttribPointer(m_aPosition, 3, GL_FLOAT, GL_FALSE, 0, line);
        glVertexAttribPointer(m_aColor, 3, GL_FLOAT, GL_TRUE, 0, colors);
        glVertexAttribPointer(_texCoordSlot, 2, GL_FLOAT, GL_FALSE,0, texCoords);
        //
        glEnableVertexAttribArray(m_aPosition);
        glEnableVertexAttribArray(m_aColor);
        glEnableVertexAttribArray(_texCoordSlot);
        //
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _mainTexture);
        glUniform1i(_textureUniform, 0);
        // Draw
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    }
}


