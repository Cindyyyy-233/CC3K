#include "controller.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

int main(int argc, char *argv[])
{
    srand(time(0));
    std::string fileName = "default_map.txt";
    Controller c = Controller();
    if (argc <= 1)
    {
        // no file
        c.readmap(fileName);
    }
    else
    {
        std::string file = argv[1];
        c.readmap(file);
    }
    c.play();
}
