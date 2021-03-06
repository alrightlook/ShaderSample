//
//  Texture.cpp
//  GLSLTest
//
//  Created by Jerry on 15-6-9.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Texture.h"

Texture::Texture(GLenum textureTarget,GLenum textureUnit, const char* filename) {
    mTextureTarget = textureTarget;
    glGenTextures(1, &mTextureID);
    glActiveTexture(textureUnit);
    glBindTexture(textureTarget, mTextureID);
    
    SDL_Surface* texSurface = IMG_Load(filename);
    
    if (texSurface == nullptr) {
        std::cout<<"Texture Image does not load sucessfully"<<std::endl;
        return;
    }
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    
    int Mode = GL_RGB;
    
    //access violation on mysurface (until I added NULL test)
    if(texSurface->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, texSurface->w, texSurface->h, 0, Mode, GL_UNSIGNED_BYTE, texSurface->pixels);
    
    std::cout<<"The tex id is:"<<mTextureID<<std::endl;
    SDL_FreeSurface(texSurface);
}

void Texture::Bind(GLenum textureUnit) {
    glActiveTexture(textureUnit);
    glBindTexture(mTextureTarget, mTextureID);
}

bool Texture::Load(GLuint programId, std::string varName, int value) {
    glUseProgram(programId);
    glUniform1i(glGetUniformLocation(programId, varName.c_str()), value);
    
    return true;
}