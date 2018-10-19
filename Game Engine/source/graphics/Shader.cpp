#include "Shader.h"


Shader::Shader(const std::string filename)
	:id(0)
{
	ShaderContainer shader = ParseShader(filename);
	id = CreateShader(shader.vertexShaderSrc, shader.fragmentShaderSrc);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(id));
}

ShaderContainer Shader::ParseShader(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in) {
		std::cout << "Error reading file";
	}
	ASSERT(in);

	enum class type {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	type shader = type::NONE;
	std::stringstream ss[2];
	std::string line;
	
	while (std::getline(in, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				shader = type::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				shader = type::FRAGMENT;
			}
		}
		else
		{
			ss[(int)shader] << line << "\n";
		}
	}
	
	return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(const unsigned int type, const std::string& source)
{
	GLCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, NULL));
	GLCall(glCompileShader(id));

	int  success;
	char infoLog[512];
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &success));

	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else
		std::cout << "Successful shader" << std::endl;

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc)
{
	GLCall(unsigned int program = glCreateProgram());
	unsigned int vertexID = CompileShader(GL_VERTEX_SHADER, vertexSrc);
	unsigned int fragmentID = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
	GLCall(glAttachShader(program, vertexID));
	GLCall(glAttachShader(program, fragmentID));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));
	GLCall(glDeleteShader(vertexID));
	GLCall(glDeleteShader(fragmentID));

	return program;
}

const int Shader::GetUniformLoc(const std::string& name)
{
	GLCall(int loc =glGetUniformLocation(id, name.c_str()));
	if (loc == -1) { 
		std::cout << "Error uniform " << name << " not found!"; 
	}
	return loc;
}

void Shader::SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3)
{
	GLCall(glUniform4f(GetUniformLoc(name), v0, v1, v2, v3));
}

void Shader::SetUniform3f(const std::string & name, const float & v0, const float & v1, const float & v2)
{
	GLCall(glUniform3f(GetUniformLoc(name), v0, v1, v2));
}

void Shader::SetUniform4(const std::string & name, glm::vec4& val)
{
	GLCall(glUniform4fv(GetUniformLoc(name), 1, &val[0]));
}

void Shader::SetUniform3(const std::string & name, glm::vec3& val)
{
	GLCall(glUniform3fv(GetUniformLoc(name), 1, &val[0]));
}

void Shader::SetUniform1i(const std::string & name, int value)
{
	GLCall(glUniform1i(GetUniformLoc(name), value));
}

void Shader::SetUniformMat4f(const std::string & name, const glm::mat4 & matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLoc(name), 1, GL_FALSE, &matrix[0][0]));
}

void Shader::Bind() const
{
	GLCall(glUseProgram(id));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

