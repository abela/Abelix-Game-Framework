//
//  Utils.cpp
//  Abelix-Zeptoplab-Test
//
//  Created by Giorgi Abelashvili on 8/7/18.
//  Copyright © 2018 Giorgi Abelashvili. All rights reserved.
//

#include "Utils.h"

namespace utils {
    const int Constants::QUAD_POS_VERTICES_ARRAY_COUNT = 6;
    const int Constants::QUAD_COLOR_VERTICES_ARRAY_COUNT = 4;
    const GLchar *Constants::SHADER_ATTRIB_POSITION_VAR = "a_position";
    const GLchar *Constants::SHADER_ATTRIB_COLOR_VAR = "a_color";
    const GLchar *Constants::SHADER_UNIFORM_MATRIX_VAR = "u_modelViewMat";
    const GLchar *Constants::SHADER_UNIFORM_PROJ_MATRIX_VAR = "u_projectionMat";
    const int Constants::GLOBAL_GRAVITY_CONST = -20.0f; // game is based on any gravity const
}
