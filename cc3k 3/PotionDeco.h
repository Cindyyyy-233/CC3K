#ifndef POTIONDECO_H
#define POTIONDECO_H

#include "player.h"
#include <memory>

class PotionDeco : public Player
{
protected:
    std::shared_ptr<Player> player;

public:
    PotionDeco(std::shared_ptr<Player> player);
    ~PotionDeco();
    virtual void setATK(int n);
    virtual void setDEF(int n);
    virtual void setHP(int n);
};

#endif