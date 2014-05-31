#version 120

attribute vec3 vertex_position;
attribute vec2 vertex_uv_coordinates;
attribute vec4 vertex_index;
attribute vec4 vertex_weight;
        
uniform mat4 scale_matrix;
uniform mat4 rotation_matrix;
uniform mat4 position_matrix;
uniform mat4 port_view;
uniform mat4 projection_matrix;
uniform mat4 inv_pose[50];
        
varying vec2 uv_coord;

void main(void)
{
    int i1 = int(vertex_index.x);
    int i2 = int(vertex_index.y);  
    int i3 = int(vertex_index.z);  
    int i4 = int(vertex_index.w);
    vec4 vertex = vec4(vertex_position, 1.0);
    vertex *= inv_pose[i1];
    vertex *= scale_matrix;
    vertex *= rotation_matrix;
    vertex *= position_matrix;
    uv_coord = vertex_uv_coordinates;
    gl_Position = projection_matrix  * port_view * vertex;
}