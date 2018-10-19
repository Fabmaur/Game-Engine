#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "GL/glew.h"
#include "GLDebug.h"
#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

struct ShaderContainer
{
	std::string vertexShaderSrc;
	std::string fragmentShaderSrc;
};


class Shader
{
public:
	Shader(const std::string filename);
	~Shader();
	void Bind() const;
	void Unbind() const;
	void SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3);
	void SetUniform3f(const std::string& name, const float& v0, const float& v1, const float& v2);
	void SetUniform4(const std::string& name, glm::vec4& val);
	void SetUniform3(const std::string& name, glm::vec3& val);
	void SetUniform1i(const std::string& name, int value);
	void SetUniformMat4f(const std::string& name, const glm::mat4& mat4);
private:
	unsigned int id;
private:
	ShaderContainer ParseShader(const std::string& filename);
	unsigned int CompileShader(const unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
	const int GetUniformLoc(const std::string& name);


};

