//
//  stars.cpp
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/23/13.
//
//

#include "Star.h"


Star::Star()
{
    initialize();
    time = 0;
}

void Star::initialize(void)
{
    y = ofRandomHeight();
    x = ofRandomWidth();
    speed = 0.5;
    ampA = 255;
    
    rad = ofRandom(5);
    timeInc = 0.1;
    
}

void Star::update(int ID)
{
    
    posA = ID;
    a = ampA * ofNoise(time*speed+posA);
    time = ofGetElapsedTimef();
}

void Star::draw(void)
{
    ofFill();
    ofSetColor(255, 255, 255, a);
    ofCircle(x,y, rad);
}