#ifndef WORLD_IS_INCLUDED
#define WORLD_IS_INCLUDED

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
	bool IsEmpty(Participant *inhabitant) const;
	void InsertParticipant(Participant participant);
	void RemoveParticipant(void);
};

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
	bool CollisionDetection(void);
	bool CheckMapEnd(void) const;
	const Obstacle* GetObsListPointer(void)const;
	const int GetDispObsStart(void) const;
	const int GetDispObsEnd(void) const;
	const int GetDispEnemyStart(void) const;
	const int GetDispEnemyEnd(void) const;
};

#endif