#include "cell.h"

Cell::Cell(size_t r, size_t c, size_t chamberNum, Type t) : info{t, r, c, chamberNum}, ob{nullptr}  {}

Cell::~Cell() {}

Cell &Cell::operator=(Cell &other)
{
    if (this == &other)
    {
        return *this;
    }
    info.type = other.getInfo().type;
    info.row = other.getInfo().row;
    info.col = other.getInfo().col;
    info.chamberNum = other.getInfo().chamberNum;
    ob = other.getObject();
    return *this;
}


void Cell::setObject(std::shared_ptr<Object> object)
{
    ob = object;
}

int Cell::getChamberNum()
{
    return info.chamberNum;
}

std::shared_ptr<Object> Cell::getObject()
{
    return ob;
}

Info Cell::getInfo() const
{
    return info;
}
