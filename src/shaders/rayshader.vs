#version 410 core

layout (location = 0) in vec3 vertex_pos;

out vec3 pixel_pos;

void main() {
	gl_Position.xyz = vertex_pos;
	gl_Position.w = 1.0;
	pixel_pos = vertex_pos;
}