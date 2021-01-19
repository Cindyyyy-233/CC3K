#include "character.h"

Character::Character(int atk, int def, int hp, std::string race, std::string type, char symbol) : Object(), atk{atk}, def{def}, hp{hp}, race{race}, type{type}, symbol{symbol} {}

Character::~Character() {}

int Character::getATK()
{
    return atk;
}

int Character::getDEF()
{
    return def;
}

int Character::getHP()
{
    return hp;
}

std::string Character::getRace()
{
    return race;
}

std::string Character::getType()
{
    return type;
}

void Character::setATK(int n)
{
    atk = n;
}

void Character::setDEF(int n)
{
    def = n;
}

void Character::setHP(int n)
{
    hp = n;
}

void Character::BeAttacked(int n)
{
    hp -= n;
    if (hp < 0)
    { //player dead
        hp = 0;
    }
}

char Character::getSymbol() {
	return symbol;
}
