#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include <vector>
#include <memory>

class Player;
class Dragon;

class Object
{
public:
    Object();
    virtual ~Object() = 0; //abstract class
    virtual char getSymbol();
    virtual std::string getRace();
    virtual std::string getType();
    virtual std::string attack(std::shared_ptr<Player> player);
    virtual std::shared_ptr<Dragon> getDragon();
    virtual void heal(int n);
    virtual std::string getEffect();
    virtual bool getDuringAttack();
    virtual void setDuringAttack(bool);
    virtual bool getHasAttacked();
    virtual void setHasAttacked(bool);
	virtual void setDragon(std::shared_ptr<Dragon>);
};

class Stair : public Object
{
    char symbol;
    std::string type;

public:
    Stair();
    ~Stair();
    virtual char getSymbol();
    virtual std::string getType();
};

#endif
