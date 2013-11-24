//
//  Game.h
//  pumpkinPie
//
//  Created by Adam Jung on 11/23/13.
//
//

#ifndef __pumpkinPie__Game__
#define __pumpkinPie__Game__

#include "Participant.cpp"
#include "ofMain.h"
#include "WorldBox.h"

enum Direction{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Game{
public:
    Game(int level);
    ~Game(void);
    
    void cleanUp(void);
    
    // initializes the fields (mui importante) and starts game
    void initialize(int level);
    
    // updates by advancing position of enemies, missiles, and the displayed section
    void update(void);
    
    // draws the player, enemies, obstacles, and everything else that needs to be seen
    void draw(void);
    
    // ends game, sets flag to false, then cleans up memory
    void endGame(void);
    
    // used primarily for player movement
    int moveParticipant(Direction d, Participant p);
    void playerShoot(void);
    
private:
    int difficulty;
    Player player;
    
    WorldBox world;
    bool isGameOn;

    // enemy variables
    
    //static int numEnemies = 1;
    //int * initialEnemyPositions;
    //Participant * enemies;
    
    //EnemyBoss boss;
};

#endif /* defined(__pumpkinPie__Game__) */
