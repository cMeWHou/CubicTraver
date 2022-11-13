#version 330 core

in vec2 texCoord;

out vec4 glColor;

uniform sampler2D ourTexture1;

void main() {
	glColor = texture(ourTexture1, texCoord);
}