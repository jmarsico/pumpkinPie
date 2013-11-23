//
//  worldBox.h
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/23/13.
//
//

#ifndef __pumpkinPie__WorldBox__
#define __pumpkinPie__WorldBox__

#include <iostream>
#include "ofMain.h"
#pragma once

class WorldBox
{
public:
    int boxx;
    int boxy;
    int boxz;
    double width, height;
    bool bWireframe;
    
    ofBoxPrimitive world;
    ofBoxPrimitive worldCell;
    
    WorldBox();
    void initialize(void);
    void draw(void);
    void keyPressed(int key);
    
    
    
};

#endif /* defined(__pumpkinPie__worldBox__) */
