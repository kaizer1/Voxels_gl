#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 2) in vec2 inTexCoords;

out vec2 exTexCoords;

void main(void)
{
	exTexCoords = inTexCoords;
	gl_Position = vec4(inPosition, 1.0f);
}
