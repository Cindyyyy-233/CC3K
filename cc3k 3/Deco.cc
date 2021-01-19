#include "Deco.h"

AtkDeco::AtkDeco(std::shared_ptr<Player> p) : PotionDeco{p} {}

AtkDeco::~AtkDeco() {}

void AtkDeco::setATK(int value)
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

DefDeco::DefDeco(std::shared_ptr<Player> p) : PotionDeco{p} {}

DefDeco::~DefDeco() {}

void DefDeco::setDEF(int value)
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

HpDeco::HpDeco(std::shared_ptr<Player> p) : PotionDeco{p} {}

HpDeco::~HpDeco() {}

void HpDeco::setHP(int value)
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