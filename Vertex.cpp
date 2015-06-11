//
//  Vertex.cpp
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(){
    
}

Vertex::~Vertex() {
    
}

Vertex::Vertex(vec3f pos, vec2f texcoord, vec3f normal) {
    mPosition.x = pos.x;
    mPosition.y = pos.y;
    mPosition.z = pos.z;
    
    mTexture.u = texcoord.u;
    mTexture.v = texcoord.v;
    
    mNormal.x = normal.x;
    mNormal.y = normal.y;
    mNormal.z = normal.z;
    
}