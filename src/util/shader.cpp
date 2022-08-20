#include "shader.h"

shader::shader(std::string vertex_path, std::string fragment_path) {
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream vshader_file;
    std::ifstream fshader_file;
    // ensure ifstream objects can throw exceptions:
    vshader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fshader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open files
		std::cout << "pass" << std::endl;
        vshader_file.open(vertex_path);
        fshader_file.open(fragment_path);
        std::stringstream vshader_stream, fshader_stream;
        // read file's buffer contents into streams
        vshader_stream << vshader_file.rdbuf();
        fshader_stream << fshader_file.rdbuf();
        // close file handlers
        vshader_file.close();
        fshader_file.close();
        // convert stream into string
        vertex_code = vshader_stream.str();
        fragment_code = fshader_stream.str();
    } catch (std::ifstream::failure e) {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vshader_code = vertex_code.c_str();
    const char* fshader_code = fragment_code.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vshader_code, NULL);
    glCompileShader(vertex);
    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // similiar for Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fshader_code, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // shader Program
    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);
    glLinkProgram(this->ID);
    // print linking errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void shader::use() {
	glUseProgram(this->ID);
}

void shader::terminate() {
	glDeleteProgram(this->ID);
}