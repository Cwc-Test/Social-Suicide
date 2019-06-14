//
//  crevards.cpp
//  Social Suicide
//
//  Created by Rick Sanchez on 02/06/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#include "crevards.hpp"

int crevard::abordage(int lieu, int choix,float money){
    int chance = 0;
    int reqm = 0;
    if (abordChance(lieu, choix)!=-1){
        chance = (rand()%100) < abordChance(lieu, choix);
    }
    if (chance){
        reqm = rand()%100;
        if (abordType(lieu, choix)==1){
            cout << "Crevard: Hé mec ta pas quelques euros ? Allez vas y man c'est la galere !" <<endl;
            if (money>0){
                cout << "Il insiste et vous lui donnez un peu d'argent..." <<endl;
            }
            else{
                cout << "Crevard: Ha ta rien, pas grave mec merci quand meme."<<endl;
            }
        }
        else{
            reqm = -1;
            cout << "Crevard: Excuse moi, tu pourrait me payer un verre ?"<<endl;
            if (money>0){
                cout << "Vous lui payez un verre..." << endl;
            }
            else{
                cout << "Crevard: Ha ta rien, pas grave mec merci quand meme."<<endl;
            }
        }
    }
    return reqm;
}

int crevard::abordChance(int lieu, int choix){
    try{
        return matrix1[lieu][choix];
    }
    catch(int e){
        return -1;
    }
    return -1;
}
int crevard::abordType(int lieu, int choix){
    try{
        return matrix2[lieu][choix];
    }
    catch(int e){
        return -1;
    }
    return -1;
}
