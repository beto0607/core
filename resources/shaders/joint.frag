#version 120

varying vec3 shared_joint_id;

void main(void)
{
    gl_FragColor = vec4(shared_joint_id,1.0);
}