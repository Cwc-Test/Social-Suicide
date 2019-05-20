//
//  need.cpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#include "need.hpp"

map<int,float> need::getNeeds(){
    map<int, float> besoins;
    besoins[1] = need_app;
    besoins[2] = need_hyg;
    besoins[3] = need_vess;
    besoins[4] = need_fun;
    besoins[5] = need_sleep;
    besoins[6] = need_soc;
    return besoins;
}

void need::manger(float val){
    need_app+=val;
    if (need_app>1.0){
        need_app = 1.00;
    }
}
void need::laver(float val){
    need_hyg+=val;
    if (need_hyg>1.0){
        need_hyg = 1.00;
    }
}
void need::pisser(float val){
    need_vess+=val;
    if (need_vess>1.0){
        need_vess = 1.00;
    }
}
void need::jouer(float val){
    need_fun+=val;
    if (need_fun>1.0){
        need_fun = 1.00;
    }
}
void need::dormir(float val){
    need_sleep+=val;
    if (need_sleep>1.0){
        need_sleep = 1.00;
    }
}
void need::parler(float val){
    need_soc+=val;
    if (need_soc>1.0){
        need_soc = 1.00;
    }
}
void need::degradApp(float fact){
    need_app=need_app - fact;
    if (need_app<0.0){
        need_app = 0.00;
    }
}
void need::degradHyg(float fact){
    need_hyg=need_hyg-fact;
    if (need_hyg<0.0){
        need_hyg = 0.00;
    }
}
void need::degradVess(float fact){
    need_vess=need_vess-fact;
    if (need_vess<0.0){
        need_vess = 0.00;
    }
}
void need::degradFun(float fact){
    need_fun=need_fun-fact;
    if (need_fun<0.0){
        need_fun = 0.00;
    }
}
void need::degradSleep(float fact){
    need_sleep=need_sleep-fact;
    if (need_sleep<0.0){
        need_sleep = 0.00;
    }
}
void need::degradSoc(float fact){
    need_soc=need_soc-fact;
    if (need_soc<0.0){
        need_soc = 0.00;
    }
}


bool need::PoopInEyes(){
    float chance = (rand() % 100) < 80;
    if (need_hyg>.15){
        if (chance){
            return false;
        }
        return true;
    }
    return true;
}


void need::affichage(){
    //need_app, need_hyg, need_vess, need_fun, need_sleep, need_soc
    
    //need_app
    cout << "Appetit\t\t[";
    for (float i=0; i<10; i++){
        if (need_app*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_app*100 <<"%)\n";
    //need_hyg
    cout << "Hygiene\t\t[";
    for (float i=0; i<10; i++){
        if (need_hyg*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_hyg*100 <<"%)\n";
    //need_vess
    cout << "Vessie\t\t[";
    for (float i=0; i<10; i++){
        if (need_vess*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_vess*100 <<"%)\n";
    //need_fun
    cout << "Fun\t\t[";
    for (float i=0; i<10; i++){
        if (need_fun*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_fun*100 <<"%)\n";
    //need_sleep
    cout << "Sommeil\t\t[";
    for (float i=0; i<10; i++){
        if (need_sleep*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_sleep*100 <<"%)\n";
    //need_soc
    cout << "Social\t\t[";
    for (float i=0; i<10; i++){
        if (need_soc*10>=i){
            cout << "#";
        }
        else{
            cout << "-";
        }
    }
    cout << "]("<< need_soc*100 <<"%)\n";
}

void need::HygZero(){
    need_hyg = 0;
}
