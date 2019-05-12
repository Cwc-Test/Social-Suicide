//
//  need.hpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef need_hpp
#define need_hpp
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class need{
private:
    float need_app = 0.35;
    float need_hyg = 0.75;
    float need_vess = 0.75;
    float need_fun = 0.50;
    float need_sleep = 0.69;
    float need_soc = 0.50;
    
public:
    void affichage();
    void manger(float val);
    void laver(float val);
    void pisser(float val);
    void jouer(float val);
    void dormir(float val);
    void parler(float val);
    void degradApp(float fact);
    void degradHyg(float fact);
    void degradVess(float fact);
    void degradFun(float fact);
    void degradSleep(float fact);
    void degradSoc(float fact);
    map<int,float> getNeeds();
    bool PoopInEyes();
    void HygZero();
};

#endif /* need_hpp */
