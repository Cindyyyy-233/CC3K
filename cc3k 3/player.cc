#include "player.h"
#include <iostream>

Player::Player(char symbol, int maxhp, int gold, int atk, int def, int hp, std::string race, std::string type) : Character(atk, def, hp, race, type, symbol), maxhp{maxhp}, gold{gold} {}

Player::~Player() {}

int Player::getMaxHP()
{
    return maxhp;
}

int Player::getGold()
{
    return gold;
}

void Player::addGold(int n)
{
    gold += n;
}

void Player::setGold(int n)
{
	gold = n;
}

void Player::heal(int n)
{
    setHP(getHP() + n);
    if (getHP() > maxhp)
    {
        setHP(maxhp);
    }
}

int Player::getBasicATK() {return 0;}

int Player::getBasicDEF() {return 0;}

Shade::Shade() : Player('@', 125, 0, 25, 25, 125, "Shade", "Player") {}
Shade::~Shade() {}

int Shade::getBasicATK()
{
    return basicAtk;
}

int Shade::getBasicDEF()
{
    return basicDef;
}

Drow::Drow() : Player('@', 150, 0, 25, 15, 150, "Drow", "Player"){};
Drow::~Drow() {}

int Drow::getBasicATK()
{
    return basicAtk;
}

int Drow::getBasicDEF()
{
    return basicDef;
}

Vampire::Vampire() : Player('@', 50, 0, 25, 25, 50, "Vampire", "Player"){};
Vampire::~Vampire() {}
void Vampire::heal(int n)
{ //no max health
    setHP(getHP() + n);
}

int Vampire::getBasicATK()
{
    return basicAtk;
}

int Vampire::getBasicDEF()
{
    return basicDef;
}

Troll::Troll() : Player('@', 120, 0, 25, 15, 120, "Troll", "Player"){};
Troll::~Troll() {}
int Troll::getBasicATK()
{
    return basicAtk;
}

int Troll::getBasicDEF()
{
    return basicDef;
}

Goblin::Goblin() : Player('@', 110, 0, 15, 20, 110, "Goblin", "Player"){};
Goblin::~Goblin() {}
int Goblin::getBasicATK()
{
    return basicAtk;
}

int Goblin::getBasicDEF()
{
    return basicDef;
}
