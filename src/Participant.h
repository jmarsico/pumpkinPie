//
//  Participant.h
//  pumpkinPie
//
//  Created by Jakob Marsico on 11/24/13.
//
//

#ifndef pumpkinPie_Participant_h
#define pumpkinPie_Participant_h

#include <iostream>
#include "ofMain.h"
#pragma once

#include <math.h>

enum ptype
{
	PLAYER,
	MISSILE,
	ENEMYONE,
	ENEMYTWO,
	ENEMYTHREE,
	ENEMYBOSS,
	OBSTACLE,
	EMPTY
};

class Participant
{
protected:
	double width, height, length;
    
public:
	double x, y, z, vx, vy, vz;
	int state, health;
    
	void Move(double dt);
	int getWidth(void);
	int getHeight(void);
	int getLength(void);
	virtual ptype getType(void);
};

class Missile : public Participant
{
protected:
public:
	
	void Initialize(double xx, double yy, double zz, double vxx, double vyy, double vzz);
	void Draw(void);
	ptype getType(void);
};

class Player : public Participant
{
protected:
	Missile pmissile[5];
    
public:
	void Initialize(void);
	void Fire(void);
	ptype getType(void);
    
};

class EnemyOne : public Participant
{
protected:
	Missile e1missile[3];
    
public:
    
	void Initialize(double xx, double yy, double zz);
	void Fire(void);
	ptype getType(void);
};

class EnemyTwo : public Participant
{
protected:
	Missile e2missile[3];
    
public:
    
	void Initialize(double xx, double yy, double zz);
	void Fire(void);
	ptype getType(void);
};

class EnemyThree : public Participant
{
protected:
	Missile e3missile[3];
    
public:
    
	void Initialize(double xx, double yy, double zz);
	void Fire(double xx, double yy, double zz);
	ptype getType(void);
};

class EnemyBoss : public Participant
{
protected:
	Missile ebmissile[25];
    
public:
    
	void Initialize(double xx, double yy, double zz);
	void Fire(void);
	ptype getType(void);
};

class Obstacle : public Participant
{
protected:
    
public:
	void Initialize(double xx, double yy, double zz);
	ptype getType(void);
};

class Empty : public Participant
{
public:
	ptype getType(void);
};


#endif
