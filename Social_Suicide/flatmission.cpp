//
//  flatmission.cpp
//  Social Suicide
//
//  Created by Rick Sanchez on 07/06/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#include "flatmission.hpp"

const string flatmission::missions[5] = {
    "Une vielle dame se fait voler son sac a mains par un gronflamitte balafrer.\nIl a un couteau et un air mechant.\nVous faite quoi ?",
    "Un homme vous agresse et vous raquette, il vous menace.\nVous vous pissez dessus.\nTu va faire quoi, Tu va faire quoi?(dit en vous poussant front a front)\nAlors ?",
    "Vous trouvez un porte-feuille par-terre.\nVous faite quoi ?",
    "Quelqu'un passant a coter de vous fait tomber un pochon qui semble contenir de la dope.\nQue faite vous ?",
    "Il se met a pleuvoir des cordes et c'est pas une theorie.\nVous faites quoi?"
};

const string flatmission::reponses1[2] = {
    "Affronter l'agresseur et defendre la vielle dame.",
    "Fuir."
};

const string flatmission::reponses2[2] = {
    "Ne pas se laissez intimider et porter un coup.",
    "Lui donner tout l'argent et se mettre en PLS."
};

const string flatmission::reponses3[2] = {
    "Garder l'argent et ne rien faire.",
    "Chercher a qui ca appartient et lui rendre."
};

const string flatmission::reponses4[2] = {
    "Ne pas le ramasser et passer son chemin.",
    "Interpeler l'individu et lui rendre son bien."
};

const string flatmission::reponses5[2] = {
    "Se mettre a l'abris.",
    "Osef, rester dehors."
};


bool flatmission::affiche(){
    //affiche
    switch (ident) {
        case 0:
            cout << missions[0] << endl;
            cout <<"(1)" <<reponses1[0] << endl;
            cout <<"(2)" <<reponses1[1] << endl;
            
            break;
        case 1:
            cout << missions[1] << endl;
            cout <<"(1)" <<reponses2[0] << endl;
            cout <<"(2)" <<reponses2[1] << endl;
            
            break;
        case 2:
            cout << missions[2] << endl;
            cout <<"(1)" <<reponses3[0] << endl;
            cout <<"(2)" <<reponses3[1] << endl;
            
            break;
        case 3:
            cout << missions[3] << endl;
            cout <<"(1)" <<reponses4[0] << endl;
            cout <<"(2)" <<reponses4[1] << endl;
            
            break;
        case 4:
            cout << missions[4] << endl;
            cout <<"(1)" <<reponses5[0] << endl;
            cout <<"(2)" <<reponses5[1] << endl;
            
            break;
            
        default:
            break;
    }
    int choix;
    while (true){
        cout << "? :";
        cin >> choix;
        if ((choix==1)||(choix==2)){
            break;
        }
    }
    if (choix==1){
        switch (ident){
            case 0:
                //vol vielle dame
                if ((rand()%100)<30){
                    cout << "Vous avez vaincu !"<<endl;
                    return true;
                }
                else{
                    cout << "Vous etes tellement mou que vous vous etes blesser tout seul."<<endl;
                    return false;
                }
                break;
            case 1:
                //combat imprevu
                if ((rand()%100)<20){
                    cout << "Vous avez combatut et gagner !"<<endl;
                    return true;
                }
                else{
                    cout << "Vous etes tellement mou que vous vous etes blesser tout seul."<<endl;
                    return false;
                }
                break;
            case 2:
                //trouver par terre
                cout << "Vous avez recuperer le fric du porte-feuilles !"<<endl;
                break;
            case 3:
                //drogue trouvee
                cout << "Rien ne se passe."<<endl;
                break;
            case 4:
                //pluie
                cout << "Heureusement que vous êtes a l'abris, ce serait dommage de tomber malade."<<endl;
                break;
        }
    }
    if (choix==2){
        switch (ident){
            case 0:
                //vol vielle dame
                if ((rand()%100)<80){
                    cout << "Vous avez fuit !"<<endl;
                    return true;
                }
                else{
                    cout << "Vous etes tomber en essayant de fuir."<<endl;
                    return false;
                }
            case 1:
                //combat imprevu
                cout << "Vous n'avez plus d'argent et vous etes en PLS au sol !"<<endl;
                return false;
                break;
            case 2:
                //trouver par terre
                cout << "Vous avez rendu le porte-feuille et la personne a dit: <<Merci, c'est cool.>>" << endl;
                return true;
                break;
            case 3:
                //drogue trouvee
                if ((rand()%100)<26){
                    cout << "Vous avez rendu a un individu louche son bien !"<<endl;
                    return true;
                }
                else{
                    cout << "Vous etes tellement nerveux qu'il vous menace et vous poursuit, heureusement vous vous cachez dans une poubelle au coins d'une rue et au bout de plusiseurs minutes vous retourner apeurer en ville."<<endl;
                    return false;
                }
                break;
            case 4:
                //pluie
                if ((rand()%100)<80){
                    cout << "Il ne pleut plus au bout de 3 minutes!"<<endl;
                    return true;
                }
                else{
                    cout << "Vous etes tremper et vous etes pas en forme car il fait froid d'un coup."<<endl;
                    return false;
                }
                break;
        }
    }
    //choix
    cx = choix;
    return false;
}
