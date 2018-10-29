#shader vertex

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTex;

out vec2 texCoord;

void main()
{
	texCoord = aTex;
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
}

#shader fragment

#version 330 core

in vec2 texCoord;
out vec4 FragColor;
uniform sampler2D tex;

void main()
{
	FragColor = texture(tex, texCoord);
}