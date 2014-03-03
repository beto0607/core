#version 120

attribute vec3 vertex_position;
attribute vec2 vertex_color;
uniform mat4 scale_matrix;
uniform mat3 rotation_matrix;
uniform mat4 traslation_matrix;
uniform mat4 projection_matrix;
uniform mat4 port_view;
varying vec2 uv_coord;

void main(void)
{
    vec4 vertex = vec4(vertex_position,1.0);
    vertex *= scale_matrix;
    vertex *= traslation_matrix;
    uv_coord = vertex_color;
    vertex *= port_view;
    gl_Position = projection_matrix * vertex;
}