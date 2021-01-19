#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"

class Potion : public Item
{
private:
    std::string effect;

public:
    static bool usedRH;
    static bool usedBA;
    static bool usedBD;
    static bool usedPH;
    static bool usedWA;
    static bool usedWD;
    Potion(std::string effect);
    ~Potion();
    std::string getEffect();
    std::string getDescription();
};

#endif
