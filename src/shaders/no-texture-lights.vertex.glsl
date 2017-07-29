#version 330 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 light_position;

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

out float light_intensity;

void main(void) {

	vec3 normal_position = vec3(model * vec4(position, 1.0));
	vec3 vertex_light = light_position - normal_position;
	light_intensity = dot(normalize(normal), normalize(vertex_light));

	gl_Position = projection * view * model * vec4(position, 1.0);
}