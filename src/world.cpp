#include <stdio.h>

/////////////////////////////////////////////////////
enum pType { EMPTY };

class Participant
{
protected:
	int width, height, length;

public:
	int x, y, z;

	pType getType(void);
	int getWidth(void);
	int getHeight(void);
	int getLength(void);
};

class Empty : public Participant
{
};

class Obstacle : public Participant
{
};

class Player : public Participant
{
};

class Enemy : public Participant
{
};
////////////////////////////////////////////////////

enum Level { EASY, NORMAL, HARDCORE };

class WorldCell
{
protected:
	Participant* inhabitants[2];

public:
	WorldCell();
	~WorldCell();
	void CleanUp(void);
	void Initialize(void);
	bool IsCellEmpty(Participant *inhabitant) const; // checks if specific cell in inhabitants is of Empty class
	bool IsFull(void) const; // checks if both cells in inhabitants are not of Empty class
	void InsertParticipant(Participant participant);
	void RemoveParticipant(void);
};

WorldCell::WorldCell()
{
	inhabitants[0] = NULL;
	inhabitants[1] = NULL;
}

WorldCell::~WorldCell()
{
	CleanUp();
}

void WorldCell::CleanUp(void) // check this
{
	if (NULL!=inhabitants[0])
	{
		delete inhabitants[0];
		inhabitants[0] = NULL;
	}

	if (NULL!=inhabitants[1])
	{
		delete inhabitants[1];	
		inhabitants[1] = NULL;
	}
}

void WorldCell::Initialize(void)
{
	inhabitants[0] = new Empty;
	inhabitants[1] = new Empty;
}

bool WorldCell::IsCellEmpty(Participant *inhabitant) const
{
	if (inhabitant->getType()==EMPTY)
	{
		return true;
	}
	return false;
}

bool WorldCell::IsFull(void) const
{
	if (IsCellEmpty(inhabitants[0]) || IsCellEmpty(inhabitants[1]))
	{
		return false;
	}
	return true;
}

void WorldCell::InsertParticipant(Participant participant)
{
	if (IsCellEmpty(inhabitants[0]))
	{
		delete inhabitants[0]; // need this?
		inhabitants[0] = &participant;
	}
	else
	{
		delete inhabitants[1]; // need this?
		inhabitants[1] = &participant;
	}
}

void WorldCell::RemoveParticipant(void)
{
	if (inhabitants[0]->getType()!=EMPTY)
	{
		delete inhabitants[0]; // need this?
		inhabitants[0] = new Empty;
	}

	if (inhabitants[1]->getType()!=EMPTY)
	{
		delete inhabitants[1]; //need this?
		inhabitants[1] = new Empty;
	}
}

class World
{
protected:
	const int nObstacles = 10;
	const int dispSectSize = 100;
	int totalZ;
	int dispObstacleStart, dispObstacleEnd, dispEnemyStart, dispEnemyEnd, zCounter;
	WorldCell ***dispSect;
	Obstacle obstacles[nObstacles]; // list should be sorted by z position

	void GenerateNewDisp(void);
	void InitializeEntities(void);
	void PopulateStartDisp(void);

public:
	World();
	World(Level level);
	~World();
	void CleanUp(void);
	void Generate(Level level);
	void InsertParticipant(Participant participant);
	void AdvanceDispSect(void);
	bool CollisionDetection(Player player);
	bool CheckMapEnd(void) const;
	const Obstacle* GetObsListPointer(void)const;
	const int GetDispObsStart(void) const;
	const int GetDispObsEnd(void) const;
	const int GetDispEnemyStart(void) const;
	const int GetDispEnemyEnd(void) const;
};

World::World()
{
	dispSect = NULL;
}

World::World(Level level)
{
	dispSect = NULL;
	Generate(level);
}	

World::~World()
{
	CleanUp();
}

void World::CleanUp(void) // check this
{
	for (int i=0; i<dispSectSize; ++i)
	{
		for (int j=0; j<dispSectSize; ++j)
		{
			delete [] dispSect[i][j];
		}
		delete [] dispSect[i];
	}
	delete [] dispSect;

	dispSect = NULL;
}

void World::GenerateNewDisp(void)
{
	dispSect = new WorldCell** [dispSectSize];
	for (int i=0; i<dispSectSize; i++)
	{
		dispSect[i] = new WorldCell* [dispSectSize];
		for (int j=0; j<dispSectSize; j++)
		{
			dispSect[i][j] = new WorldCell [dispSectSize];
		}
	}
}

void World::InitializeEntities(void)
{
	// initialize all WorldCells to Empty to start
	for (int i=0; i<dispSectSize; ++i)
	{
		for (int j=0; j<dispSectSize; ++j)
		{
			for (int k=0; k<dispSectSize; ++k)
			{
				dispSect[i][j][k].Initialize();
			}
		}
	}

	// initialize positions of obstacles
	for (int ind=0; ind<nObstacles; ++ind)
	{
		obstacles[ind].x = 10*ind;
		obstacles[ind].y = 10*ind;
		obstacles[ind].z = 20*ind+10;
	}
}

void World::PopulateStartDisp(void)
{
	// inserting obstacles that will be seen at the start of the level
	for (int i=0; i<nObstacles; ++i)
	{
		if (obstacles[i].z>0 && obstacles[i].z<dispSectSize)
		{
			InsertParticipant(obstacles[i]);
		}
		else
		{
			dispObstacleEnd = i-1;
			break;
		}
	}
}

void World::Generate(Level level)
{
	switch (level)
	{
	case NORMAL:
		totalZ = 300;	
		break;
	case HARDCORE:
		totalZ = 400;
		break;
	default: // default is easy mode
		totalZ = 200;
	}

	dispObstacleStart = 0;
	dispEnemyStart = 0;
	zCounter = dispSectSize;

	GenerateNewDisp();
	InitializeEntities();
	PopulateStartDisp();
}

void World::InsertParticipant(Participant participant)
{
	int cx, cy, cz, sizeX, sizeY, sizeZ;
	
	sizeX = participant.getWidth()/2;
	sizeY = participant.getHeight()/2;
	sizeZ = participant.getLength()/2;

	cx = participant.x;
	cy = participant.y;
	cz = participant.z;

	for (int i=(cx-sizeX); i<(cx+sizeX+1); ++i)
	{
		for (int j=(cy-sizeY); j<(cy+sizeY+1); ++j)
		{
			// if statements used to check if a Partcipant is partially in the displayed world in the z-direction
			// Participant is in displayed world as long as its center is
			// if the Participant's size causes part of it to be out of the displayed world, only part of it will be stored
			if ((cz-sizeZ)<0)
			{
				for (int k=0; k<(cz+sizeZ+1); ++k)
				{
					dispSect[i][j][k].InsertParticipant(participant);
				}
			}
			else if ((cz+sizeZ)>dispSectSize)
			{
				for (int k=(cz-sizeZ); k<dispSectSize; ++k)
				{
					dispSect[i][j][k].InsertParticipant(participant);
				}
			}
			else
			{
				for (int k=(cz-sizeZ); k<(cz+sizeZ+1); ++k)
				{
					dispSect[i][j][k].InsertParticipant(participant);
				}
			}
		}
	}
}

void World::AdvanceDispSect(void)
{
	int obsState = 0;

	++zCounter;

	// remove all obstacles in the displayed world
	for (int i=dispObstacleStart; i<(dispObstacleEnd+1); ++i)
	{
		dispSect[obstacles[i].x][obstacles[i].y][obstacles[i].z].RemoveParticipant();
	}

	// insert obstacles that should be displayed into the displayed world
	// edit dispObstacleStart and dispObstacleEnd to identify which obstacles are being displayed
	for (int i=dispObstacleStart; i<nObstacles; ++i)
	{
		--obstacles[i].z;

		if (obsState==0)
		{
			if (obstacles[i].z>0 && obstacles[i].z<dispSectSize)
			{
				obsState = 1;
				InsertParticipant(obstacles[i]);
				dispObstacleStart = i;
			}
		}
		else if (obsState==1)
		{
			if (obstacles[i].z>0 && obstacles[i].z<dispSectSize)
			{
				InsertParticipant(obstacles[i]);
			}
			else
			{
				obsState = 0;
				dispObstacleEnd = i-1;
				break;
			}
		}
	}
}

bool World::CollisionDetection(Player player)
{
	int cx, cy, cz, sizeX, sizeY, sizeZ;
	
	sizeX = player.getWidth()/2;
	sizeY = player.getHeight()/2;
	sizeZ = player.getLength()/2;

	cx = player.x;
	cy = player.y;
	cz = player.z;

	for (int i=(cx-sizeX); i<(cx+sizeX+1); ++i)
	{
		for (int j=(cy-sizeY); j<(cy+sizeY+1); ++j)
		{
			for (int k=(cz-sizeZ); k<(cz+sizeZ+1); ++k)
			{
				if (dispSect[i][j][k].IsFull())
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool World::CheckMapEnd(void) const
{
	if (zCounter==totalZ)
	{
		return true;
	}
	return false;
}

const Obstacle* World::GetObsListPointer(void) const
{
	return obstacles;
}

const int World::GetDispObsStart(void) const
{
	return dispObstacleStart;
}

const int World::GetDispObsEnd(void) const
{
	return dispObstacleEnd;
}

const int World::GetDispEnemyStart(void) const
{
	return dispEnemyStart;
}

const int World::GetDispEnemyEnd(void) const
{
	return dispEnemyEnd;
}