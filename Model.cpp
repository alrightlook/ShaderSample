//
//  Model.cpp
//  GLSLTest
//
//  Created by Jerry on 15-6-10.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Model.h"
#include <assimp/vector3.h>


Model::Model() {
    
}

Model::~Model() {
    
}

void Model::InitMesh(unsigned int Index, const aiMesh* paiMesh) {
    std::vector<Vertex> verteices;
    std::vector<int> indices;
    
    const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);
    
    for (unsigned int i = 0; i < paiMesh->mNumVertices; i++) {
        const aiVector3D* pPos = &(paiMesh->mVertices[i]);
        const aiVector3D* pNormal = paiMesh->HasNormals()? &(paiMesh->mNormals[i]): &Zero3D;
        const aiVector3D* pTexture = paiMesh->HasTextureCoords(0)? &(paiMesh->mTextureCoords[0][i]) :&Zero3D;
        
        Vertex v(vec3f(pPos->x, pPos->y, pPos->z), vec2f(pTexture->x,pTexture->y), vec3f(pNormal->x, pNormal->y, pNormal->z));
        
        verteices.push_back(v);
    }
    
    for (unsigned int i = 0; i < paiMesh->mNumFaces; i++) {
        const aiFace& Face = paiMesh->mFaces[i];
        assert(Face.mNumIndices == 3);
        indices.push_back(Face.mIndices[0]);
        indices.push_back(Face.mIndices[1]);
        indices.push_back(Face.mIndices[2]);
    }
    Mesh m;
    m.init(verteices, indices);
    mMeshes.push_back(m);
}

bool Model::initScene(const aiScene* pScene, const std::string& Filename) {
    for (unsigned int i = 0; i < pScene->mNumMeshes;  i++) {
        const aiMesh* paiMesh = pScene->mMeshes[i];
        InitMesh(i, paiMesh);
    }
    return true;
}

void Model::Render() {
    for (unsigned int i = 0;  i < mMeshes.size(); i++) {
        glBindBuffer(GL_ARRAY_BUFFER, mMeshes[i].mVBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mMeshes[i].mIBO);
        glDrawElements(GL_TRIANGLES, mMeshes[i].mNumIndices, GL_UNSIGNED_INT, 0);
    }
}

void Model::LoadModel(std::string filename) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filename, aiProcess_CalcTangentSpace       |
                                aiProcess_Triangulate            |
                                aiProcess_JoinIdenticalVertices  |
                                aiProcess_SortByPType);
    if (!scene) {
        std::cout<<"Cannot import scene:"<<importer.GetErrorString()<<std::endl;
        return;
    }
    else {
        std::cout<<"The model import successfully:"<<filename<<std::endl;
    }
    
    initScene(scene, filename);
}