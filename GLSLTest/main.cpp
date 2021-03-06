//
//  main.cpp
//  GLSLTest
//
//  Created by Jerry on 15-2-15.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include <iostream>
#include <glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Shader.h"
#include "Utils.h"
#include "Texture.h"
#include "VertexArray.h"

void render() {
    //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 1.0f, -1.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1.0f, 0.0f, -1.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0f, 0.0f, -1.0);
    glEnd();
}

int main(int argc, const char * argv[])
{
    int initResult = SDL_Init(SDL_INIT_EVERYTHING);
    if (initResult < 0) {
        std::cout<<"Init failed"<<std::endl;
    }
    else {
        std::cout<<"Init success"<<std::endl;
    }
    
    SDL_Window* window = SDL_CreateWindow("Hello World", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
    SDL_GLContext glctx = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glctx);
    glewInit();
    
    string trianglevert = Utils::getInstance()->readFiles("triangle.vert");
    string trianglefrag = Utils::getInstance()->readFiles("triangle.frag");
    
    Shader triangleshader;
    triangleshader.createShader(Shader::VERTEX_SHADER, trianglevert);
    triangleshader.createShader(Shader::FRAGMENT_SHADER, trianglefrag);
    string vertexShaderInfo = triangleshader.getShaderInfoLog(Shader::VERTEX_SHADER);
    string fragmentShaderInfo = triangleshader.getShaderInfoLog(Shader::FRAGMENT_SHADER);
    cout<<"The vertex shader compile info is:"<<vertexShaderInfo<<endl;
    cout<<"The fragment Shader compile info is:"<<fragmentShaderInfo<<endl;
    
    
    VertexArray* vao = new VertexArray(triangleshader.getProgramID());
    const GLfloat triangleData[4][3] = {
        {0.5f, 0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f},
        {-0.5f, -0.5f, 0.0f},
        {-0.5f, 0.5f, 0.0f},
    };
    
    const GLfloat triangleColor[4][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 1.0f, 0.0f}
    };
    
    const GLfloat texCoord[4][2] = {

        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f},
        {0.0f, 0.0f}
    };
    
    
    
    const GLuint indices[] = { 0,1,2,0,2,3}; //indices  must start with 0;
    
    vao->createIBO(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices, GL_STATIC_DRAW);
    
    vao->createVBO(GL_ARRAY_BUFFER, "triangle", 12 * sizeof(GLfloat), (void*) triangleData, GL_STATIC_DRAW);
    triangleshader.registerAttribute("VertexPosition", 3, GL_FLOAT, GL_FALSE, 0, 0, 0);
    
    vao->createVBO(GL_ARRAY_BUFFER, "trianglecolor", 12*sizeof(GLfloat), (void*) triangleColor, GL_STATIC_DRAW);
    triangleshader.registerAttribute("VertexColor", 3, GL_FLOAT, GL_FALSE, 0, 0, 1);
    
    vao->createVBO(GL_ARRAY_BUFFER, "texCoord", sizeof(GLfloat)*8, (void*) texCoord, GL_STATIC_DRAW);
    triangleshader.registerAttribute("TexCoord", 2, GL_FLOAT, GL_FALSE, 0, 0, 2);

    triangleshader.link();                  //link program should after registerAttirbute
    string linklog = triangleshader.getProgramInfoLog();
    cout<<"The linker log is:"<<linklog<<endl;
    triangleshader.use();
    
    Texture* tex = new Texture(GL_TEXTURE_2D,GL_TEXTURE0, "brick.png");
    tex->Load(triangleshader.getProgramID(), "texUnit", 0);

    if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
		printf("Ready for GLSL\n");
	else {
		printf("Not totally ready :( \n");
		exit(1);
	}
    
    if (glewIsSupported("GL_VERSION_2_0"))
		printf("Ready for OpenGL 2.0\n");
	else {
		printf("OpenGL 2.0 not supported\n");
		exit(1);
	}
    
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        else {
//            SDL_UpdateWindowSurface(window);
            //render();
            //vao->draw(GL_TRIANGLES, 0, 3);
            vao->drawElement(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            SDL_GL_SwapWindow(window);
        }

    }
    std::cout << "Hello, World!\n";
    SDL_Quit();
    return 0;
}

