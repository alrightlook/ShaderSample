//
//  Model.h
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Model__
#define __GLSLTest__Model__

#include <iostream>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include "Vertex.h"
#include "Mesh.h"

class Model
{
public:
    Model();
    ~Model();
    void LoadModel(std::string filename);
    void Render();
private:
    bool initScene(const aiScene* pScene, const std::string& Filename);
    void InitMesh(unsigned int Index, const aiMesh* paiMesh);
    bool InitMaterials(const aiScene* pScene, const std::string& Filename);
    
    std::vector<Mesh> mMeshes;
    
};
#endif /* defined(__GLSLTest__Model__) */
