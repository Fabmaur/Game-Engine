#shader vertex

// Load vertex attributes
#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texPos;
layout(location = 2) in float TUID;
layout(location = 3) in vec4 colour;

out vec2 texCoord;
uniform mat4 mvp;


// Send attributes to fragment shader
out attrib
{
	vec2 texPos;
	float TUID;
	vec4 colour;
} vsOut;

void main()
{
	// Set fragment shader out variables
	vsOut.texPos = texPos;
	vsOut.TUID = TUID;
	vsOut.colour = colour;

	//Update position with mvp matrix
	gl_Position = mvp * vec4(pos, 1.0f);
}

#shader fragment

#version 330 core


// Get variables from the vertex shader
in attrib
{
	vec2 texPos;
	float TUID;
	vec4 colour;
} fsIn;

// Output colour
out vec4 FragColour;


//Load samplers
uniform sampler2D textures[16];

void main()
{
	// Set the texture depending on the TUID of the vertex attribute
	vec4 texColour = fsIn.colour;
	if (fsIn.TUID > 0.0)
	{
		texColour = texture(textures[int(fsIn.TUID)], fsIn.texPos);
	}
	// Set the colour
	FragColour = texColour;
}