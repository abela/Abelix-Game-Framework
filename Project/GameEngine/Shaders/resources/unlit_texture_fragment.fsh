//
precision mediump float;
//
uniform sampler2D Texture;
varying vec2 TexCoord;
varying vec3 Color;
//
void main()
{
    vec4 texSample = texture2D(Texture, TexCoord);
    gl_FragColor = texSample * vec4(Color, 1.0);
}
//
