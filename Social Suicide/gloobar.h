//
//  gloobar.h
//  Social Suicide
//
//  Created by Rick Sanchez on 01/06/2019.
//  Copyright © 2019 Rick Sanchez. All rights reserved.
//

#ifndef gloobar_h
#define gloobar_h
#include "idiotpass.h"
class bar{
private:
    int resistancebeer = 9;
    int beercount = 0;
    
    
public:
    bool getComa(){
        return beercount>=10;
    }
    void oneMoreBeer(){
        beercount++;
    }
    int getBeer(){return beercount;}
    bool machina(){
        idiotbarmachine IBM(6);
        return IBM.playLoop();
    }
};
#endif /* gloobar_h */
