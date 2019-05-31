//
//  gameplay.hpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//
/*
 [X]Points de sauvegardes(2h)
 []Sauvegarde du jeu(6h)
 []Chargement du jeu(8h)
 
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
 
 
 [X]-Une araignée qui vend(5h)
 [X]-Un pot de putella(3h)
 [X]-Un bouclier pour testicules(3h)
 [X]-Intro histoire(2h)
 [X]-Couteau qui donne l’avantage sur 1 combat (80€) 3h
 [X]-La nuit tu peut te faire violer(1h)
 
 Spéciale (après 10tours une seule fois)
 [X]-Traverser la rue(parodie macron)
    [X]-Peut se faire écraser(90%)
    [X]-Peut trouver du travail(10%)

 [X]-Simulation passants manche(2h)
 [X]-Ecran gameover(1h)
 
 []-3 Lieux
 []-1 club prive
 
 
*/

#ifndef gameplay_hpp
#define gameplay_hpp
#include <map>
#include <fstream>
#include <sstream>
#include "need.hpp"
#include "sha512.h"


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
    bool bouclierAcouilles = false;
    
    bool CrotteDeNezCacaSida = false;
    bool DiarrheeAnusDilated = false;
    
    int countSida = 80;
    
    int PointSave = 3;
    
    bool couteau = false;
    bool BAC = false;
    
    
    int logique = 1;
    

    
public:
    bool oldipass1 = true;
    bool logiquestate = false;
    bool freeville = false;
    void shredder(string filePath){
        fstream is(filePath.c_str(), ios::out | ios::in | ios::binary);
        
        is.seekg(0, is.end);
        long length = is.tellg();
        is.seekg(0, is.beg);
        stringstream SS1;
        for (int i = 0; i<length; i++){
            for (int j = 0; j < 200; j++){
                SS1.str("");
                SS1 << (char) (rand()*(int)(256));
                is.seekg(i);
                is << SS1.str();
            }
            is.seekg(i);
            is << "#";
        }
        is.close();
        remove(filePath.c_str());
    }
    
    void youWon();
    float getMoney(){return money;}
    bool busUSA();
    
    bool getCouteau();
    void setCouteau();
    bool getBAC();
    void setBAC();
    bool traverserLaRue();//Traverser la rue(parodie macron)
    
    void spyderdealer();//Une araignée qui vend(5h)
    
    void Sauvegarder();//Sauvegarde du jeu(6h)
    void addPointSave(int val);//Points de sauvegardes(2h)
    int getPS(){return PointSave;}
    bool Charger();//Chargement du jeu(8h)
    
    bool mourirDeCrotteDeNezCacaSida(){
        if (CrotteDeNezCacaSida){
            countSida-=1;
            if (countSida<=0){
                if ( (rand()%100) < 95){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    void getBACouilles();
    bool useBACouilles();
    /*
     Le putella permet d'augmenter les PV et le Divertissement
     Il coute 50 credits
     Il est possible de choper une des plus graves maladies
     Il désactive le BAC
     Il est vendu par une arraignée (Mac in teucha)
     */
    void usePutella();
    
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
    int getTime();
    
    void combat();

};


#endif /* gameplay_hpp */
