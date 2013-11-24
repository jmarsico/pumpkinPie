#ifndef WORLD_IS_INCLUDED
#define WORLD_IS_INCLUDED

#include "Participant.h"
#include <stdio.h>

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
	bool IsCellEmpty(Participant *inhabitant) const;
	void InsertParticipant(Participant participant);
	void RemoveParticipant(void);
    bool IsFull(void) const;
};

class World
{
protected:
	static const int nObstacles = 10;
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

#endif