#shader vertex

#version 330 core
layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texPos;
layout(location = 2) in vec3 normal;

uniform mat4 mvp;
uniform vec3 lightPos;

out vec2 TexPos;
out vec3 Normal;
out vec3 toLightVec;
out vec3 toCameraVec;



void main()
{

	vec4 worldPos = mvp * vec4(pos, 1.0);
	gl_Position = worldPos;
	Normal = normalize(mvp * vec4(normal, 0.0)).xyz;
	toLightVec = normalize(lightPos - worldPos.xyz);
	toCameraVec = normalize((inverse(mvp) * vec4(0.0, 0.0, 0.0, 1.0))).xyz - worldPos.xyz;

	TexPos = texPos;
}

#shader fragment

#version 330 core

in vec2 TexPos;
in vec3 Normal;
in vec3 toLightVec;
in vec3 toCameraVec;
out vec4 FragColour;

uniform vec3 lightColour;
uniform sampler2D text;
uniform float shineDampness;
uniform float shininess;


void main()
{
	float dot1 = dot(Normal, toLightVec);
	float brightness = max(dot1, 0.0);
	vec3 diffuse = brightness * lightColour;

	vec3 lightDir = -toLightVec;
	vec3 reflectedLightDir = reflect(lightDir, Normal);
	float specular = max(dot(reflectedLightDir, toCameraVec), 0.0);
	float dampness = pow(specular, shineDampness) * shininess;
	vec3 specularLight = dampness * lightColour;

	FragColour = vec4(diffuse, 1.0) * texture(text, TexPos) + vec4(specularLight, 1.0);
}