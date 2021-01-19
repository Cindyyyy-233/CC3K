#ifndef _INFO_H
#define _INFO_H
#include <cstddef> // defines size_t i.e. an unsigned int

// State of the cell i.e. either dead or alive.
enum class Type
{
    Wall,
    FloorTile,
    Doorway,
    Passage,
    WhiteSpace
};

// Information for the cell to return i.e. its state (Alive/Dead) and position in grid.
struct Info
{
    Type type;
    size_t row, col, chamberNum;
};

#endif
