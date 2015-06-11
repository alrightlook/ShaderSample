//
//  Mesh.h
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Mesh__
#define __GLSLTest__Mesh__

#include <iostream>
#include <vector>
#include "Vertex.h"
#include <SDL2/SDL_opengl.h>
#include "VertexArray.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();
    bool init(std::vector<Vertex>& verts, std::vector<int>& indices);
    GLuint mVBO;
    GLuint mIBO;
    int mNumIndices;
private:
    GLuint mMaterialID;
    GLuint mTextureID;
    VertexArray mVao;
};

#endif /* defined(__GLSLTest__Mesh__) */
