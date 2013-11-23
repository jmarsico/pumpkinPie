//
//  worldBox.cpp
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/23/13.
//
//

#include "WorldBox.h"


WorldBox::WorldBox()
{
    initialize();
}

void WorldBox::initialize(void)
{
    width = ofGetWidth();
    height = ofGetHeight();
    worldCell.set(width*.01, width*.01, width*.01);
    
    boxx = 0;
    boxy = 0;
    boxz = 0;
    
    bWireframe = true;
    
    world.set(1000,1000,1000);
    

    
}

void WorldBox::draw(void)
{
    double width = ofGetWidth();
    double height = ofGetHeight();
    
	ofEnableDepthTest();
	ofSetFrameRate(60);
    
    
	worldCell.setPosition(boxx, boxy, boxz);
    world.setPosition(width/2, height/2, boxz);
    
	//vector<ofMeshFace> triangles = world.getMesh().getUniqueFaces();
    //ofSetColor(255,0,0);
    //world.draw();
    ofSetColor(255,255,255);
    world.drawWireframe();
    
    
    
    ofSetColor(255,0,0);
    worldCell.drawWireframe();
    
	ofDisableDepthTest();
	
}
