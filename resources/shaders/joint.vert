#version 120

attribute vec3 vertex_position;

uniform mat4 scale_matrix;
uniform mat4 rotation_matrix;
uniform mat4 position_matrix;
uniform mat4 projection_matrix;
uniform mat4 port_view;
uniform float joint_id;
uniform mat4 uniform_inv_bindpose;

varying vec3 shared_joint_id;

void main(void)
{
    vec3 joint_vertex_color[50];
    joint_vertex_color[0] = vec3(1.0,0.0,0.0);joint_vertex_color[1] = vec3(0.0,1.0,0.0);joint_vertex_color[2] = vec3(0.0,0.0,1.0);
    joint_vertex_color[3] = vec3(1.0,1.0,0.0);joint_vertex_color[4] = vec3(1.0,0.0,1.0);joint_vertex_color[5] = vec3(0.0,1.0,1.0);
    joint_vertex_color[6] = vec3(0.8,0.0,0.0);joint_vertex_color[7] = vec3(0.0,0.8,0.0);joint_vertex_color[8] = vec3(0.0,0.0,0.8);
    joint_vertex_color[9] = vec3(0.8,0.8,0.0);joint_vertex_color[10] = vec3(0.8,0.0,0.8);joint_vertex_color[11] = vec3(0.0,0.8,0.8);
    joint_vertex_color[12] = vec3(0.6,0.0,0.0);joint_vertex_color[13] = vec3(0.0,0.6,0.0);joint_vertex_color[14] = vec3(0.0,0.0,0.6);
    joint_vertex_color[15] = vec3(0.6,0.6,0.0);joint_vertex_color[16] = vec3(0.6,0.0,0.6);joint_vertex_color[17] = vec3(0.0,0.6,0.6);
    joint_vertex_color[18] = vec3(0.4,0.0,0.0);joint_vertex_color[19] = vec3(0.0,0.4,0.0);joint_vertex_color[20] = vec3(0.0,0.0,0.4);
    joint_vertex_color[21] = vec3(0.4,0.4,0.0);joint_vertex_color[22] = vec3(0.0,0.4,0.4);joint_vertex_color[23] = vec3(0.2,0.0,0.0);
    joint_vertex_color[24] = vec3(0.0,0.2,0.0);joint_vertex_color[25] = vec3(0.0,0.0,0.2);joint_vertex_color[26] = vec3(0.2,0.0,0.2);
    joint_vertex_color[27] = vec3(0.2,0.2,0.0);joint_vertex_color[28] = vec3(0.0,0.2,0.2);joint_vertex_color[29] = vec3(0.1,0.2,0.2);
    joint_vertex_color[30] = vec3(0.2,1.0,0.2);joint_vertex_color[31] = vec3(0.2,0.2,1.0);joint_vertex_color[32] = vec3(0.1,0.5,0.1);
    joint_vertex_color[33] = vec3(0.6,0.6,0.2);joint_vertex_color[34] = vec3(0.2,0.6,0.6);joint_vertex_color[35] = vec3(0.6,0.2,0.6);
    joint_vertex_color[36] = vec3(0.8,0.4,0.2);joint_vertex_color[37] = vec3(0.2,0.4,0.8);joint_vertex_color[38] = vec3(0.4,0.6,0.1);
    joint_vertex_color[39] = vec3(1.0,4.0,1.0);joint_vertex_color[40] = vec3(0.0,0.0,0.0);joint_vertex_color[41] = vec3(0.1,0.8,0.5);
    joint_vertex_color[42] = vec3(0.2,0.0,0.6);joint_vertex_color[43] = vec3(0.4,0.4,0.4);joint_vertex_color[44] = vec3(0.7,0.4,0.5);
    joint_vertex_color[45] = vec3(0.4,0.3,0.7);joint_vertex_color[46] = vec3(0.4,0.6,0.7);joint_vertex_color[47] = vec3(0.7,0.6,8.0);
    joint_vertex_color[48] = vec3(0.63,0.26,0.2);joint_vertex_color[49] = vec3(0.0,0.0,0.0);

    vec4 vertex = vec4(vertex_position,1.0);
    vertex *= uniform_inv_bindpose;
    vertex *= rotation_matrix;
    vertex *= position_matrix;
    shared_joint_id = joint_vertex_color[int(joint_id)];
    gl_Position = projection_matrix * port_view * vertex;
}