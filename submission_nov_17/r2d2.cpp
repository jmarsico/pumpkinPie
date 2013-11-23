//
//  r2d2.cpp
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/16/13.
//
//

#include "r2d2.h"


r2d2::r2d2()
{
    initialize();
}

void r2d2::initialize(void)
{
    x = cylRad*2 + 30;
    y = (ofGetHeight()- cylHei - 50);
    z = 0;
    state = 1;
    
    
    cylinder.set(cylRad, cylHei, 20, 13);
    sphere.set(40, 20);
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .85) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
	material.setShininess( 120 );
    // the light highlight of the material //
	material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    
    texture.loadImage("of.png");
    texture.getTextureReference().setTextureWrap( GL_REPEAT, GL_REPEAT );
}

void r2d2::draw(void)
{
     
    
    pointLight.setPosition((ofGetWidth()*.5)+ cos(ofGetElapsedTimef()*.5)*(ofGetWidth()*.3), ofGetHeight()/2, 500);
    
    ofEnableLighting();
    pointLight.enable();
    
    ofEnableDepthTest();
    
    material.begin();
    
    
    // get all the faces from the icoSphere, handy when you want to copy
    // individual vertices or tweak them a little ;)
    vector<ofMeshFace> triangles = cylinder.getMesh().getUniqueFaces();
    
    
    //draw sphere of r2d2
    ofFill();
    ofSetColor(100,100,100);
    sphere.setPosition(x, y - 60, z);
    sphere.draw();
    
    
    //draw wireframe of sphere
    ofNoFill();
    ofSetColor(0, 0, 0);
    sphere.setScale(1.01f);
    //sphere.drawWireframe();
    sphere.setScale(1.0f);
    
    
    //draw cylinder of r2d2
    ofFill();
    ofSetColor(255, 255, 255);
    cylinder.setPosition(x, y, z);    //cylinder.rotate(1, 1.0, 0.0, 0.0);
    cylinder.draw();
 
    
   
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    cylinder.setScale(1.01f);
    //cylinder.drawWireframe();
    cylinder.setScale(1.0f);
    
    

    
    
    
}