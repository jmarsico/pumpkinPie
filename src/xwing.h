//
//X-wing Class

#ifndef __pumpkinPie__r2d2__
#define __pumpkinPie__r2d2__

#include <iostream>
#include "ofMain.h"
#pragma once

class Xwing
{
public: 
	double x, y, z;


	void Draw(void);
	void Initialize(void);
	void SetPosition(double xx, double yy, double zz);

	ofBoxPrimitive pbody;
	ofCylinderPrimitive pcyl[8];
	ofBoxPrimitive pwings[4];

	vector<ofMeshFace> triangles;

};

#endif
