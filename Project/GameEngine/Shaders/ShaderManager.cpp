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
    
    const char *ShaderManager::GetVertexShaderSource()
    {
        return m_vertexShaderSource;
    }
    const char *ShaderManager::GetFragmentShaderSource()
    {
        return m_fragmentShaderSource;
    }
    
    GLuint ShaderManager::GetProgram()
    {
        return program;
    }
    
    ShaderManager::~ShaderManager()
    {
        std::cout<<"destroying shadermanager object"<<std::endl;
    }
    void ShaderManager::initShaders(const char *vertexShaderSource, const char *fragmentShaderSource)
    {
        m_vertexShaderSource = (char*)malloc(sizeof(char) * strlen(vertexShaderSource));
        m_fragmentShaderSource = (char*)malloc(sizeof(char) * strlen(fragmentShaderSource));
        //
        //
        strcpy(m_vertexShaderSource, vertexShaderSource);
        strcpy(m_fragmentShaderSource, fragmentShaderSource);
        //
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &m_vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        //
        GLchar errorLog[255] = "";
        GLsizei outputLength = 0;
        glGetShaderInfoLog(vertexShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        // Create and compile fragment shader
        //
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &m_fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        errorLog[0] = 0;
        glGetShaderInfoLog(fragmentShader, 255, &outputLength, errorLog);
        printf("%s\n", errorLog);
        //
        // Create and link program
        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        // Use program
        glUseProgram(program);
        //
    }
}
