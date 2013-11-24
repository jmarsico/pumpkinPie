//24-780 Engineering Computation 
//Pumpkin Pie Participant Class

#include <iostream>
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

void Participant::Move(double dt)
{
	x += vx*dt;
	y += vy*dt;
	z += vz*dt;

//need environment information so we can have movement limits
	if (x < 0)
	{
		x = 0;
	}
	if(x>100)
	{
		x = 100;
	}
	if(y<0)
	{
		y = 0;
	}
	if (y>100)
	{
		y = 100;
	}
}

void Player::Initialize(void)
{
	state = 1;
	x = 50;	y = 50;	z = 0;
	vx = 0;	vy = 0;	vz = 1;
	width = 5; height = 3; length = 3;
}

void EnemyOne::Initialize(double xx, double yy, double zz) 
{
	state = 1; 
	x = xx;	y = yy;	z = zz;
	vx = 0;	vy = 0; vz = -1;
	width = 3; height = 5; length = 3;
}

void EnemyTwo::Initialize(double xx, double yy, double zz)
{
	state = 1; 
	x = xx;	y = yy;	z = zz;
	vx = 0;	vy = 0; vz = 0;
	width = 3; height = 5; length = 3;
}

void EnemyThree::Initialize(double xx, double yy, double zz)
{
	state = 1; 
	x = xx;	y = yy;	z = zz;
	vx = 0;	vy = 0; vz = 0;
	width = 3; height = 5; length = 3;
}

void EnemyBoss::Initialize(double xx, double yy, double zz)
{
	state = 1;
	x = xx; y = yy; z = zz;
	vx = 0, vy = 0; vz = 0;

}

void Missile::Initialize(double xx, double yy, double zz, double vxx, double vyy, double vzz)
{
	state = 1;
	x = xx; y = yy; z = zz; 
	vx = vxx; vy = vyy; vz = vzz;
}

void Obstacle::Initialize(double xx, double yy, double zz) 
{
	state = 1; 
	x = xx;	y = yy;	z = zz;
	vx = 0;	vy = 0; vz = 0;
	width = 1; height = 1; length = 1;
}

void Player::Fire(void)
{
	int term = 0;
	for(int i = 0; i<5;i++)
	{
		if(pmissile[i].state == 0)
		{
			pmissile[i].Initialize(x, y, z, 0, 0, 3); //vz speed not finalized
			term++;
		}
		if(term >0)
		{
			break;
		}
	}
}

void EnemyOne::Fire(void)
{
	int term = 0;
	for(int i = 0; i<3;i++)
	{
		if(e1missile[i].state == 0)
		{
			e1missile[i].Initialize(x, y, z, 0, 0, -2); //vz speed not finalized
			term++;
		}
		if(term >0)
		{
			break;
		}
	}
}

void EnemyTwo::Fire(void)
{
	int term = 0;
	for(int i = 0; i<3;i++)
	{
		if(e2missile[i].state == 0)
		{
			e2missile[i].Initialize(x, y, z, 0, 0, -2); //vz speed not finalized
			term++;
		}
		if(term >0)
		{
			break;
		}
	}
}

void EnemyThree::Fire(double xx, double yy, double zz)
{
	double xdis = xx-x;
	double ydis = yy-y;
	double zdis = zz-z;

	double vzz = zdis/5 + 1;
	double vxx = xdis/5;
	double vyy = ydis/5;

	int term = 0;
	for(int i = 0; i<3;i++)
	{
		if(e3missile[i].state == 0)
		{
			e3missile[i].Initialize(x, y, z, vxx, vyy, vzz); //vz speed not finalized
			term++;
		}
		if(term >0)
		{
			break;
		}
	}
}

void EnemyBoss::Fire(void)
{
	//haven't determined how the firing function is going to work. Needs to be fun for for the player. 
}

int Participant::getHeight(void)
{
	return height;
}

int Participant::getLength(void)
{
	return length;
}

int Participant::getWidth(void)
{
	return width;
}

ptype Participant::getType(void)
{
}

ptype Player::getType(void)
{
	return PLAYER;
}

ptype EnemyOne::getType(void)
{
	return ENEMYONE;
}

ptype EnemyTwo::getType(void)
{
	return ENEMYTWO;
}

ptype EnemyThree::getType(void)
{
	return ENEMYTHREE;
}

ptype EnemyBoss::getType(void)
{
	return ENEMYBOSS;
}

ptype Obstacle::getType(void)
{
	return OBSTACLE;
}

ptype Empty::getType(void)
{
	return EMPTY;
}