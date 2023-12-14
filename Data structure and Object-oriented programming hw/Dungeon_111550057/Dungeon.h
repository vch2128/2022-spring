#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Room.h"


using namespace std;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
    bool run;
public:
    Dungeon():run(true){}
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moving action */
    void handleMovement();

    /* Deal with player's interaction with objects in that room */
    void handleEvent(Object* obj);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction(vector<Object*> obj);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();


    /* Deal with the whole game process */
    void runDungeon();


    void setRun(bool b){run=b;}
    bool getRun(){return run;}
};


#endif // DUNGEON_H_INCLUDED
