#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include <vector>
#include "observer.h"
#include "cell.h"

class Cell;

class TextDisplay : public Observer
{
    std::vector<std::vector<char>> map;
    std::shared_ptr<Cell> subject;

public:
    explicit TextDisplay(std::vector<std::string> floor);
    virtual std::string notify(Cell &whoNotified) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
