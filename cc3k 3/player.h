#ifndef _PLAYER_H
#define _PLAYER_H

#include "character.h"
#include <string>

class Player : public Character
{
    const int maxhp;
    int gold;

public:
    Player(char symbol, int max_HP, int gold, int atk, int def, int hp, std::string race, std::string type);
    virtual ~Player() = 0;
    virtual int getMaxHP();
    virtual int getGold();
    virtual void addGold(int n);
    void setGold(int n);
    virtual void heal(int n) override;
    virtual int getBasicATK();
    virtual int getBasicDEF();
};

// Shade: 120 HP, 25 Atk, 25 Def
class Shade : public Player
{
    const int basicAtk = 25;
    const int basicDef = 25;

public:
    Shade();
    virtual int getBasicATK() override;
    virtual int getBasicDEF() override;
    ~Shade();
};

// Drow: 150 HP, 25 Atk, 15 Def, magnified potion effect by 1.5
class Drow : public Player
{
    const int basicAtk = 25;
    const int basicDef = 15;

public:
    Drow();
    virtual int getBasicATK() override;
    virtual int getBasicDEF() override;
    ~Drow();
};

// Vamprie: 50 HP, 25 Atk, 25 Def, heal 5 HP every successful attack and no MAX_HP
class Vampire : public Player
{
    const int basicAtk = 25;
    const int basicDef = 25;

public:
    Vampire();
    ~Vampire();
    virtual int getBasicATK() override;
    virtual int getBasicDEF() override;
    virtual void heal(int n) override;
};

// Troll: 120 HP, 25 Atk, 15 Def, regain 5 HP every turn
class Troll : public Player
{
    const int basicAtk = 25;
    const int basicDef = 15;

public:
    Troll();
    virtual int getBasicATK() override;
    virtual int getBasicDEF() override;
    ~Troll();
};

// Goblin: 110 HP, 15 Atk, 20 Def, get 5 gold every kill
class Goblin : public Player
{
    const int basicAtk = 15;
    const int basicDef = 20;

public:
    Goblin();
    virtual int getBasicATK() override;
    virtual int getBasicDEF() override;
    ~Goblin();
};

#endif
