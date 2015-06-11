//
//  VertexArray.cpp
//  GLSLTest
//
//  Created by Jerry on 15-5-11.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "VertexArray.h"
VertexArray::VertexArray() {
    glGenVertexArrays(1, &mVao);
    glBindVertexArray(mVao);
}

VertexArray::VertexArray(GLuint programID) {
    mProgramID = programID;
    glGenVertexArrays(1, &mVao);
    glBindVertexArray(mVao);
}
GLuint VertexArray::getIBO() {
    return mIbo;
}

void VertexArray::createIBO(GLenum target,
                            GLsizeiptr size,
                            const GLvoid * data,
                            GLenum usage)
{
    glGenBuffers(1, &mIbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
    glBufferData(target, size, data, usage);
}

GLuint VertexArray::getVBO(string name) {
    return mMapVbo.find(name)->second;
}

void VertexArray::drawElement(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
    glDrawElements(mode, count, type, indices);
}

VertexArray::~VertexArray() {
    
}

void VertexArray::createVBO(GLenum target, string name, long size, void *data, GLenum usage) {
    if (mMapVbo.find(name) != mMapVbo.end()) {
        return;
    }
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(target, size, data, usage);
    mMapVbo.insert(make_pair(name, vbo));
}

void VertexArray::draw(GLenum mode, int first, int count) {
    glDrawArrays(mode, first, count);
}