//
//  Mesh.cpp
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Mesh.h"

Mesh::Mesh(){
    
}

Mesh::~Mesh() {
    
}

bool Mesh::init(std::vector<Vertex> &verts, std::vector<int> &indices) {
    mVao.createIBO(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), &indices[0], GL_STATIC_DRAW);
    mVao.createVBO(GL_ARRAY_BUFFER, "vbo", verts.size() * sizeof(Vertex), &verts[0], GL_STATIC_DRAW);
    mVBO = mVao.getVBO("vbo");
    mIBO = mVao.getIBO();
    
    mNumIndices = indices.size();
    return true;
}