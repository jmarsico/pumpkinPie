//
//  stars.h
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/23/13.
//
//

#ifndef __pumpkinPie__stars__
#define __pumpkinPie__stars__

#include <iostream>
#include "ofMain.h"
#pragma once

class Star{
private:
    float x, y, a;
    void initialize(void);
    float speed, ampA, time, timeInc;
    int rad, posA;

public:
    
    
    Star();
    void update(int ID);
    void draw(void);


};



#endif /* defined(__pumpkinPie__stars__) */
