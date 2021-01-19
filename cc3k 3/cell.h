#ifndef CELL_H
#define CELL_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include <memory>
#include "info.h"
#include "object.h"
#include "character.h"
#include "player.h"
#include "Treasure.h"
#include "Potion.h"

class Object;

class Cell
{
private:
    struct Info info;
    std::shared_ptr<Object> ob;

public:
    Cell(size_t r, size_t c, size_t chamberNum, Type);

    ~Cell();

    Cell &operator=(Cell &other);

    // point to the object which is on the floor
    void setObject(std::shared_ptr<Object>);


    int getChamberNum();

    std::shared_ptr<Object> getObject();

    // Observer calls this to get information about cell.
    Info getInfo() const;
};

#endif
