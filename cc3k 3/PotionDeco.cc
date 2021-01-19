#include "PotionDeco.h"

PotionDeco::PotionDeco(std::shared_ptr<Player> p) : Player(0, 0, 0, 0, 0, 0, "", ""), player{p} {}

PotionDeco::~PotionDeco(){};

void PotionDeco::setATK(int value)
{
    int atk = player->getATK();
    if (atk + value <= 0)
    {
        player->setATK(0);
    }
    else
    {
        player->setATK(atk + value);
    }
}

void PotionDeco::setDEF(int value)
{
    int def = player->getDEF();
    if (def + value <= 0)
    {
        player->setDEF(0);
    }
    else
    {
        player->setDEF(def + value);
    }
}

void PotionDeco::setHP(int value)
{
    int hp = player->getHP();
    if ((player->getRace() == "Vampire" ||
         player->getMaxHP() >= hp + value) &&
        hp + value >= 0)
    {
        player->setHP(hp + value);
    }
    else
    {
        if (value >= 0)
        {
            player->setHP(player->getMaxHP());
        }
        else
        {
            player->setHP(0);
        }
    }
}
