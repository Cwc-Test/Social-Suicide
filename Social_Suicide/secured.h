//
//  secured.h
//  Social Suicide
//
//  Created by Rick Sanchez on 17/05/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef secured_h
#define secured_h
#include <stdio.h>
#include <sys/ioctl.h>

#include <iostream>
#include <cstdlib>
#include "csi.h"
#include <unistd.h>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


void encodesave(string filename, string password){
    cout << "[CHIFFREMENT]FICHIER: " << filename << endl;
    CSI4096 algocrypt(512);
    algocrypt.set_file(filename);
    algocrypt.set_password(password);
    algocrypt.crypt();
    
    shredder(filename);
}

void decodesave(string filename, string password){
    cout << "[DECHIFFREMENT]FICHIER: " << filename << endl;
    CSI4096 algocrypt(512);
    algocrypt.set_file2(filename);
    algocrypt.set_password(password);
    
    algocrypt.decrypt();
}

void killedfile(string filename){
    shredder(filename);
}

#endif /* secured_h */
