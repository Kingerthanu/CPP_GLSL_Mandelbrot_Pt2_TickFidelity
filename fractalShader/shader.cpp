#include "shader.h"


std::string get_file_contents(const char* fileName)
{

	std::ifstream in(fileName, std::ios::binary);

	if (in) {

		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();

		return (contents);

	}
	throw(errno);

};

Shader::Shader(const char* vertFile, const char* fragFile)
{

	std::string vertexCode = get_file_contents(vertFile);
	std::string fragmentCode = get_file_contents(fragFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();


	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	this->ID = glCreateProgram();

	glAttachShader(this->ID, vertexShader);
	glAttachShader(this->ID, fragmentShader);
	glLinkProgram(this->ID);


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

};

void Shader::Activate()
{

	glUseProgram(this->ID);

}

void Shader::Delete()
{

	glDeleteProgram(this->ID);

}
