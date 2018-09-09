//
//  ShaderManager.hpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/8/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include <stdio.h>
#include <mutex>
#include <OpenGLES/gltypes.h>
#include "Utils.h"

#define ShaderManagerInstance shaders::ShaderManager::Instance()

namespace shaders {
    class ShaderManager : public utils::Singleton<ShaderManager>
    {
    public:
        
        virtual ~ShaderManager();
        //
        ShaderManager(initializer);
        //
        void initUnlitColorShaders(const char *vertexShaderSource,const char *fragmentShaderSource);
        void initUnlitTextureShaders(const char *vertexShaderSource,const char *fragmentShaderSource);
        //
        const char *GetVertexShaderSource();
        const char *GetFragmentShaderSource();
        //
        GLuint GetUnlitColorProgram();
        GLuint GetUnlitTextureProgram();
        //
        void GlUseUnlitColorProgram();
        void GlUseUnlitTextureProgram();
        //
    private:
        //
        GLuint program_unlit_color;
        GLuint program_unlit_texture;
        //
    };

}

#endif /* ShaderManager_hpp */
