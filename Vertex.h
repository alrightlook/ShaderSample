//
//  Vertex.h
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Vertex__
#define __GLSLTest__Vertex__

#include <iostream>
typedef struct vec3f
{
    vec3f() {
        x = y= z = 0.0f;
    }
    vec3f(float mx, float my, float mz){
        x= mx;
        y = my;
        z = mz;
    };
    float x;
    float y;
    float z;
} vec3f;

typedef struct vec2f
{
    vec2f() {
        u = v = 0.0f;
    }
    vec2f(float mu, float mv) {
        u = mu;
        v = mv;
    };
    float u;
    float v;
}vec2f;

class Vertex
{
public:
    Vertex();
    Vertex(vec3f pos, vec2f texcoord, vec3f normal);
    ~Vertex();
private:
    vec3f mPosition;
    vec2f mTexture;
    vec3f mNormal;
};

#endif /* defined(__GLSLTest__Vertex__) */
