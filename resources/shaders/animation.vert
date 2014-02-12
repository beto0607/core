#version 120

attribute vec3 vertex_position;
attribute vec2 vertex_color;
uniform mat3 scale_matrix;
uniform mat3 rotation_matrix;
uniform mat3 position_matrix;
uniform mat4 projection_matrix;
uniform mat4 port_view;
varying vec2 uv_coord;

void main(void)
{
    vec3 vertex = vertex_position;
    vertex *= scale_matrix;
    vertex[0] += position_matrix[0][2];
    vertex[1] += position_matrix[1][2];
    uv_coord = vertex_color;
    gl_Position = projection_matrix  * vec4(vertex, 1.0);
}