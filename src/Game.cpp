
#include "Game.h"

Game::Game(int level){
    /*
    
    */
<<<<<<< HEAD
    
    initialize(difficulty);
=======
    difficulty = level;
    player.
    initialize(level);

>>>>>>> 5f1fee16e1c2b58a0dfee0a16a4d83b2c9c1e9c9
}

Game::~Game(void){
    cleanUp();
}

void Game::cleanUp(void){
    
}

void Game::initialize(int level){
    /*
    
    initialEnemyPositions = new int[2*numEnemies];
    enemies = new Participant[numEnemies]
    for (int i = 0; i < numEnemies; i++){
        enemies
    }
    */
    
    difficulty = level;
    player.initialize();
    world = new WorldBox();
    world.initialize();
    isGameOn = true;
    
}

void Game::update(void){
    // TODO: update missiles
    worldBox.advance();
    // check for a collision between player and an obstacle
    
}

void Game::draw(void){
    // TODO: draw enemies
    Obstacle obstacles[] = world.getVisibleObstacles();
    
    /*
    EnemyOne enemyOnez[] = world.getVisibleEnemyOne();
    EnemyTwo enemyTwoz[] = world.getVisibleEnemyTwo();
    EnemyThree enemyThreez[] = world.getVisibleEnemyThree();
    */
    
    
}

void Game::endGame(void){
    // TODO: cleanup world, enemies, initialEnemyPositions
    isGameOn = false;
    worldBox.cleanup();
    
}

int Game::moveParticipant(Direction d, Participant p){
    
}

void Game::playerShoot(void){
    
}