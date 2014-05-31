#version 120

attribute vec3 vertex_position;
uniform mat4 scale_matrix;
uniform mat4 rotation_matrix;
uniform mat4 position_matrix;
uniform mat4 projection_matrix;

void main(void)
{
    vec4 vertex = vec4(vertex_position,1.0);
    vertex *= position_matrix;
    gl_Position = projection_matrix  * vertex;
}