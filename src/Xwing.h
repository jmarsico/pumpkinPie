//
//X-wing Class

#ifndef __pumpkinPie__Xwing__
#define __pumpkinPie__Xwing_

#include <iostream>
#include "ofMain.h"
#pragma once

class Xwing
{
public: 
	double x, y, z;
    
    Xwing();

	void Draw(void);
	void Initialize(void);
	void SetPosition(double xx, double yy, double zz);

	ofBoxPrimitive pbody;
	ofCylinderPrimitive pcyl[8];
	ofBoxPrimitive pwings[4];
    
    ofLight pointLight;
    ofMaterial material;


	vector<ofMeshFace> triangles;

};

#endif
