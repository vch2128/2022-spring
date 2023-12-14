#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"
#include "Chest.h"
#include "GameCharacter.h"
#include "Object.h"
#include "Room.h"
#include "Skill.h"
#include "Weapon.h"


using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    return 0;
}
