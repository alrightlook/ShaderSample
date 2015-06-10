//
//  Texture.h
//  GLSLTest
//
//  Created by Jerry on 15-6-9.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Texture__
#define __GLSLTest__Texture__

#include <iostream>
#include <SDL2/SDL_opengl.h>
#include <SDL2_image/SDL_image.h>
#include <string>

class Texture
{
public:
    Texture(GLenum textureTarget,GLenum textureUnit, const char* filename);
    void Bind(GLenum textureUnit);
    bool Load(GLuint programId, std::string varName, int value);
    ~Texture();
private:
    GLuint mTextureID;
    GLenum mTextureTarget;
};

#endif /* defined(__GLSLTest__Texture__) */
