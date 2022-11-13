#version 330 core

layout(location = 0) in vec3 IPosition;
layout(location = 1) in vec2 ITexCoord;

out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(IPosition, 1.0f);
    texCoord = ITexCoord;
}