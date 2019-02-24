#pragma once
#include <iostream>
#include <map>
#include "maths/maths.h"

namespace graphics
{

	//Used as return type to ParseShader function
	struct ShaderContainer
	{
		std::string vertex;
		std::string fragment;
	};

	/*Shader class loads and parses shaders from other files so that opengl
	shaders can be created and compiled. The class also allows uniforms to be
	set for the current shader program. The class must be bound when the
	shader is to be used.*/

	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string& filename);
		~Shader();
		void Bind() const;
		void Unbind() const;
		void Delete();
		void SetUniform2f(const std::string& name, const float v0, const float v1);
		void SetUniform3f(const std::string& name, const float v0, const float v1, const float v2);
		void SetUniform4f(const std::string& name, const float v0, const float v1, const float v2, const float v3);
		void SetUniform4v(const std::string& name, maths::vec4f& val);
		void SetUniform3v(const std::string& name, maths::vec3f& val);
		void SetUniform1i(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniformMat4f(const std::string& name, const maths::mat4f& mat4);
	
	private:
		ShaderContainer ParseShader(const std::string& filename);
		unsigned int CompileShader(const unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		const int GetUniformLoc(const std::string& name);
	
	private:
		unsigned int id;
		static std::map<std::string, unsigned int> shaderMap;

	};
}