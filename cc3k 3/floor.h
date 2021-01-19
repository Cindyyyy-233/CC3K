#ifndef FLOOR_H
#define FLOOR_H

#include "textDisplay.h"
#include "object.h"
#include "cell.h"
#include "Potion.h"
#include "Treasure.h"
#include "Deco.h"
#include "player.h"
#include "PotionDeco.h"
#include <cmath>
#include <vector>
#include <memory>
#include <string>

class Floor
{
    const std::string directions[8] = {"no", "so", "ea", "we", "ne", "nw", "se", "sw"};
    std::shared_ptr<TextDisplay> td;
    std::shared_ptr<Player> p;
    std::shared_ptr<Cell> player;
    std::vector<std::shared_ptr<Cell>> enemies;
    std::vector<std::vector<std::shared_ptr<Cell>>> floor;
    int floor_num;
    bool onDragonHoard;
    bool atstair;
    Cell dragonhoard;
    void generatePosition(int &r, int &c, int chamberNum);
    void generatePlayerStair();
    void generatePotion();
    void generateGold();
    void generateEnemy();
    std::shared_ptr<Cell> getNeighbour(std::string d, int r, int c);

public:
    Floor();
    ~Floor();
    void init(std::vector<std::string> strFloor);
    void init2(std::vector<std::string> strFloor);
    void setObjects(std::vector<std::string> strFloor);
    void setDragonHoard(int row, int col, std::vector<std::string> strFloor);
    int getFloorNum();
    void setFloorNum(int n);
    void setPlayer(std::shared_ptr<Player> player);
    void setObserver();
    std::shared_ptr<Player> getPlayer();
    std::shared_ptr<Cell> getCell(int r, int c);
    void generate();
    std::string Move(std::string direction);
    void enemyMove();
    std::string usePotion(std::string s);
    std::string attack(std::string direction);
    bool atStair();
    void floorclear();
    void clearEnemies();
    std::string notify();
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

std::ostream &operator<<(std::ostream &out, const Floor &f);

#endif
