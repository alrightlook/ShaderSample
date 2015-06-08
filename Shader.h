//
//  Shader.h
//  GLSLTest
//
//  Created by Jerry on 15-5-4.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Shader__
#define __GLSLTest__Shader__

#include <iostream>
#include <string>
#include <SDL2/SDL_opengl.h>
#include <map>

using namespace std;

class Shader {
public:
    enum ShaderType {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };
private:
    GLuint mVertexShaderID;
    GLuint mFragmentShaderID;
    GLuint mProgramID;
    map<string, GLint> mMapUniformVariables;
    map<string, GLint> mMapAttributeVariables;
public:
    Shader();
    void link();
    void use();
    string getShaderInfoLog(ShaderType type);
    string getProgramInfoLog();
    GLuint getProgramID();
    void createShader(ShaderType type, string code);
    
    void registerUniform(string name);
    GLint getUniform(string name);
    void setUniform1f(string name, GLfloat f0);
    void setUniform2f(string name, GLfloat f0, GLfloat f1);
    void setUniform3f(string name, GLfloat f0, GLfloat f1, GLfloat f2);
    void setUniform4f(string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3);
    
    void setUniform1fv(string name, GLsizei count, GLfloat* v);
    void setUniform2fv(string name, GLsizei count, GLfloat* v);
    void setUniform3fv(string name, GLsizei count, GLfloat* v);
    void setUniform4fv(string name, GLsizei count, GLfloat* v);
    
    void registerAttribute(string name,GLint size, GLenum type, GLboolean normalized,GLsizei stride, const void* offset, GLuint index);
    GLint getAttribute(string name);
    
    void setAttribute1f(string name, GLfloat f0);
    void setAttribute2f(string name, GLfloat f0, GLfloat f1);
    void setAttribute3f(string name, GLfloat f0, GLfloat f1, GLfloat f2);
    void setAttribute4f(string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3);
    
    void setAttribute1fv(string name, GLfloat* v);
    void setAttribute2fv(string name, GLfloat* v);
    void setAttribute3fv(string name, GLfloat* v);
    void setAttribute4fv(string name, GLfloat* v);
    
    ~Shader();
    
    
};

#endif /* defined(__GLSLTest__Shader__) */
