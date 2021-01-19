#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "object.h"
#include <string>

class Character : public Object
{
    int atk, def, hp;
    std::string race, type;
    char symbol;

public:
    Character(int atk, int def, int hp, std::string race, std::string type, char symbol);
    virtual ~Character() = 0; //abstract class
    virtual int getATK();
    virtual int getDEF();
    virtual int getHP();
    virtual std::string getRace();
    virtual std::string getType();
    virtual void setATK(int n);
    virtual void setDEF(int n);
    virtual void setHP(int n);
    virtual void BeAttacked(int n);
	virtual char getSymbol() override;
};

#endif
