#version 330 core

out vec4 color;

in float light_intensity;

void main(void) {
	color = vec4(0.7, 0.0, 1.0, 1.0) * light_intensity;
}