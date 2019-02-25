#shader vertex

#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texPos;
layout(location = 2) in float TUID;
layout(location = 3) in vec4 colour;

out vec2 texCoord;
uniform mat4 mvp;

out attrib
{
	vec2 texPos;
	float TUID;
	vec4 colour;
} vsOut;

void main()
{
	vsOut.texPos = texPos;
	vsOut.TUID = TUID;
	vsOut.colour = colour;

	gl_Position = vec4(pos, 1.0f);
}

#shader fragment

#version 330 core

in attrib
{
	vec2 texPos;
	float TUID;
	vec4 colour;
} fsIn;

out vec4 FragColour;

uniform sampler2D textures[16];

void main()
{
	vec4 texColour = fsIn.colour;
	if (fsIn.TUID > 0.0)
	{
		texColour = texture(textures[int(fsIn.TUID)], fsIn.texPos);
	}
	
	FragColour = texColour;
}