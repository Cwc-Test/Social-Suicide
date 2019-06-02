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
#include "gloobar.h"
using namespace std;

gameplay jeu(1);
//START VAR
int lieux = 1;
bool candidated = true;
int countcand = 0;
int counttour = 0;
bool isLaRue = true;
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
int memchoix = 0;
int memlieu = 0;
bar BAR;
bool firstbar = true;
void choixAct(int lieu){
    int choix = 0;
    bool funisnee = jeu.funNeeded(0.15);
    
    bool socisnee = jeu.socNeeded(0.10);
    countcand -= 1;
    if (countcand <= 0) {
        candidated = true;
        countcand = 0;
    }
    if (lieu==2){
        if (firstbar){
            firstbar = false;
            cout << "Braman: Hey mec j'te serre a boire ?"<<endl<<"Barman: Tu peux aussi jouer a la machine mais j'te préviens c'est pas pour les abrutits !" << endl;
        }
        cout << "0 - Aller pisser"<<endl;
        cout << "1 - Boire un verre"<<endl;
        if (jeu.oldipass1){
            cout << "2 - Jouer a IdiotPass" << endl;
        }
        cout << "3 - Ecouter de la musique"<<endl;
        cout << "4 - Aller autre part..." <<endl;
        
        cin >> choix;
        cout << endl << endl;
        switch (choix) {
            case 4:
                lieu = jeu.aller();
                break;
            case 3:
                jeu.jouer();
                break;
            case 0:
                jeu.wc();
                break;
            case 1:
                if (jeu.getMoney()>=7.00){
                    cout << "Tu donne 7 euros au barman et il te sert un verre."<< endl;
                    cout << "Tu le boie..." << endl;
                    BAR.oneMoreBeer();
                    int eff = BAR.getBeer();
                    switch (eff) {
                        case 1:
                            jeu.tempcourage = 6;
                            break;
                        case 2:
                        case 3:
                            jeu.maladroit = 4;
                            break;
                        case 6:
                        case 7:
                            jeu.zerocar = 6;
                            break;
                        case 9:
                            jeu.vomir();
                            break;
                        default:
                            break;
                    }
                    if(BAR.getComa()){
                        cout << "Tu est tomber dans le coma et tu est cliniquement mort..."<< endl;
                        jeu.AffGameOver();
                        exit(0);
                    }
                }
                else{
                    cout << "T'en a pas marre d'etre pauvre? Bordel ta meme pas 7 euros..." << endl << "Tu ne peut pas boire tant pis.." << endl;
                }
                break;
            case 2:
                if (jeu.oldipass1){
                    if (jeu.getMoney()>=2.00){
                        cout << "Tu met deux euros dans la machine."<< endl;
                        bool result = BAR.machina();
                        if (result){//winner code
                            cout << "Vous debloquez la competence: logique" << endl;
                            jeu.logiquestate = true;
                            
                            cout << "Vous pouvez maintenant sortir de la ville, allez explorer !" << endl;
                            jeu.freeville = true;
                            
                            jeu.oldipass1 = false;
                        }
                    }
                    else{
                        cout << "T'est vraiment un clodo, ta meme pas 2 euros..." << endl << "Tu ne peut pas jouer." << endl;
                    }
                }
                break;
        }
    }
    if (lieu==1){
        cout << "\nVous êtes en ville.\nQue faire ?" << endl;
        if (jeu.isSolar()){
            if (jeu.getTime() < -3){
                if (jeu.getTime() > -6){
                    cout << "0 - Parler a l'araignee poilue" << endl;
                }
            }
        }
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
        if (counttour>10){
            if (isLaRue){
               cout << "8 - Traverser la rue pour trouver du travail" << endl;
            }
        }
        if (jeu.getMoney()>100){
            cout << "9 - Prendre le bus pour chopper l'avion vers les USA(Rentrer chez vous)" << endl;
        }
        if (jeu.getPS()>0){
            cout << "10 - Sauvegarder" << endl;
        }
        cout << "11 - Allez dans les toilettes publiques" << endl;
        cout << "12 - Allez autre part..."<< endl;
        
        cin >> choix;
        cout << endl << endl;
        bool res;
        counttour+=1;
        switch (choix) {
            case 12:
                lieu = jeu.aller();
                break;
            case 11:
                jeu.wc();
                jeu.nextStep();
                break;
            case 10:
                if (jeu.getPS()>0){
                    jeu.Sauvegarder();
                }
                break;
            case 8:
                if (counttour>10){
                    if (isLaRue){
                        if(jeu.traverserLaRue()){
                            cout << "Vous avez ete retenu pour du travail !" << endl;
                            
                            cout << "Quelque temps plus tard vous avez finit votre contrat..." << endl;
                            float calcmoney = (rand()%1200)+400;
                            jeu.gagnemoney(calcmoney);
                            cout << "Vous avez gagner: " << calcmoney << "€ !" << endl;
                        }
                        isLaRue = false;
                    }
                }
                break;
            case 0:
                if (jeu.isSolar()){
                    if (jeu.getTime() < -3){
                        if (jeu.getTime() > -6){
                            jeu.spyderdealer();
                        }
                    }
                }
                break;
            case 1:
                jeu.manche();
                break;
            case 2:
                res = jeu.manger();//7.00
                if (!res){
                    cout << "La bouffe coute 7.00€, t'a pas les tunes mec !" << endl;
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
                
            case 9:
                if (jeu.getMoney()>100){
                    bool resultfinal = jeu.busUSA();
                    if (resultfinal){
                        jeu.youWon();
                    }
                }
                break;
                
            default:
                counttour-=1;
                if (counttour<0){counttour=0;}
                break;
        }
    }
    memlieu = lieu;
    memchoix = choix;
}


int main(int argc, const char * argv[]) {
    cout << "Charger la sauvegarde ? (O)ui/(N)on" << endl;
    string chrg;
    cin >> chrg;
    bool crx = false;
    if (chrg=="O"){
        crx = jeu.Charger();
    }
    
    
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
    cout << "Social Suicide, Le jeu de Jerry !" << endl << "Enfin c'est rick qui l'a cree car Jerry est trops con pour ca...\n" << endl;
    
    cout << "Rick Sanchez t’a laisser, toi Jerry Smith dans la rue(dimension inconnue),\navec quelques euros en poche et rien d’autre!" << endl;
    cout << "Tu dois survivre et te sortir de là, tu est un crétin et Rick a déjà d’eu te remplacer par un clone." << endl <<"Mais tu ne veux pas mourrir et même si tu est con tu va essayer de t’en sortir."<<endl<<endl;
    
    cout << "RICK DIT:" << "Tiens voila 5 euro, ici c’est la France donc tu paye pas en dollars." << endl;
    cout << "On va voir si tu réussit a survivre, peut-être que je te respecterai, sinon c’est pas grave,\nj’ai un plan de secours si tu venait malencontreusement a mourrir." << endl;
    cout << "T’est tellement stupide que ça ne devrait pas être un problème.\n";
    cout << "Je suis sur que personne ne verra la différence.\n";
    cout << "Essaye de trouver un travail, ici personne ne va t ‘héberger a l’oeil.\n";
    cout << "Par contre essaye de ne pas te faire violer, ça serait con de choper des merdes.\n\n";
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
        if (jeu.gameisover()){
            jeu.AffGameOver();
            return 0;
        }
        jeu.poopishere();
        jeu.noEnergy();
        jeu.nextStep();
        jeu.mourirDeCrotteDeNezCacaSida();
        jeu.zerocharisme();
        if (jeu.maladroitesse()){
            int malchance = (rand()%100) < 80;
            if (malchance){
                float prcentmoney = rand() % 100;
                jeu.perdreArgent(prcentmoney);
            }
        }

    }
    jeu.simuCrevard(memlieu,memchoix);
    return 0;
}
