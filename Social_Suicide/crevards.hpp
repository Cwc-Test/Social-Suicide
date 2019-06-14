//
//  crevards.hpp
//  Social Suicide
//
//  Created by Rick Sanchez on 02/06/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef crevards_hpp
#define crevards_hpp
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
class crevard{
private:
    
    map<int, map<int, int> > matrix1;//lieu,choix : percent
    map<int, map<int, int> > matrix2;//lieu,choix : type
    int abordChance(int lieu, int choix);
    int abordType(int lieu, int choix);
    
public:
    
    
    crevard(){
        //%
        matrix1[2][0] = 5;
        matrix1[2][1] = 15;
        matrix1[2][2] = 0;
        matrix1[2][3] = 4;
        matrix1[2][4] = 20;

        matrix2[2][0] = 1;
        matrix2[2][1] = 2;
        matrix2[2][2] = 0;
        matrix2[2][3] = 1;
        matrix2[2][4] = 1;

        matrix1[1][1] = 1;
        matrix1[1][2] = 5;
        matrix1[1][3] = 6;
        matrix1[1][4] = 1;
        matrix1[1][5] = 9;
        
        matrix2[1][1] = 1;
        matrix2[1][2] = 1;
        matrix2[1][3] = 1;
        matrix2[1][4] = 1;
        matrix2[1][5] = 1;
    }
    
    int abordage(int lieu, int choix, float money);

};


class foyerclodo{
private:
    int placesmax = 100;
    int occuped = 0;
    
public:
    void initplaces(){occuped=0;}
    void nextplacebyclodo(){
        occuped += rand()%13;
    }
    bool isgood(int heure){
        if ((-7 > heure)&&(heure > -11)){
            cout << "Le centre est ouvert... vous entrez..." << endl;
            bool malchance = (rand()%100)<1;
            if (!malchance){
                cout << "Vous attendez a l'acceuil..." << endl;
                if (occuped<placesmax){
                    cout << "Vous avez trouver une place, vous êtes au chaud !" << endl;
                    return true;
                }
            }
            else{
                cout << "Il y a trops de monde, vous ne trouverez pas de place, il vaut mieux partir..." << endl;
            }
        }
        else{
            cout << "Le centre est fermer, revenez plus tard." << endl;
        }
        return false;
    }
    
};

#endif /* crevards_hpp */
