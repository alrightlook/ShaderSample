//
//  Utils.h
//  GLSLTest
//
//  Created by Jerry on 15-5-12.
//  Copyright (c) 2015年 com.jerry. All rights reserved.
//

#ifndef __GLSLTest__Utils__
#define __GLSLTest__Utils__

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Utils
{
public:
    ~Utils();
    static Utils* getInstance();
    string readFiles(const char* filename);
private:
    Utils();
    static Utils* mInstance;
};

#endif /* defined(__GLSLTest__Utils__) */
