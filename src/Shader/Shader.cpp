/* 
 * File:   Shader.cpp
 * Author: francisco
 * 
 * Created on 12 de diciembre de 2013, 19:29
 */

#include <Core/Core.h>
#include <Scene/Scene.h>
#include <Scene/Camera/Camera.h>
#include <Scene/Material.h>
#include <Shader/Shader.h>
#include <Log/Logger.h>
#include <Renderer/Model2D.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace kaikai;

std::string textFileRead(const GLchar *fileName) {
	std::string fileString = std::string(); 
	std::string line = std::string(); 

	std::ifstream file(fileName);
	if (file.is_open()) 
        { 
                while (!file.eof()) 
                { 
                        getline(file, line);
		  	fileString.append(line);
			fileString.append("\n");
		}
		file.close();
	}
        else
        {
            std::string error_code = fileName;
            error_code.append(" wasn't found.\n");
            (Core::getInstance())->getLogger()->criticalLog(error_code.c_str());
        }
        return fileString;
}

void validateShader(GLuint shader, const GLchar* file = 0) {
    GLuint BUFFER_SIZE = 512;
    GLchar buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;
    
    glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer); 
    if (length > 0) 
        std::cout << "Shader " << shader << " (" << (file?file:"") << ") compile error: " << buffer << std::endl; 
}

void validateProgram(GLuint program, const GLchar* _name) {
    GLuint BUFFER_SIZE = 512;
    GLchar buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;
    
    glGetProgramInfoLog(program, BUFFER_SIZE, &length, buffer); 
    if (length > 0) 
        std::cout << "Program " << _name << " link error: " << buffer << std::endl; 
    
    glValidateProgram(program); 
    GLint status;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status); 
    if (status == GL_FALSE)
		std::cout << "Error validating shader " << _name << std::endl; 
}

Shader::Shader(const GLchar* _name, const char *vertex_filename, const char *fragment_filename) {
    
    name = std::string(_name);
    vertex_shader_id = glCreateShader(GL_VERTEX_SHADER); 
    fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER); 
    
    std::string vsText = textFileRead(vertex_filename); 
    std::string fsText = textFileRead(fragment_filename); 
    
	const GLchar *vertexText = vsText.c_str();
	const GLchar *fragmentText = fsText.c_str();

    if (vertexText == NULL || fragmentText == NULL) { 
        std::cout << "Either vertex shader or fragment shader file not found." << std::endl; 
        return;
    }
    
    glShaderSource(vertex_shader_id, 1, &vertexText, 0);
    glCompileShader(vertex_shader_id); 
    validateShader(vertex_shader_id, vertex_filename); 
    
    glShaderSource(fragment_shader_id, 1, &fragmentText, 0);
    glCompileShader(fragment_shader_id); 
    validateShader(fragment_shader_id, fragment_filename); 
    
    program_shader_id = glCreateProgram(); 
    
    glAttachShader(program_shader_id, vertex_shader_id); 
    glAttachShader(program_shader_id, fragment_shader_id); 

    glLinkProgram(program_shader_id); 
    validateProgram(program_shader_id, name.c_str());    
}

Shader::Shader(const GLchar* _name, const GLchar ** shader_vector) {
    name = std::string(_name);
    GLint vartex_status, fragment_status;
    
    vertex_shader_id = glCreateShader(GL_VERTEX_SHADER); 
    fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER); 
    
    const GLchar *vertexText = shader_vector[0];
    const GLchar *fragmentText = shader_vector[1];

    glShaderSource(vertex_shader_id, 1, &vertexText, 0);
    glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &vartex_status);
    /*if(vartex_status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(vertex_shader_id, infoLogLength, NULL, strInfoLog);
        std::cout << "Compilation error in shader " <<  strInfoLog << "\n";
        delete[] strInfoLog;
    }*/
    glCompileShader(vertex_shader_id);
    
    glShaderSource(fragment_shader_id, 1, &fragmentText, 0);
    glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &fragment_status);
    /*if(fragment_status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(fragment_shader_id, infoLogLength, NULL, strInfoLog);
        std::cout << "Compilation error in shader " <<  strInfoLog << "\n";
        delete[] strInfoLog;
    }*/
    glCompileShader(fragment_shader_id);
    
    program_shader_id = glCreateProgram(); 
    
    glAttachShader(program_shader_id, vertex_shader_id); 
    glAttachShader(program_shader_id, fragment_shader_id); 

    glLinkProgram(program_shader_id); 
    validateProgram(program_shader_id, name.c_str());     
}

Shader::~Shader() {
}

GLint Shader::getAttributeLocation(GLuint program, const GLchar* attribute_name)
{
    GLint resu = glGetAttribLocation(program, attribute_name);
    std::string message = attribute_name;
    message.append(" isn't in Attribute, Program Shader\n");
    if(resu == -1)
        (Core::getInstance())->getLogger()->warnningLog(message.c_str());
    return resu;
}

GLint Shader::getUniformLocation(GLuint program, const GLchar* uniform_name)
{
    GLint resu = glGetUniformLocation(program, uniform_name);
    std::string message = uniform_name;
    message.append(" isn't in Uniform, Program Shader");
    if(resu == -1)
        (Core::getInstance())->getLogger()->warnningLog(message.c_str());
    return resu;
}

void Shader::enableShaderVariables()
{
    
}

void Shader::setShaderVariables(Renderable* _renderable, Material* _material, Scene* _scene) {
    glUseProgramObjectARB(program_shader_id);
    glUniformMatrix4fv(uniform_scale_matrix,1,GL_FALSE,_renderable->getScale());
    glUniformMatrix4fv(uniform_position_matrix,1,GL_FALSE,_renderable->getPosition());
    glUniformMatrix4fv(proM,1,GL_FALSE,_renderable->getProjectionMatrix());
    glUniformMatrix4fv(viewP,1,GL_FALSE,_scene->getCamera()->getMatrixView());
    glEnableVertexAttribArray(attribute_vertex);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getVertexBufferID());
    glVertexAttribPointer(attribute_vertex, 3, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,_renderable->getUVBufferID());
    glEnableVertexAttribArray(attribute_coordinate_vertex);
    glVertexAttribPointer(attribute_coordinate_vertex, 2, GL_FLOAT,GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void Shader::disableShaderVariables()
{
    glDisableVertexAttribArray(attribute_vertex);
    glUseProgramObjectARB(0);
}