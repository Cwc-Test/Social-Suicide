//
//  main.cpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#include <iostream>
#include <map>
#include "gameplay.hpp"
#include <stdio.h>
#include <sys/ioctl.h>
using namespace std;

gameplay jeu(1);
//START VAR
int lieux = 1;
bool candidated = true;
int countcand = 0;

/*
 besoins[1] = need_app;
 besoins[2] = need_hyg;
 besoins[3] = need_vess;
 besoins[4] = need_fun;
 besoins[5] = need_sleep;
 besoins[6] = need_soc;
 MATRX[7] = money;
 MATRX[8] = CV;
 MATRX[9] = LM;
 MATRX[10] = charisme;
 MATRX[11] = force;
 MATRX[12] = intelligence;
 MATRX[13] = guitard;
 */
void choixAct(int lieu){
    bool funisnee = jeu.funNeeded(0.15);
    
    bool socisnee = jeu.socNeeded(0.10);
    countcand -= 1;
    if (countcand <= 0) {
        candidated = true;
        countcand = 0;
    }
    if (lieu==1){
        cout << "\nVous êtes en ville.\nQue faire ?" << endl;
        cout << "1 - La manche" << endl;
        cout << "2 - Manger un truc" << endl;
        cout << "3 - Parler aux gens" << endl;
        cout << "4 - Jouer de la guitare" << endl;
        cout << "5 - Aller au cinemas" << endl;
        if (!funisnee | !socisnee){
            cout << "6 - Deposer un CV dans une boite" << endl;
            if (candidated){
                cout << "7 - Deposer une candidature" << endl;
            }
        }
        
        int choix;
        cin >> choix;
        bool res;
        switch (choix) {
            case 1:
                jeu.manche();
                break;
            case 2:
                res = jeu.manger();//7.00
                if (!res){
                    cout << "Le cinemas coute 7.00€, t'a pas les tunes mec !" << endl;
                }
                break;
            case 3:
                jeu.parler();
                break;
            case 4:
                jeu.gratte();
                break;
            case 5:
                res = jeu.cinemas();//12.60
                if (!res){
                    cout << "Le cinemas coute 12.60€, t'a pas les tunes mec !" << endl;
                }
                break;
            case 6:
                if (!funisnee | !socisnee){
                    res = jeu.depotCV();
                    if (res){
                        cout << "Vous avez trouver du travail !" << endl;
                        
                        cout << "Quelque temps plus tard vous avez finit votre contrat..." << endl;
                        float calcmoney = (rand()%100)+30;
                        jeu.gagnemoney(calcmoney);
                        cout << "Vous avez gagner: " << calcmoney << "€ !" << endl;
                    }
                }
                else {
                    cout << "Vous êtes trops tendu pour faire ça !" << endl;
                }
                break;
            case 7:
                if (!funisnee | !socisnee){
                    if (candidated){
                        res = jeu.candidate();
                        if (res){
                            cout << "Vous avez ete retenu pour du travail !" << endl;
                            
                            cout << "Quelque temps plus tard vous avez finit votre contrat..." << endl;
                            float calcmoney = (rand()%300)+30;
                            jeu.gagnemoney(calcmoney);
                            cout << "Vous avez gagner: " << calcmoney << "€ !" << endl;
                        }
                        else {
                            candidated = false;
                            countcand = 8;
                        }
                    }
                }
                else {
                    cout << "Vous êtes trops tendu pour faire ça !" << endl;
                }
                break;
                
            default:
                break;
        }
    }
}


int main(int argc, const char * argv[]) {
    cout << "Veuillez mettre le terminal en plein écran." << endl;
    while (true){
        //Structure dans laquelle sera mit les informations du terminal
        struct winsize w;
        //Recuperation des informations
        ioctl(0, TIOCGWINSZ, &w);
        if (w.ws_row>40){
            if (w.ws_col>190){
                break;
            }
        }
    }
    //efface
    system("clear");
    
    /*
     besoins[1] = need_app;
     besoins[2] = need_hyg;
     besoins[3] = need_vess;
     besoins[4] = need_fun;
     besoins[5] = need_sleep;
     besoins[6] = need_soc;
     MATRX[7] = money;
     MATRX[8] = CV;
     MATRX[9] = LM;
     MATRX[10] = charisme;
     MATRX[11] = force;
     MATRX[12] = intelligence;
     MATRX[13] = guitard;
     */
    
    //MAIN LOOP
    while (true){
        //system("clear");
        cout << "\n\n";
        //jeu.wtimeisit();
        if (jeu.isSolar()){
            cout << "Il fait jour." << endl;
        }
        else{
            cout << "Il fait nuit." << endl;
        }
        jeu.afficheTout();
        jeu.timepassndegrad();
        choixAct(lieux);
        if (jeu.gameisover()){ return 0; }
        jeu.poopishere();
        jeu.noEnergy();
        jeu.nextStep();
    }
    
    return 0;
}
