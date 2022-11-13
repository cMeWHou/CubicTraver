#version 330 core

out vec4 glColor;

uniform vec3 shapeColor;

void main() {
	glColor = vec4(shapeColor, 1.0f);
}