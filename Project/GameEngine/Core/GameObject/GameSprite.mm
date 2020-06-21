//
//  GameSprite.cpp
//  OpenGLEsGameFramework
//
//  Created by Giorgi Abelashvili on 9/2/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "GameSprite.h"
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
    GameSprite::GameSprite(char *path,utils::Point3D<float>position) : GameObject(position)
    {
        LoadTexture(path);
        CompileShaders();
    }
    GameSprite::GameSprite(char *path,utils::Point3D<float>position,utils::Point3D<float>size, utils::Point3D<float>color)
    {
        LoadTexture(path);
        CompileShaders();
        SetSize(size);
        SetColor(color);
    }
    //
    void GameSprite::LoadTexture(char* path)
    {
        NSString *fileName = [[NSString alloc] initWithCString:path encoding:NSUTF8StringEncoding];
        CGImageRef spriteImage = [UIImage imageNamed:fileName].CGImage;
        if (!spriteImage) {
            NSLog(@"Failed to load image %@", fileName);
            exit(1);
        }
        GLsizei width = (GLsizei)CGImageGetWidth(spriteImage);
        GLsizei height = (GLsizei)CGImageGetHeight(spriteImage);
        GLubyte * spriteData = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        CGContextRef spriteContext = CGBitmapContextCreate(spriteData, width, height, 8, width*4,
                                                           CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);
        CGContextDrawImage(spriteContext, CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &_mainTexture);
        glBindTexture(GL_TEXTURE_2D, _mainTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);
        //
        free(spriteData);
        //
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    //
    void GameSprite::CompileShaders()
    {
        m_aPosition = glGetAttribLocation(ShaderManagerInstance.GetUnlitTextureProgram(), utils::Constants::SHADER_ATTRIB_POSITION_VAR);
        m_aColor = glGetAttribLocation(ShaderManagerInstance.GetUnlitTextureProgram(), utils::Constants::SHADER_ATTRIB_COLOR_VAR);
        m_uModelview = glGetUniformLocation(ShaderManagerInstance.GetUnlitTextureProgram(), utils::Constants::SHADER_UNIFORM_MATRIX_VAR);
        _texCoordSlot = glGetAttribLocation(ShaderManagerInstance.GetUnlitTextureProgram(), utils::Constants::SHADER_TEXTURE_COORD_VAR);
        _textureUniform = glGetUniformLocation(ShaderManagerInstance.GetUnlitTextureProgram(), utils::Constants::SHADER_TEXTURE_VAR);
        //
    }
    //
    GameSprite::~GameSprite()
    {
        //
        glDeleteTextures(1, &_mainTexture);
    }

    void GameSprite::Draw(float deltaTime)
    {
        glUseProgram(ShaderManagerInstance.GetUnlitTextureProgram());
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
        
        GLfloat texCoords[] = {
            0,1,
            1,1,
            0,0,
            1,0,
        };
        //
        glVertexAttribPointer(m_aPosition, 3, GL_FLOAT, GL_FALSE, 0, square);
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
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        //
    }
}
