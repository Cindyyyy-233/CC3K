#ifndef DECO_H
#define DECO_H

#include <memory>
#include "player.h"
#include "PotionDeco.h"

class AtkDeco : public PotionDeco
{
public:
    AtkDeco(std::shared_ptr<Player> p);
    ~AtkDeco();
    virtual void setATK(int n) override;
};

class DefDeco : public PotionDeco
{
public:
    DefDeco(std::shared_ptr<Player> p);
    ~DefDeco();
    virtual void setDEF(int n) override;
};

class HpDeco : public PotionDeco
{
public:
    HpDeco(std::shared_ptr<Player> p);
    ~HpDeco();
    virtual void setHP(int n) override;
};

#endif