//
//  Menu.cpp
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/16/13.
//
//
//

#include "Menu.h"


Menu::Menu()
{
    initialize();
}



void Menu::initialize(void)
{
    ofLog() << "menu initialized" ;
    ofBackground(0, 0, 0, 255);
    
    //load the title font and set up spacing for the font
    GalaxyAlt30.loadFont("SF Distant Galaxy Alternate.ttf", 30);
    GalaxyAlt30.setLetterSpacing(1.04);
    GalaxyAlt30.setLineHeight(34.0f);
    
    //load the title font and set up spacing for the font
    GalaxyAlt80.loadFont("SF Distant Galaxy Alternate.ttf", 80);
    GalaxyAlt80.setLetterSpacing(1.3);
    GalaxyAlt80.setLineHeight(34.0f);
    
    //load and set up font for menu items
    GalaxyAlt14.loadFont("SF Distant Galaxy Outline.ttf", 14);
    GalaxyAlt14.setLetterSpacing(1.037);
    GalaxyAlt14.setLineHeight(34.0f);
    
    
    //set up variables for width and height of each line
    for(int i = 0; i < 4; i++)
    {
        strwdthLine[i] = GalaxyAlt30.stringWidth(line[i]);
        strhghtLine[i] = GalaxyAlt30.stringHeight(line[i]);
    }
    
    //set up variables for width and height of each level
    for(int i = 0; i < 4; i++)
    {
        strwdthLevel[i] = GalaxyAlt14.stringWidth(level[i]);
        strhghtLevel[i] = GalaxyAlt14.stringHeight(level[i]);
    }
    
        
    
        
    y = ofGetHeight() + 200;        //initialize location of scrolling intro
    state = 1;                      // state 0 is for when intro text scrolls
    selection = 0;                  //selection 0 means nothing has been selected

}
    
    

void Menu::update(void)
{
    
    for(int i = 0; i < numStars; i++)
    {
        stars[i].update(i);
    }
    //if state is 0, run through the scrolling letters sequence
    if(state == 0)
    {
        if(y > - 200)
        {
            y = y - 1;
        }
        else
        {
            state = 1;              //when it's finished, open the menue
        }
    }
    
    
}



void Menu::draw(void)
{
        
    ofSetColor(255,191,64);
    
    //state 0 is for scrolling intro
    if(state == 0)                     
    {
        for(int i = 0; i < 4; i++)
        {
            GalaxyAlt30.drawString(line[i], ofGetWidth()/2-strwdthLine[i]/2, y + i*strhghtLine[i]+lineHeight*i);
        }
    }   
    
    //state 1 is for main menu
    if(state == 1)                      
    {
        R2d2.draw();
        ofSetColor(255,191,64);
        for(int i = 0; i < 4; i++)
        {
            GalaxyAlt14.drawString(level[i], ofGetWidth()/2 - strwdthLevel[i]/2, 300 + i*40+40);
        }
        
        GalaxyAlt80.drawString("STAR WARS", ofGetWidth()/2 - GalaxyAlt80.stringWidth("STAR WARS")/2, 200);
    }
    
    for(int i = 0; i < numStars; i++)
    {
        stars[i].draw();
    }

}



//call thsi function to get the newest selection ID (zero = "resume")
int Menu::getSelection(void)
{
    ofLog() <<"getSelection Called... Selection is: " << selection;
    return selection;
}


//call this function in the mousePressed() function of testApp.cpp
//it will switch level selection based on where you click
void Menu::select(const int mX, const int mY)
{
    
    //"level 1"
    if(mX > 450 && mY >320 && mY < 355 && mX < 580)
    {
        selection = 1;
        ofLog() << "MenuSelection: " << selection;
    }
    
    //"level 2"
    else if(mX > 450 && mY >355 && mY < 395 && mX < 580)
    {
        selection = 2;
        ofLog() << "MenuSelection: " << selection;
    }
    
    //"level 3"
    else if(mX > 450 && mY > 395 && mY < 435 && mX < 580)
    {
        selection = 3;
        ofLog() << "MenuSelection: " << selection;
    }
    
    //"resume"
    else if(mX > 450 && mY >435 && mY < 475 && mX < 580)
    {
        selection = 0;
        ofLog() << "MenuSelection: " << selection;
    }
    else
    {
        selection = -1;
    }

    
}







