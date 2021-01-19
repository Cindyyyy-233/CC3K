#ifndef ITEM_H
#define ITEM_H

#include "object.h"
#include <string>

class Item : public Object
{
    char Symbol;
    std::string type;

public:
    Item(char symbol, std::string type);
    virtual ~Item();
    virtual char getSymbol() override;
    virtual std::string getType() override;
};

#endif