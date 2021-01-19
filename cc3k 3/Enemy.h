#ifndef _ENEMY_H
#define _ENEMY_H

#include "character.h"
#include "player.h"
#include <cstdlib>
#include <string>

class Enemy : public Character
{
public:
    static bool moved;
    bool duringAttack;
    Enemy(int atk, int def, int hp, char symbol, std::string race, std::string type);
    virtual bool getDuringAttack() override;
    virtual void setDuringAttack(bool) override;
    virtual ~Enemy() = 0;
    virtual std::string attack(std::shared_ptr<Player> player) override;
};

// Human: 140 HP, 20 Atk, 20 Def, 2 golds * 2
class Human : public Enemy
{
public:
    Human();
    ~Human();
};

// Dwarf: 100 HP, 20 Atk, 30 Def, Vampire -5 HP when attacking Dwarf
class Dwarf : public Enemy
{
public:
    Dwarf();
    ~Dwarf();
};

// Elf: 140 HP, 30 Atk, 10 Def, attack twice except Drow
class Elf : public Enemy
{
public:
    Elf();
    ~Elf();
};

// Orc: 180 HP, 30 Atk, 25 Def, 50% more dmg to goblin
class Orc : public Enemy
{
public:
    Orc();
    ~Orc();
};

class Merchant : public Enemy
{
public:
    static bool hostile;
    Merchant();
    ~Merchant();
};

class Halfling : public Enemy
{
public:
    Halfling();
    ~Halfling();
};

class Dragon : public Enemy
{
    bool hasattacked;
public:
    Dragon();
    ~Dragon();
    virtual bool getHasAttacked() override;
    virtual void setHasAttacked(bool) override;
};

#endif
