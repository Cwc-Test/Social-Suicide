//
//  flatmission.hpp
//  Social Suicide
//
//  Created by Rick Sanchez on 07/06/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef flatmission_hpp
#define flatmission_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class flatmission{
private:

    int ident = 0;

    
public:
    bool affiche();
    int getId(){return ident;}
    int cx;
    const static string missions[];
    const static string reponses1[];
    const static string reponses2[];
    const static string reponses3[];
    const static string reponses4[];
    const static string reponses5[];
    bool initPlay(){
        ident = rand() % 5;
        return affiche();
    }
    
};
#endif /* flatmission_hpp */
