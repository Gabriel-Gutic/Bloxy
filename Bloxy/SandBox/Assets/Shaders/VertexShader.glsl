#version 330 core
layout (location = 0) in vec3 i_Position;


void main()
{
    gl_Position = vec4(i_Position.xyz, 1.0f);
}