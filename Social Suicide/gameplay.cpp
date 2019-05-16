//
//  gameplay.cpp
//  Social Suicide
//
//  Created by Rick Sanchez on 28/04/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#include "gameplay.hpp"

void gameplay::usePutella(){
    
}

bool gameplay::getBAC(){
    return BAC;
}

void gameplay::setBAC(){
    BAC = true;
}

bool gameplay::getCouteau(){
    return couteau;
}
void gameplay::setCouteau(){
    couteau = true;
}

bool gameplay::traverserLaRue(){//Traverser la rue(parodie macron)
    //- [X]         [X]-Peut se faire écraser(90%)
    //- [X]         [X]-Peut trouver du travail(10%)
    if ( (rand()%100) < 90){
        //ecraser
        cout << "Vous venez de vous faire ecraser par un bus, vous êtes mort !"<< endl;
        AffGameOver();
        exit(0);
    }
    else{
        //trouver du travail
        cout << "Houra macron avait raison ! Vous êtes embauche !" << endl;
        return true;
    }
    return false;
}

void gameplay::spyderdealer(){
    /*
     []-Une araignée qui vend(5h)
     []-Un pot de putella(3h)
     []-Un bouclier pour testicules(3h)
     [X]-Couteau qui donne l’avantage sur 1 combat (80€) 3h
    */
    cout << "0 - Acheter un couteau" << endl;
    cout << "1 - Acheter un pot de Putella" << endl;
    cout << "2 - Acheter un B.A.C.(Bouclier à testicules)"<< endl;
    int choix;
    cin >> choix;
    switch (choix) {
        case 0:
            if (money>=80.00){
                money-=80.00;
                setCouteau();
            }
            break;
            
        case 1:
            if (money>=50.99){
                money-=50.99;
                usePutella();
            }
            break;
        case 2:
            if (money>=32.70){
                money-=32.70;
                setBAC();
            }
            
        default:
            break;
    }
}

int gameplay::getTime(){
    return hourCurrent;
}

void gameplay::Sauvegarder(){//Sauvegarde du jeu(6h)
    if (PointSave>0){
        PointSave-=1;
        
    }
}
void gameplay::addPointSave(int val){//Points de sauvegardes(2h)
    PointSave+=val;
}
void gameplay::Charger(){//Chargement du jeu(8h)
    
}

void gameplay::getBACouilles(){
    bouclierAcouilles = true;
}
void gameplay::combat(){
    /*
     [X]Mode combat:
     [X]Attaque a mains nue (force)
     [X]Dissuasion (Intelligence+++ et Charisme+)
     [X]Fuite (Chance++ et Intelligence+)
     */
    cout << "Vous vous faites attaquer !" << endl;
    float PV = 50;
    float PVopp = rand()%50;
    float FORCEopp = rand()%10;
    int choix;
    int chance, x;
    bool breakerfast = true;
    while (breakerfast){
        cout << "Tu a " << PV << " PV" << endl;
        cout << "Il a " << PVopp << " PV" << endl;
        cout << "1 - Attaquer a mains nues" << endl;
        cout << "2 - Dissuasion" << endl;
        cout << "3 - Fuite" << endl;
        cin >> choix;
        switch (choix) {
            case 1: //Attaque a mains nue (force)
                chance = (rand() % 100) < 80;
                if (chance){
                    x = 3;
                    if ( ( (force * 5) / (FORCEopp * 5) ) > 0 ) {
                        // Je suis plus fort que lui
                        x = x + rand()%10;
                        x += ( (force * 2) / (FORCEopp * 3) )* 10;
                    }
                    force += (rand()%20)/100;
                    PVopp-=x;
                }
                else{
                    cout << "Echec du coup !" << endl;
                }
                break;
            case 2: //Dissuasion (Intelligence+++ et Charisme+)
                chance = (rand()%100) < 500 / 100 * ((1+intelligence)*0.3);
                if (chance){
                    if ((rand()%100) < 500 / 100 * ((1+charisme)*0.1)){
                        cout << "L'ennemi viens de fuir !" << endl;
                        breakerfast = false;
                    }
                    PVopp-=rand()%10;
                }
                else{
                    cout << "Echec du coup !" << endl;
                }
                break;
            case 3: //Fuite (Chance++ et Intelligence+)
                chance = (rand() % 100) < 40;
                if (chance){
                    breakerfast = false;
                    cout << "Vous fuyez !" << endl;
                }
                else{
                    if (intelligence > FORCEopp){
                        breakerfast = false;
                        cout << "Vous fuyez !" << endl;
                    }
                    else{
                        cout << "Echec de fuite !" << endl;
                    }
                }
                break;
                
            default:
                break;
        }
        //GAMEOVER
        if (PV <= 0){
            cout << "Vous êtes mort !" << endl;
            //ASCII GO
            AffGameOver();
            exit(0);
        }
        
        //WIN
        if (PVopp <= 0){
            x = rand()%10;
            cout << "L'ennemi est mort !" << endl;
            breakerfast = false;
            money+=x;
            cout << "Vous lui volez " << x << " Euros !" << endl;
        }
        
    }
    
}

bool gameplay::isSolar(){
    return isDay;
}

void gameplay::wtimeisit(){
    if (!isDay){
        cout << "Il est " << hourCurrent << "h du soir"<<endl;
    }
    cout << "Il est " << hourCurrent << "h du matin"<<endl;
}

void gameplay::nextStep(){
    if (isDay){
        hourCurrent  = ( hourCurrent + 1) % 13;
        if (hourCurrent==0){
            isDay = not isDay;
        }
    }
    if (!isDay){
        hourCurrent  = ( hourCurrent - 1) % -13;
        if (hourCurrent==0){
            isDay = not isDay;
        }
    }
}

void gameplay::gagneExpCharisme(){
    charisme = (charisme + (rand()%10)/100);
}

void gameplay::gagneExpForce(){
    force = (force + (rand()%10)/100);
}

void gameplay::gagneExpIntell(){
    intelligence = (intelligence + (rand()%10)/100);
}

void gameplay::gagneExpGuitard(){
    guitard = (guitard + (rand()%10)/100);
}

map<int, float> gameplay::getAll(){
    map<int, float> MATRX;
    /*
     besoins[1] = need_app;X
     besoins[2] = need_hyg;X
     besoins[3] = need_vess;X
     besoins[4] = need_fun;X
     besoins[5] = need_sleep;X
     besoins[6] = need_soc;X
     MATRX[7] = money;
     MATRX[8] = CV;
     MATRX[9] = LM;
     MATRX[10] = charisme;X
     MATRX[11] = force;
     MATRX[12] = intelligence;X
     MATRX[13] = guitard;X
     PTSLIVE.affichage();
     CV=1;
     LM=1;
     charisme=0;
     force=0;
     intelligence=0;
     guitard=0;
     money=5;
     */
    MATRX = PTSLIVE.getNeeds();
    MATRX[7] = money;
    MATRX[8] = CV;
    MATRX[9] = LM;
    MATRX[10] = charisme;
    MATRX[11] = force;
    MATRX[12] = intelligence;
    MATRX[13] = guitard;
    return MATRX;
}

void gameplay::noEnergy(){
    if (PTSLIVE.getNeeds()[5]<0.01){
        cout << "Vous êtes fatigue et vous vous endormez !" << endl;
        //Vous vous faites voler
        bool malchance = (rand() % 100) < 30;
        if (malchance){
            money = 0;
            cout << "Vous vous faites voler tout votre argent !" << endl;
        }
        //Vous perder une compétence
        malchance = (rand() % 100) < 8;
        if (malchance){
            int comp = rand() % 4;
            cout << "Vous perdez des points de competence !" << endl;
            float calu = ( rand() % 100 ) / 100;
            switch (comp) {
                case 0:
                    charisme -= calu;
                    cout << calu * 100 << "% perdu sur la competence charisme" << endl;
                    break;
                case 1:
                    force -= calu;
                    cout << calu * 100 << "% perdu sur la competence force" << endl;
                    break;
                case 2:
                    intelligence -= calu;
                    cout << calu * 100 << "% perdu sur la competence intelligence" << endl;
                    break;
                case 3:
                    guitard -= calu;
                    cout << calu * 100 << "% perdu sur la competence guitard" << endl;
                    break;
                    
                default:
                    break;
            }
        }
        
        //Vous dégrader vos besoins pour 4 tours
        for (int i=0; i<4; i++){
            timepassndegrad();
        }
        PTSLIVE.dormir(0.6);
    }
}

bool gameplay::socNeeded(float seuil){
    if (PTSLIVE.getNeeds()[6]<seuil){
        PTSLIVE.degradFun(0.08);
        return true;
    }
    return false;
}// Impacte le fun si bas, empeche de travailler

bool gameplay::funNeeded(float seuil){
    if (PTSLIVE.getNeeds()[4]<seuil){
        return true;
    }
    return false;
}

void gameplay::poopishere(){
    float Poop = PTSLIVE.getNeeds()[3];
    if (Poop<=0){
        charisme = (charisme - 1);
        PTSLIVE.HygZero();
    }
}

bool gameplay::gameisover(){
    float Appetit = PTSLIVE.getNeeds()[1];
    if (Appetit <= 0){
        return true;
    }
    return false;
}

bool gameplay::depotCV(){
    if (PTSLIVE.PoopInEyes()){
        cout << "Vous puez la merde !" << endl;
    }
    else{
        if (CV>=1){
            CV-=1;
            if ( (rand()%100) < 500 / 100 * ((1+charisme)*0.1) ){
                gagneExpCharisme();
                return true;
            }
        }
    }
    return false;
}

bool gameplay::candidate(){
    if (PTSLIVE.PoopInEyes()){
        cout << "Vous puez la merde !" << endl;
    }
    else{
        if ((CV>=1)&(LM>=1)){
            CV-=1;
            LM-=1;
            if ( (rand()%100) < 500 / 100 * ((1+charisme)*0.5) ){
                gagneExpCharisme();
                if ( (rand()%100) < 500 / 100 * ((1+intelligence)*0.8) ){
                    gagneExpIntell();
                    return true;
                }
            }
        }
    }
    return false;
}

void gameplay::gratte(){
    bool malchance = (rand() % 100) < 6;
    int x = 0.02;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradHyg(x);
    malchance = (rand() % 100) < 4;
    x = 0.02;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradVess(x);
    malchance = (rand() % 100) < 10;
    x = 0.10;
    if (malchance){
        x += (rand() % 10)/100;
    }
    PTSLIVE.degradSleep(x);
    
    bool chance = (rand() % 100) < 10;
    x =  1.00;
    if (chance){
        x += (rand() % 11);
    }
    malchance = (rand() % 100) < 35;
    bool chanceCompetences = (rand() % 100) < (guitard * 5);
    if (!malchance){
        gagneExpGuitard();
        if (chanceCompetences){
            x += (rand() % 10);
        }
        guitard+=(rand()%100)/100;
    }
    money+=x;
}

bool gameplay::cinemas(){
    if (money>=12.60){
        money-=12.60;
        bool malchance = (rand() % 100) < 15;
        float x = 0.1;
        if (malchance){
            x += (rand() % 30)/100;
        }
        PTSLIVE.degradVess(x);
        bool chance = (rand() % 100) < 30;
        x = 0.35;
        if (chance){
            x += (rand() % 20)/100;
        }
        PTSLIVE.jouer(x);
        return true;
    }
    if (money+0.01==12.60){ cout << "Il te manque 1 centime !"<<endl;}
    return false;
}

void gameplay::timepassndegrad(){
    bool malchance = (rand() % 100) < 6;
    float x = 0.05;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradApp(x);
    malchance = (rand() % 100) < 6;
    x = 0.02;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradHyg(x);
    malchance = (rand() % 100) < 4;
    x = 0.02;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradVess(x);
    malchance = (rand() % 100) < 6;
    x = 0.05;
    if (malchance){
        x += (rand() % 3)/100;
    }
    PTSLIVE.degradFun(x);
    malchance = (rand() % 100) < 9;
    x = 0.03;
    if (malchance){
        x += (rand() % 5)/100;
    }
    PTSLIVE.degradSoc(x);
    malchance = (rand() % 100) < 10;
    x = 0.04;
    if (malchance){
        x += (rand() % 6)/100;
    }
    PTSLIVE.degradSleep(x);
}

bool gameplay::imprimerCVLM(){
    if (money>=5.00){
        CV += 1;
        LM += 1;
        money -= 5.00;
        return true;
    }
    return false;
}

void gameplay::dormir(){
    int coefmal;
    if (isDay){
        coefmal=5;
    }
    else{
        coefmal = 45;
        //La nuit tu peut te faire violer(1h)
        bool vviol = (rand() % 100) < 15;
        if (vviol){
            cout << "Vous vous faites violer par l'anus !\nVous en avez plein le cul!" << endl;
            if ( (rand()%100) < 5 ){
                CrotteDeNezCacaSida = true;
            }
            if ( (rand()%100) < 15 ){
                DiarrheeAnusDilated = true;
                cout << "Votre anus est eclaté !\n Vous pouvez vous chiez dessus !"<<endl;
            }
        }
    }
    bool malchance = (rand() % 100) < coefmal;
    if (malchance){
        money = 0;
        cout << "Vous vous faites voler tout votre argent !" << endl;
    }
    bool chance = (rand() % 100) < 10;
    float x = 0.85;
    if (chance){
        x += (rand() % 8)/100;
    }
    PTSLIVE.dormir(x);
    malchance = (rand() % 100) < 25;
    if (malchance){
        cout << "Vous vous faites attaquer !" << endl;
        combat();
    }
}

bool gameplay::manger(){
    if (money>=7.00){
        money-=7.00;
        bool malchance = (rand() % 100) < 17;
        float x = 0.1;
        if (malchance){
            x += (rand() % 30)/100;
        }
        PTSLIVE.degradVess(x);
        bool chance = (rand() % 100) < 15;
        x = 0.40;
        if (chance){
            x += (rand() % 15)/100;
        }
        PTSLIVE.manger(x);
        return true;
    }
    if (money+0.01==7.00){ cout << "Il te manque 1 centime !"<<endl;}
    return false;
}

void gameplay::douche(){
    bool chance = (rand() % 100) < 15;
    float x = 0.75;
    if (chance){
        x += (rand() % 15)/100;
    }
    PTSLIVE.laver(x);
}

void gameplay::wc(){
    bool chance = (rand() % 100) < 20;
    float x = 0.85;
    if (chance){
        x += (rand() % 15)/100;
    }
    PTSLIVE.pisser(x);
}

void gameplay::jouer(){
    bool chance = (rand()%100) < 500 / 100 * ((1+guitard)*0.1);
    float x = 0.60;
    if (chance){
        x += (rand() % 25)/100;
    }
    bool malchance = (rand() % 100) < 10;
    
    if (!malchance){
        gagneExpGuitard();
    }
    PTSLIVE.jouer(x);
}

void gameplay::parler(){
    bool chance = (rand() % 100) < 15;
    float x = 0.20;
    if (chance){
        x += (rand() % 40)/100;
    }
    PTSLIVE.parler(x);
}

void gameplay::manche(){
    if (isDay){
        bool malchance = (rand() % 100) < 6;
        if (malchance){
            cout << "La police vous arrête car la mendicite est interdite !\nDirection le poste de police !" << endl;
            cout << "Vous en sortez au bout de plusieurs heures." << endl;
            for (int i=0; i<2+rand()%8; i++){
                nextStep();
            }
        }
        else{
            map<int, float> sommeswin;
            bool chance;
            float x;
            bool malchance;
            bool chanceCompetences;
            int idmax = rand()%50;
            for (int id=0; id<idmax; id++){
                chance = (rand() % 100) < 16;
                x = (rand()%100)/ 100;
                if (chance){
                    x += (rand() % 10);
                }
                malchance = (rand() % 100) < 35;
                chanceCompetences = (rand() % 100) < (charisme * 5);
                if (!malchance){
                    gagneExpCharisme();
                    if (chanceCompetences){
                        x += (rand() % 30);
                    }
                }
                sommeswin[id] = x;
                
            }
            
            for (int i=0; i<idmax; i++){
                if (sommeswin[i]==0.00){cout << "Connard dit: Va trouver du travail faigneant"<< endl;}
                else{
                    cout << "Vous recevez " << sommeswin[i] << " Euros !" << endl;
                }
                money+=sommeswin[i];
            }
        }
    }
    else{
        cout << "Impossible de faire la manche car il fait nuit !!" << endl;
    }
}

