#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "Enemy.h"

#include <string>

class Treasure : public Item
{
    int gold;

public:
    Treasure(char symbol, std::string type,
             int gold);
    ~Treasure() = 0;
    int getGold();
};

class smallhoard : public Treasure
{
public:
    smallhoard();
    ~smallhoard();
};

class normalhoard : public Treasure
{
public:
    normalhoard();
    ~normalhoard();
};

class merchanthoard : public Treasure
{
public:
    merchanthoard();
    ~merchanthoard();
};

class DragonHoard : public Treasure
{
    std::shared_ptr<Dragon> dragon;

public:
    DragonHoard(std::shared_ptr<Dragon> dragon);
    ~DragonHoard();
    virtual std::shared_ptr<Dragon> getDragon() override;
	void setDragon(std::shared_ptr<Dragon>);
};

#endif
