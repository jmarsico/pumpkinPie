#include "xwing.h"

//--------------------------------------------------------------

Xwing::Xwing()
{
    Initialize();
}


void Xwing::Initialize(void)
{
	x = ofGetWidth()/2;
	y = ofGetHeight()/2;
	z = 0;

	pbody.set(10, 5, 30);	
	for(int i = 0; i<4; i++)
	{
		pcyl[i].set(4, 7.5);
		pcyl[i].tilt(90);
	}
	for(int i =4; i <8; i++)
	{
		pcyl[i].set(2.5,15);
		pcyl[i].tilt(90);
	}
	for(int i =0; i<4;i++)
	{
		pwings[i].set(23.6,1,7.5);
	}
	pwings[0].roll(32);
	pwings[2].roll(32);
	pwings[1].roll(-32);
	pwings[3].roll(-32);

}

void Xwing::SetPosition(double xx, double yy, double zz)
{
	x = xx;
	y = yy; 
	z = zz;
}

void Xwing::Draw(void){
	ofEnableDepthTest();

	pbody.setPosition(x,y, z);
	pcyl[0].setPosition(x+5,y+2.5,z+11.25);
	pcyl[1].setPosition(x-5,y+2.5,z+11.25);
	pcyl[2].setPosition(x+5,y-2.5,z+11.25);
	pcyl[3].setPosition(x-5,y-2.5,z+11.25);
	pcyl[4].setPosition(x+25, y+15, z+7.5);
	pcyl[5].setPosition(x-25, y+15, z+7.5);
	pcyl[6].setPosition(x+25, y-15, z+7.5);
	pcyl[7].setPosition(x-25, y-15, z+7.5);
	pwings[0].setPosition(x-15,y-8.75,z+7.5);
	pwings[1].setPosition(x+15,y-8.75,z+7.5);
	pwings[2].setPosition(x+15,y+8.75,z+7.5);
	pwings[3].setPosition(x-15,y+8.75,z+7.5);


   
	pbody.draw(); 
	for(int i = 0; i<8; i++)
	{
		
		pcyl[i].draw();
	}
	for(int i = 0; i<4;i++)
	{
		pwings[i].draw();
	}
	ofDisableDepthTest();
	
}

