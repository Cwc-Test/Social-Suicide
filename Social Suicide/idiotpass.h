//
//  idiotpass.h
//  Social Suicide
//
//  Created by Rick Sanchez on 23/05/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef idiotpass_h
#define idiotpass_h
#include <math.h>

using namespace std;

class idiotbarmachine{
private:
    float enigme1(float x0, float x1){
        return trunc(floor(cos(0.114)+x1 - x0));
    }
    bool test(float y){
        return y == (tabX[longueur+1]);
    }
    map<int, float> tabX, tabY;
    int longueur;
    void affiche(){
        for (int i = 0; i<longueur; i++){
            cout << tabX[i] << "----->";
        }
        cout <<"???"<< endl;
        for (int i = 0; i<longueur; i++){
            if (i>0){
                cout << "|\t";
            }
            else{
                cout << "\t";
            }
        }
        cout << endl;
        for (int i = 0; i<longueur; i++){
            if (i>0){
                cout << tabY[i] << "\t";
            }
            else{
                cout << "\t";
            }
        }
        //triche//cout << tabX[longueur+1] << " >>";
    }
    
public:
    idiotbarmachine(int taille){
        tabY[0] = -999;
        longueur = taille;
    }
    void generate(){
        tabX[0] = (rand()%100)+1;
        int ny = 1;
        for (int i=0; i<longueur+1; i++){
            tabY[ny] = tabX[i]+(rand()%100)+1;
            tabX[ny] = enigme1(tabX[ny-1],tabY[ny]);
            //cout << "G:: "<<" :: "<<tabX[ny]<<endl;
            ny++;
        }
        tabX[ny] -= 1;
    }
    bool playLoop(){
        float repon;
        bool zstate = true;
        bool winstate = false;
        int ness = 3;
        generate();
        while(zstate){
            cout << "Vous jouer a idiotpass dans un bar." << endl<<"Voici la question: "<< endl;
            
            affiche();
            cout << "Votre reponse: ";
            cin >> repon;
            winstate = test(repon);
            if (winstate){
                cout << "Vous avez gagner !" << endl;
                //WINNER CODE
                
                zstate = false;
                return true;
            }
            else{
                ness-=1;
                cout << "Vous n'avez pas trouver ! ("<<ness<<" essais restants)" << endl;
                if (ness<1){
                    cout << "PERDU... Dommage..." << endl;
                    zstate = false;
                }
            }
        }
        return false;
    }
    
    
};


#endif /* idiotpass_h */
