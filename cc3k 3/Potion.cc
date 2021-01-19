#include "Potion.h"

#include <string>

bool Potion::usedPH = false;

bool Potion::usedRH = false;

bool Potion::usedBA = false;

bool Potion::usedBD = false;

bool Potion::usedWA = false;

bool Potion::usedWD = false;

Potion::Potion(std::string effect) : Item{'P', "potion"}, effect{effect} {}

Potion::~Potion() {}

std::string Potion::getEffect()
{
    return effect;
}

std::string Potion::getDescription()
{
    if (effect == "RH")
    {
        if (usedRH)
        {
            return "Restore Health potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else if (effect == "BA")
    {
        if (usedBA)
        {
            return "Boost Atk potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else if (effect == "BD")
    {
        if (usedBD)
        {
            return "Boost Def potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else if (effect == "PH")
    {
        if (usedPH)
        {
            return "Poison health potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else if (effect == "WA")
    {
        if (usedWA)
        {
            return "Wound Atk potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else if (effect == "WD")
    {
        if (usedWD)
        {
            return "Wound Def potion";
        }
        else
        {
            return "unknown potion";
        }
    }
    else
    {
        return "unknown potion";
    }
}
