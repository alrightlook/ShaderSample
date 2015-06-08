//
//  Shader.cpp
//  GLSLTest
//
//  Created by Jerry on 15-5-4.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Shader.h"

Shader::Shader() {
    mProgramID = glCreateProgram();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GLuint Shader::getProgramID() {
    return mProgramID;
}

void Shader::createShader(Shader::ShaderType type, string code) {
    GLenum shaderType;
    char* codestr = (char *)malloc(sizeof(char) * (code.size() + 1));
    memcpy(codestr, code.c_str(), code.size() + 1);
    if (type == VERTEX_SHADER) {
        shaderType = GL_VERTEX_SHADER;
        mVertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(mVertexShaderID, 1, (const GLchar**)&codestr, 0);
        glCompileShader(mVertexShaderID);
        glAttachShader(mProgramID, mVertexShaderID);
        
    }
    else {
        mFragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        shaderType = GL_FRAGMENT_SHADER;
        glShaderSource(mFragmentShaderID, 1, (const GLchar**)&codestr, 0);
        glCompileShader(mFragmentShaderID);
        glAttachShader(mProgramID, mFragmentShaderID);
    }
}

string Shader::getShaderInfoLog(Shader::ShaderType type) {
    string infoLogRes;
    GLuint shaderId = mFragmentShaderID;
    if (type == ShaderType::VERTEX_SHADER) {
        shaderId = mVertexShaderID;
    }
    
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
    
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH,&infologLength);
    
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetShaderInfoLog(shaderId, infologLength, &charsWritten, infoLog);
        //printf("%s\n",infoLog);
        infoLogRes = infoLog;
        free(infoLog);
    }
    
    return infoLogRes;
}

void Shader::setUniform1f(string name, GLfloat f0) {
    glUniform1f(getUniform(name), f0);
}

void Shader::setUniform2f( string name, GLfloat f0, GLfloat f1) {
    glUniform2f(getUniform(name), f0, f1);
}

void Shader::setUniform3f(string name, GLfloat f0, GLfloat f1, GLfloat f2) {
    glUniform3f(getUniform(name), f0, f1, f2);
}

void Shader::setUniform4f(string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3) {
    glUniform4f(getUniform(name), f0, f1, f2, f3);
}

void Shader::setUniform1fv(string name, GLsizei count, GLfloat *v) {
    glUniform1fv(getUniform(name),count, v);
}

void Shader::setUniform2fv(string name, GLsizei count, GLfloat *v) {
    glUniform2fv(getUniform(name), count, v);
}

void Shader::setUniform3fv(string name, GLsizei count, GLfloat *v) {
    glUniform3fv(getUniform(name), count, v);
}

void Shader::setUniform4fv(string name, GLsizei count, GLfloat *v) {
    glUniform4fv(getUniform(name), count, v);
}

void Shader::registerAttribute(string name,GLint size, GLenum type, GLboolean normalized,GLsizei stride, const void* offset, GLuint index) {
    if (mMapAttributeVariables.find(name) == mMapAttributeVariables.end()) {
        glBindAttribLocation(mProgramID, index, name.c_str());
        glVertexAttribPointer(index, size, type, normalized, stride, offset);
        glEnableVertexAttribArray(index);
        mMapAttributeVariables.insert(make_pair(name, index));
    }
}

GLint Shader::getAttribute(string name) {
    if (mMapAttributeVariables.find(name) != mMapAttributeVariables.end()) {
        return mMapAttributeVariables.find(name)->second;
    }
    return 0;
}

void Shader::registerUniform(string name) {
    if (mMapUniformVariables.find(name) == mMapUniformVariables.end()) {
        GLint ul = glGetUniformLocation(mProgramID, name.c_str());
        mMapUniformVariables.insert(make_pair(name, ul));
    }
}

GLint Shader::getUniform(string name) {
    if (mMapUniformVariables.find(name) !=mMapUniformVariables.end()) {
        return mMapUniformVariables.find(name)->second;
    }
    return 0;
}

void Shader::setAttribute1f(string name, GLfloat f0) {
    glVertexAttrib1f(getAttribute(name), f0);
}

void Shader::setAttribute2f(string name, GLfloat f0, GLfloat f1) {
    glVertexAttrib2f(getAttribute(name), f0, f1);
}

void Shader::setAttribute3f(string name, GLfloat f0, GLfloat f1, GLfloat f2) {
    glVertexAttrib3f(getAttribute(name), f0, f1, f2);
}

void Shader::setAttribute4f(string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3) {
    glVertexAttrib4f(getAttribute(name), f0, f1, f2, f3);
}

void Shader::setAttribute1fv(string name, GLfloat *v) {
    glVertexAttrib1fv(getAttribute(name), v);
}

void Shader::setAttribute2fv(string name, GLfloat *v) {
    glVertexAttrib2fv(getAttribute(name), v);
}

void Shader::setAttribute3fv(string name, GLfloat *v) {
    glVertexAttrib3fv(getAttribute(name), v);
}

void Shader::setAttribute4fv(string name, GLfloat *v) {
    glVertexAttrib4fv(getAttribute(name), v);
}

string Shader::getProgramInfoLog() {
    string infoLogRes;
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
    
    glGetProgramiv(mProgramID, GL_INFO_LOG_LENGTH,&infologLength);
    
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetProgramInfoLog(mProgramID, infologLength, &charsWritten, infoLog);
        //printf("%s\n",infoLog);
        infoLogRes = infoLog;
        free(infoLog);
    }
    return infoLogRes;
}

void Shader::link() {
    glLinkProgram(mProgramID);
}

void Shader::use() {
    glUseProgram(mProgramID);
}

Shader::~Shader() {
    glUseProgram(0);
    map<string, GLint>::iterator i;
    for (i = mMapAttributeVariables.begin(); i != mMapAttributeVariables.end(); i++) {
        glDisableVertexAttribArray(i->second);
    }
    glDetachShader(mProgramID, mFragmentShaderID);
    glDetachShader(mProgramID, mVertexShaderID);
    
    glDeleteShader(mFragmentShaderID);
    glDeleteShader(mVertexShaderID);
    
    glDeleteProgram(mProgramID);
    
}