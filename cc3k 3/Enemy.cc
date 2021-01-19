#include "Enemy.h"
#include <cmath>
#include <iostream>

bool Enemy::moved = true;
Enemy::Enemy(int atk, int def, int hp, char symbol, std::string race, std::string type) : Character(atk, def, hp, race, type, symbol), duringAttack{false} {}

bool Enemy::getDuringAttack()
{
    return duringAttack;
}

void Enemy::setDuringAttack(bool b)
{
    duringAttack = b;
}

std::string Enemy::attack(std::shared_ptr<Player> player)
{
	std::string msg;
    std::string playerrace = player->getRace();
    /*if (getRace() == "Merchant")
    {
	 std::cout << Merchant::hostile << std::endl;
        if (Merchant::hostile == false)
        {
            return msg;
        }
    }*/
    int chance = rand() % 2;
    double no = 100 * getATK();
    double de = 100 + player->getDEF();
    double res = no / de;
    int dmg = ceil(res);
    // did not miss the attack
    if (chance == 0)
    {
        if (getRace() == "Orcs")
        {
            if (playerrace == "Goblin")
            {
                dmg *= 1.5;
            }
        }
        player->BeAttacked(dmg);
        if (player->getHP() == 0)
        {
            return msg += "You are Dead!!!";
        }
        else
        {
            msg += getRace() + "deals" + std::to_string(dmg) + "damage to PC";
        }
        if (getRace() == "Elf")
        {
            if (player->getRace() != "Drow")
            {
		    int newchance = rand() % 2;
                if (newchance == 0)
                {
                    player->BeAttacked(dmg);
                    if (player->getHP() == 0)
                    {
                        return msg += "You are Dead!!!";
                    }
                    else
                    {
                        msg += "The enemy is an elf, it deals additional" + std::to_string(dmg) + "damage to PC";
                    }
                }
                else
                {
                    msg += "Oops," + getRace() + "miss the attack to PC";
                }
            }
        }
    }
    else
    { // miss the attack
        msg += "Oops," + getRace() + "miss the attack to PC";
    	if (getRace() == "Elf")
        {
            if (player->getRace() != "Drow")
            {
		    int newchance = rand() % 2;
                if (newchance == 0)
                {
                    player->BeAttacked(dmg);
                    if (player->getHP() == 0)
                    {
                        return msg += "You are Dead!!!";
                    }
                    else
                    {
                        msg += "The enemy is an elf, it deals additional" + std::to_string(dmg) + "damage to PC";
                    }
                }
                else
                {
                    msg += "Oops," + getRace() + "miss the attack to PC";
                }
	    }
	}
    }
    std::cout << "Enemy attacking you: " << getRace() << std::endl;
    return msg;
}

Enemy::~Enemy() {}

Human::Human() : Enemy(20, 20, 140, 'H', "Human", "Enemy") {}
Human::~Human() {}

Dwarf::Dwarf() : Enemy(20, 30, 100, 'W', "Dwarf", "Enemy") {}
Dwarf::~Dwarf() {}

Elf::Elf() : Enemy(30, 10, 140, 'E', "Elf", "Enemy") {}
Elf::~Elf() {}

Orc::Orc() : Enemy(30, 25, 180, 'O', "Orc", "Enemy") {}
Orc::~Orc() {}

bool Merchant::hostile = false;
Merchant::Merchant() : Enemy(70, 5, 30, 'M', "Merchant", "Enemy") {}
Merchant::~Merchant() {}

Halfling::Halfling() : Enemy(15, 20, 100, 'L', "Halfling", "Enemy") {}
Halfling::~Halfling() {}

Dragon::Dragon() : Enemy(20, 20, 150, 'D', "Dragon", "Enemy"), hasattacked{false} {}
Dragon::~Dragon() {}
bool Dragon::getHasAttacked() {
	return hasattacked;
}

void Dragon::setHasAttacked(bool b) {
	hasattacked = b;
}
