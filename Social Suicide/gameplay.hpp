//
//  gameplay.hpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//
/*
Integrer un mode jour/nuit
 la journee tout est permis(12 tours)
    [X]La police peut vous interpeller si vous faites la manche(Malchance-)
 La nuits:
    [X]impossible de faire la manche
    [X]dormir est plus risquer
    [X]des gens peuvent vous attaquer
    [X]Mode combat:
        [X]Attaque a mains nue (force)
        [X]Dissuasion (Intelligence+++ et Charisme+)
        [X]Fuite (Chance++ et Intelligence+)
*/
#ifndef gameplay_hpp
#define gameplay_hpp
#include <map>
#include <stdio.h>
#include "need.hpp"
using namespace std;

class gameplay{
private:
    need PTSLIVE;
    
    //SAC
    int CV;
    int LM;
    float money;
    
    //Competences
    float charisme, force, intelligence, guitard;
    
    void gagneExpCharisme();
    void gagneExpForce();
    void gagneExpIntell();
    void gagneExpGuitard();
    
    int hourCurrent = 2;
    bool isDay = true;
    
    
public:
    void AffGameOver(){
        cout << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "███▀▀▀██┼███▀▀▀███┼███▀█▄█▀███┼██▀▀▀" << endl;
        cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼█┼┼┼██┼██┼┼┼" << endl;
        cout << "██┼┼┼▄▄▄┼██▄▄▄▄▄██┼██┼┼┼▀┼┼┼██┼██▀▀▀" << endl;
        cout << "██┼┼┼┼██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██┼┼┼" << endl;
        cout << "███▄▄▄██┼██┼┼┼┼┼██┼██┼┼┼┼┼┼┼██┼██▄▄▄" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "███▀▀▀███┼▀███┼┼██▀┼██▀▀▀┼██▀▀▀▀██▄┼" << endl;
        cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
        cout << "██┼┼┼┼┼██┼┼┼██┼┼██┼┼██▀▀▀┼██▄▄▄▄▄▀▀┼" << endl;
        cout << "██┼┼┼┼┼██┼┼┼██┼┼█▀┼┼██┼┼┼┼██┼┼┼┼┼██┼" << endl;
        cout << "███▄▄▄███┼┼┼─▀█▀┼┼─┼██▄▄▄┼██┼┼┼┼┼██▄" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼██┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼████▄┼┼┼▄▄▄▄▄▄▄┼┼┼▄████┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼▀▀█▄█████████▄█▀▀┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼█████████████┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼██▀▀▀███▀▀▀██┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼██┼┼┼███┼┼┼██┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼█████▀▄▀█████┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼███████████┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼▄▄▄██┼┼█▀█▀█┼┼██▄▄▄┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼▀▀██┼┼┼┼┼┼┼┼┼┼┼██▀▀┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼▀▀┼┼┼┼┼┼┼┼┼┼┼" << endl;
        cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼" << endl;
    }

    gameplay(int diffi){
        srand((unsigned)time(0));
        CV=1;
        LM=1;
        charisme=0;
        force=0;
        intelligence=0;
        guitard=0;
        money=5;
        
    }
    map<int, float> getAll();
    void gagnemoney(float price){
        money = price;
    }
    
    void nextStep();
    
    void afficheTout(){
        PTSLIVE.affichage();
        //ICI GET AND DISPLAY
        map<int,float> data = getAll();
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
        cout << "Poches: " << data[7] << "€" << endl;
        cout << "SAC: " << data[8] << "CV ; "<< data[9] << "LM" << endl;
        cout << "===\nCompetences: \ncharisme: lvl(" << data[10] <<")"<< endl;
        cout << "force: lvl(" << data[11] << ")" << endl;
        cout << "intelligence: lvl(" << data[12] << ")" << endl;
        cout << "guitard: lvl(" << data[13] << ")" << endl;
        cout << "===" << endl;
    }
    
    
    //ville
    void manche();
    bool depotCV();
    bool candidate();//LM/CV
    bool manger();
    bool cinemas();
    void gratte();
    void parler();
    
    //appartement
    //MANGER
    //AUTRE
    bool imprimerCVLM();
    void dormir();
    void jouer();
    void wc();
    void douche();
    
    void timepassndegrad();
    bool gameisover();
    void poopishere();
    bool funNeeded(float seuil);
    bool socNeeded(float seuil);// Impacte le fun si bas, empeche de travailler
    void noEnergy();
    
    bool isSolar();
    void wtimeisit();
    
    void combat();

};
#endif /* gameplay_hpp */
