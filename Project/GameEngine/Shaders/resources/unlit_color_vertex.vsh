
precision mediump float;

attribute vec4 a_position;
attribute vec3 a_color;

uniform mat4 u_modelViewMat;
uniform mat4 u_projectionMat;

varying vec3 v_color;


void main() {
    
    v_color = a_color;
    
    gl_Position = a_position * u_modelViewMat * u_projectionMat;
} 
