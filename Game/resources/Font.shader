#shader vertex

#version 330 core
layout(location = 0) in vec4 vertex; // {vec2 pos, vec2 tex}
out vec2 TexCoords;

uniform mat4 mvp;


void main()
{
	// Multiplying position by mvp matrix
	gl_Position = mvp * vec4(vertex.xy, 0.5, 1.0);
	TexCoords = vertex.zw;
}

#shader fragment

#version 330 core
in vec2 TexCoords;
out vec4 colour;

// Getting user colour and font
uniform sampler2D text;
uniform vec3 textColour;

void main()
{
	// Setting transparency based on r value of texture
	vec4 transparency = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
	colour = vec4(textColour, 1.0) * transparency;
}