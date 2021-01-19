#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "textDisplay.h"
#include "floor.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

class Controller
{
    std::shared_ptr<Floor> floor;
    std::vector<std::string> strFloor;
    std::string message;
    bool defaultMap;

public:
    Controller();
    ~Controller();
    void readmap(std::string &file);
    void init();
    void play();
    void createPlayer(std::string type);
    void printstate();
    void stopenemies();
    void restarts();

private:
    bool isMove(std::string cmd);
};

#endif
