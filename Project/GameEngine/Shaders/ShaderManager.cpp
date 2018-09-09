//
//  ShaderManager.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/8/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//
#include <iostream>
#include "ShaderManager.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#include <sys/types.h>
#include <OpenGLES/gltypes.h>
namespace shaders {
    
    ShaderManager::ShaderManager(initializer)
    {
        std::cout<<"creating shader manager object"<<std::endl;
    }
    
    GLuint ShaderManager::GetUnlitColorProgram()
    {
        return program_unlit_color;
    }
    
    GLuint ShaderManager::GetUnlitTextureProgram()
    {
        return program_unlit_texture;
    }
    
    ShaderManager::~ShaderManager()
    {
        std::cout<<"destroying shadermanager object"<<std::endl;
    }
    
    
    
    void ShaderManager::initUnlitColorShaders(const char *vertexShaderSource, const char *fragmentShaderSource)
    {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        //
        GLchar errorLog[255] = "";
        GLsizei outputLength = 0;
        glGetShaderInfoLog(vertexShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        // Create and compile fragment shader
        //
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        errorLog[0] = 0;
        glGetShaderInfoLog(fragmentShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        //
        // Create and link program
        program_unlit_color = glCreateProgram();
        glAttachShader(program_unlit_color, vertexShader);
        glAttachShader(program_unlit_color, fragmentShader);
        glLinkProgram(program_unlit_color);
        //
    }
    
    void ShaderManager::initUnlitTextureShaders(const char *vertexShaderSource, const char *fragmentShaderSource)
    {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        //
        GLchar errorLog[255] = "";
        GLsizei outputLength = 0;
        glGetShaderInfoLog(vertexShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        // Create and compile fragment shader
        //
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        errorLog[0] = 0;
        glGetShaderInfoLog(fragmentShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        //
        // Create and link program
        program_unlit_texture = glCreateProgram();
        glAttachShader(program_unlit_texture, vertexShader);
        glAttachShader(program_unlit_texture, fragmentShader);
        glLinkProgram(program_unlit_texture);
        //
    }
    
    void ShaderManager::GlUseUnlitColorProgram()
    {
        
    }
    
    void ShaderManager::GlUseUnlitTextureProgram()
    {
        
    }
}
