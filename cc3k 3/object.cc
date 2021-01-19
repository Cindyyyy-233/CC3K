#include "object.h"

Object::Object() {}

Object::~Object() {}

std::string Object::getRace() { return ""; }

std::string Object::getType() { return ""; }

std::string Object::attack(std::shared_ptr<Player> player) { return ""; }

void Object::heal(int n) {}

std::string Object::getEffect() { return ""; }

char Object::getSymbol() { return 0; }

std::shared_ptr<Dragon> Object::getDragon() { return nullptr; }

bool Object::getDuringAttack() { return 0; }

void Object::setDuringAttack(bool) {}

bool Object::getHasAttacked() {return 0;}

void Object::setHasAttacked(bool) {}

void Object::setDragon(std::shared_ptr<Dragon> d) {}
Stair::Stair() : symbol{'\\'}, type{"Stair"} {}

Stair::~Stair() {}

char Stair::getSymbol()
{
    return symbol;
}

std::string Stair::getType()
{
    return type;
}
