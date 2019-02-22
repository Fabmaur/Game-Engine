#shader vertex

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColour;

out vec4 ourColour;
uniform mat4 mvp;



void main()
{
	ourColour = aColour;
	gl_Position = vec4(aPos, 1.0f);
}

#shader fragment

#version 330 core

in vec4 ourColour;
out vec4 FragColour;

void main()
{
	FragColour = ourColour;
}