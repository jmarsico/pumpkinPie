//
//  r2d2.h
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/16/13.
//
//

#ifndef __pumpkinPie__r2d2__
#define __pumpkinPie__r2d2__

#include <iostream>
#include "ofMain.h"
#pragma once

class r2d2
{
public:
    int x,y,z,state;
    r2d2();
    void initialize(void);
    void draw(void);
    
    
    ofCylinderPrimitive cylinder;
    int cylRad = 40;
    int cylHei = 100;
    
    ofSpherePrimitive sphere;
    int sphRad = 80;
    
    ofLight pointLight;
    
    ofImage texture;
    ofMaterial material;
    
};

#endif /* defined(__pumpkinPie__r2d2__) */
