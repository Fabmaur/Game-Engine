#shader vertex

#version 330 core
layout(location = 0) in vec3 aPos;
out vec3 FragPos;

void main()
{
	FragPos = vec4(aPos.x, aPos.y, aPos.z)
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}

#shader fragment

#version 330 core
struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

out vec4 FragColor;
uniform Material material;
uniform lightPos lightpos;

void main()
{

	vec3 ambient = light.ambient * material.ambient;

	// diffuse 
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = lightDir.x;
	vec3 diffuse = light.diffuse * (diff * material.diffuse);

	// specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * (spec * material.specular);

	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}