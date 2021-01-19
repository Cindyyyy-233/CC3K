#include "item.h"

#include <iostream>
#include <string>

Item::Item(char symbol, std::string t) : Symbol{symbol}, type{t} {}

Item::~Item(){}

char Item::getSymbol()
{
    return Symbol;
}

std::string Item::getType()
{
    return type;
}