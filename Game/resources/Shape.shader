#shader vertex

#version 330 core
layout(location = 0) in vec3 pos;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(pos, 1.0f);
}

#shader fragment

#version 330 core


uniform vec3 colour;
out vec4 FragColour;

void main()
{
	FragColour = vec4(colour, 1.0);
}