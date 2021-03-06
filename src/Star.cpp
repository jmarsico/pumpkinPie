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
    alpha = ampA * ofNoise(time*speed+ID);
    time = ofGetElapsedTimef();
}

void Star::draw(void)
{
    ofFill();
    ofSetColor(255, 255, 255, alpha);
    ofCircle(x,y, rad);
}