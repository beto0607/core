#version 120

varying vec2 uv_coord;
uniform sampler2D texture_uniform_1; 

void main(void)
{
      gl_FragColor = texture2D(texture_uniform_1, uv_coord).zyxw;
}