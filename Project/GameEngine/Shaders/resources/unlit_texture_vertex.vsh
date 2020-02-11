
precision mediump float;

attribute vec4 a_position;
attribute vec3 a_color;
attribute vec2 a_texCoordIn;

uniform mat4 u_modelViewMat;
uniform mat4 u_projectionMat;

varying vec2 TexCoord;
varying vec3 Color;

void main() {
    TexCoord = a_texCoordIn;
    Color = a_color;
    gl_Position = a_position * u_modelViewMat * u_projectionMat;
}
