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

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		double px, py, pz;

		ofBoxPrimitive pbody;
		ofCylinderPrimitive pcyl[8];
		ofBoxPrimitive pwings[4];

		vector<ofMeshFace> triangles;
};
