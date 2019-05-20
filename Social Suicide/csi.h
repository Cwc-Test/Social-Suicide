//
//  Header.h
//  CSI
//
//  Created by Rick Sanchez on 08/10/2018.
//  Copyleft © 2018 Rick Sanchez. All rights reserved.
//  Juste un truc a dire, si tu utilise ça c'est comme si tu disait "nique la police"
//  Moi j'ai rien dir, c'est de ta faute sale racaille xD
//  Aller n'oubliez pas que celui qui fabrique le verre n'est pas responsable de ce que l'on met dedans...
//

#ifndef CSI_h
#define CSI_h
#include <map>
#include <sstream>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "sha512.h"
#include "Shred.h"
#include "base64.h"
#include "like.h"
#include <functional>
#endif /* Header_h */
using namespace std;

stringstream readFileLines(string filepath){
    string line;
    stringstream SS1;
    ifstream infile(filepath.c_str());
    if (infile.is_open()){
        while (getline(infile,line)){
            SS1 << line << endl;
        }
    }
    return SS1;
}

std::hash<std::string> hash_fn;


string findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
    }
    return data;
}

class CSI4096{
public:
    CSI4096(unsigned int tailleBlocs): size_block(tailleBlocs)
    {
        tblc = tailleBlocs;
        buffer.clear();
        passW = "None";
        pos = 0;
        ENDERPOS = false;
        filepath = "";
    }
    
    void set_password(string motdepasse){
        passW = motdepasse;
    }
    
    void set_file(string nomfichier){
        filepath = nomfichier;
        destfilepath = nomfichier+".CSI";
    }
    
    void set_file2(string nomfichier){
        filepath = nomfichier;
        destfilepath = findAndReplaceAll(nomfichier, ".CSI", "");
    }
    
    void crypt(){
        srand((int)hash_fn(passW));//Le rand() est en fonction du mot de passe, plutôt simple hein ?
        ofstream fichier(destfilepath.c_str());
        if (fichier.is_open()){
            makeSign();
            fichier << passW;
            while (!ENDERPOS){
                make_key();
                readFileBlocks();
                cipher();
                fichier << buffer;
            }
            fichier.close();
        }
        else {
            cout << "ERROR: Can't write file destination !" << endl;
        }
    }
    
    void decrypt(){
        srand((int)hash_fn(passW));//Le rand() est en fonction du mot de passe, plutôt simple hein ?
        ofstream fichier(destfilepath.c_str());
        if (fichier.is_open()){
            size_block = 172;
            readFileBlocks();
            RefPW = buffer;
            size_block = tblc;
            if (getSign()){
                while (!ENDERPOS){
                    make_key();
                    readFileBlocks();
                    decipher();
                    fichier << buffer;
                }
            }
            else {
                cout << "ERROR BAD PASSORD ! "<<endl;
            }
            fichier.close();
        }
        else {
            cout << "ERROR: Can't write file destination !" << endl;
        }
    }
    
    
private:
    unsigned int tblc;
    string destfilepath;
    string KEY;
    bool ENDERPOS;
    string buffer;
    unsigned int size_block;
    int seed;
    string passW;
    int pos;
    string filepath;
    string RefPW;
    //friend std::string base64_encode(unsigned char const* , unsigned int len);
    //friend std::string base64_decode(std::string const& s);
    //Bha faut lire le fichier par bloc
    //tout lire d'un coup c'est pas top donc voilà
    void makeSign(){
        passW = sha512(passW);
        //cout << "0@" << passW << "@" << endl;
        passW = base64_encode((unsigned char const*)passW.c_str(),(unsigned int)passW.size());
    }
    
    bool getSign(){
        passW = sha512(passW);
        //cout << "1@" << passW << "@" << endl;
        RefPW = base64_decode((string const&)RefPW.c_str());
        //cout << "2@" << RefPW << "@" << endl;
        return is_equal_like(passW, RefPW);
    }
    
    void readFileBlocks(){
        string bloc;
        stringstream SS1;
        char tmp;
        ifstream fichier(filepath.c_str(), std::ios_base::binary);
        if (fichier.is_open()){
            fichier.seekg(pos);
            for (int i=0; i!=size_block; i++){
                if (fichier.peek() != EOF){
                    tmp = fichier.get();
                    pos++;
                    SS1 << tmp;
                }
                else{
                    ENDERPOS = true;
                }
            }
            buffer = SS1.str();
            SS1.str("");
            fichier.close();
        }
    }
    
    friend stringstream readFileLines(string filepath);
    
    void make_key(){
        stringstream SS1;
        char tmp;
        for (int i=0; i<512; i++){ //512*8 = 4096bits
            tmp = rand()%256;
            SS1 << tmp;
        }
        KEY = SS1.str();
        SS1.str("");
    }
    
    void cipher(){
        for (int i=0; i<buffer.size(); i++){
            int delta1 = rand()%300;
            for (int j=0; j<KEY.size(); j++){
                int salt = rand()%256;
                buffer[i] = ((buffer[i] ^ KEY[j]));
                buffer[i] = buffer[i] ^ salt;
            }
            buffer[rand()%buffer.size()] ^= rand()%256;
            buffer[i] = buffer[i] ^ delta1;
        }
        
        //(unsigned char const* , unsigned int len)
        
        
    }

    void decipher(){
        //string const&
        for (int i=0; i<buffer.size(); i++){
            int delta1 = rand()%300;
            for (int j=0; j<KEY.size(); j++){
                int salt = rand()%256;
                buffer[i] = ((buffer[i] ^ KEY[j]));
                buffer[i] = buffer[i] ^ salt;
            }
            buffer[rand()%buffer.size()] ^= rand()%256;
            buffer[i] = buffer[i] ^ delta1;
        }
    }
    
};
