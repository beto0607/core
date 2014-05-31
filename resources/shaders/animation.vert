#version 120

attribute vec3 vertex_position;
attribute vec2 vertex_uv_coordinates;
uniform mat4 scale_matrix;
uniform mat4 position_matrix;
uniform mat4 projection_matrix;
uniform mat4 port_view;
varying vec2 uv_coord;

void main(void)
{
    vec4 vertex = vec4(vertex_position,1.0);
    vertex *= scale_matrix;
    vertex *= position_matrix;
    gl_Position = projection_matrix * port_view * vertex;
    uv_coord = vertex_uv_coordinates;
}