//
//  Menu.h
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/16/13.
//
//

#ifndef __pumpkinPie__Menu__
#define __pumpkinPie__Menu__

#include <iostream>
#include "r2d2.h"
#include "ofMain.h"
#pragma once

class Menu
{
private:
    int selection;          //controll class can call getSelection();

public:
    float y;
    int state;
    
    Menu();
    void initialize(void);   //you don't need to call this, it is called in the constructor
    void update(void);          //used
    void draw(void);
    void select(const int mX, const int mY);        //call this function in the "mousepressed()" function in testapp.cpp
    int getSelection(void);                     //controller can call this to see what level to start on
    
    ofTrueTypeFont GalaxyAlt30;                 //type object (30pt)
    ofTrueTypeFont GalaxyAlt14;                 //type object (14pt)
    ofTrueTypeFont GalaxyAlt80;                 //type font for title (80pt)
    r2d2 R2d2;
    
   
    
    
    //text to be displayed in menu
    string line[4] = {"In a galaxy far, far away",      //array of strings for 
                    "five students built a game",       //each line of intro text
                    "the game is called...",
                    "STAR WARS"};
    
    string level[4] = {"Level 1", "Level 2", "Level 3", "RESUME"};
    
    
    
    //arrays to keep track of width and height of each string
    int strwdthLine[4];
    int strhghtLine[4];
    int lineHeight = 30;
    
    int strwdthLevel[4];
    int strhghtLevel[4];
    
};

#endif /* defined(__pumpkinPie__Menu__) */
