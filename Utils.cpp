//
//  Utils.cpp
//  GLSLTest
//
//  Created by Jerry on 15-5-12.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#include "Utils.h"

Utils* Utils::mInstance = nullptr;

Utils* Utils::getInstance() {
    if (mInstance == nullptr) {
        mInstance = new Utils();
    }
    return mInstance;
}


Utils::Utils() {
    
}

Utils::~Utils() {
    if (mInstance != nullptr) {
        delete mInstance;
        mInstance = nullptr;
    }
}

string Utils::readFiles(const char* filename) {
    ifstream qFile(filename);
    string filecontent;
    while (qFile.peek() != EOF) {
        string qLine;
        getline(qFile, qLine);
        filecontent += qLine;
        filecontent += "\n";
    }
    qFile.close();
    return filecontent;
    
}

