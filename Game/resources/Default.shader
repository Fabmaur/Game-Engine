#shader vertex

#version 330 core
// Load vertex attributes
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTex;

out vec2 texCoord;
uniform mat4 mvp;

void main()
{
	// Set out variables
	texCoord = aTex;
	gl_Position = mvp * vec4(aPos, 1.0f);
}

#shader fragment

#version 330 core

in vec2 texCoord;
out vec4 FragColour;

uniform sampler2D tex;

void main()
{
	//Set colour to textures colour
	FragColour = texture(tex, texCoord);
}