#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "debug/GLDebug.h"
#include "maths/Matrix3.h"
#include "maths/Matrix4.h"
#include "graphics/renderer/Material.h"

namespace graphics{
	struct ShaderContainer
	{
		std::string vertexShaderSrc;
		std::string fragmentShaderSrc;
	};

	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string filename);
		~Shader();
		void Bind() const;
		void Unbind() const;
		void SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3);
		void SetUniform3f(const std::string& name, const float& v0, const float& v1, const float& v2);
		void SetUniform4v(const std::string& name, maths::vec4f& val);
		void SetUniform3v(const std::string& name, maths::vec3f& val);
		void SetUniform1i(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniformMat4f(const std::string& name, const maths::mat4f& mat4);
		void SetUniformMaterial(const std::string& name, const Material& mat);
	private:
		unsigned int id;
	private:
		ShaderContainer ParseShader(const std::string& filename);
		unsigned int CompileShader(const unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		const int GetUniformLoc(const std::string& name);


	};
}