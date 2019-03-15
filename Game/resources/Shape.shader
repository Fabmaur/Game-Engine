#shader vertex

#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texPos;

uniform mat4 mvp;
out vec2 TexPos;

void main()
{
	gl_Position = mvp * vec4(pos, 1.0f);
	TexPos = texPos;
}

#shader fragment

#version 330 core


uniform vec3 colour;
in vec2 TexPos;
uniform sampler2D text;

out vec4 FragColour;

void main()
{
	FragColour = texture(text, TexPos);
}