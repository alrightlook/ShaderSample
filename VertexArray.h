//
//  VertexArray.h
//  GLSLTest
//
//  Created by Jerry on 15-5-11.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__VertexArray__
#define __GLSLTest__VertexArray__
#define GL_GLEXT_PROTOTYPES 1
#include <iostream>
#include <string>
#include <SDL2/SDL_opengl.h>
#include <map>


using namespace std;


class VertexArray
{
private:
    GLuint mVao;
    map<string, GLuint> mMapVbo;
    GLuint mProgramID;
    GLuint mIbo;
public:
    VertexArray(GLuint programID);
    VertexArray();
    GLuint getVBO(string name);
    GLuint getIBO();
    void createVBO(GLenum target, string name, long size, void* data, GLenum usage);
    void createIBO(GLenum target,
                   GLsizeiptr size,
                   const GLvoid * data,
                   GLenum usage);
    void draw(GLenum mode, int first, int count);
    void drawElement(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
    ~VertexArray();
};
#endif /* defined(__GLSLTest__VertexArray__) */
