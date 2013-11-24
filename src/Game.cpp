
#include "Game.h"

void Game::initialize(void){
    /*initialEnemyPositions = new int[2*numEnemies];
    enemies = new Participant[numEnemies]
    for (int i = 0; i < numEnemies; i++){
        enemies
    }
    */
    
    player.initialize();
    world = new World();
    world.initialize();
    isGameOn = true;
    
}

void Game::update(void){
    // TODO: update missiles
    world.advance();
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
    world.cleanup();
    
}

int Game::moveParticipant(Direction d, Participant p){
    
}

void Game::playerShoot(void){
    
}