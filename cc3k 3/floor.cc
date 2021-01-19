#include "floor.h"
#include "info.h"

Floor::Floor() : floor_num{1}, onDragonHoard{false}, dragonhoard(0, 0, 0, Type::WhiteSpace) {}
Floor::~Floor() {}

void Floor::init(std::vector<std::string> strFloor)
{
    td = std::make_shared<TextDisplay>(strFloor);
    int width = strFloor[0].size();
    int rowLength = strFloor.size();
    for (int row = 0; row < rowLength; row++)
    {
        std::vector<std::shared_ptr<Cell>> cells;
        for (int col = 0; col < width; col++)
        {
            if (strFloor[row][col] == '|' || strFloor[row][col] == '-')
            {
                Cell tmp = Cell(row, col, 0, Type::Wall);
                cells.push_back(std::make_shared<Cell>(tmp));
            }
            else if (strFloor[row][col] == '.')
            {
                int chambernum = 0;
                if (row >= 3 && row <= 8 && col >= 3 && col <= 30)
                {
                    chambernum = 1;
                }
                else if (row >= 15 && row <= 23 && col >= 4 && col <= 26)
                {
                    chambernum = 2;
                }
                else if (row >= 10 && row <= 14 && col >= 38 && col <= 51)
                {
                    chambernum = 3;
                }
                else if ((row >= 19 && row <= 23 && col >= 37 && col <= 65) || (row >= 16 && row <= 23 && col >= 65 && col <= 77))
                {
                    chambernum = 4;
                }
                else if ((row >= 3 && row <= 5 && col >= 39 && col <= 63) || (row >= 5 && row <= 8 && col >= 61 && col <= 71) ||
                         (row >= 6 && row <= 8 && col >= 71 && col <= 74) || (row >= 7 && row <= 14 && col >= 74 && col <= 76) ||
                         (row >= 8 && row <= 14 && col >= 61 && col <= 74))
                {
                    chambernum = 5;
                }
                Cell tmp = Cell(row, col, chambernum, Type::FloorTile);
                cells.push_back(std::make_shared<Cell>(tmp));
            }
            else if (strFloor[row][col] == '+')
            {
                Cell tmp = Cell(row, col, 0, Type::Doorway);
                cells.push_back(std::make_shared<Cell>(tmp));
            }
            else if (strFloor[row][col] == '#')
            {
                Cell tmp = Cell(row, col, 0, Type::Passage);
                cells.push_back(std::make_shared<Cell>(tmp));
            }
            else
            {
                Cell tmp = Cell(row, col, 0, Type::WhiteSpace);
                cells.push_back(std::make_shared<Cell>(tmp));
            }
        }
        floor.push_back(cells);
    }
}

void Floor::init2(std::vector<std::string> strFloor)
{
    td = std::make_shared<TextDisplay>(strFloor);
    int width = strFloor[0].size();
    int rowLength = strFloor.size();
    for (int row = 0; row < rowLength; row++)
    {
        std::vector<std::shared_ptr<Cell>> cells;
        for (int col = 0; col < width; col++)
        {
            if (strFloor[row][col] == '|' || strFloor[row][col] == '-')
            {
                Cell tmp = Cell(row, col, 0, Type::Wall);
                std::shared_ptr<Cell> cell = std::make_shared<Cell>(tmp);
                cells.push_back(cell);
            }
            else if (strFloor[row][col] == '+')
            {
                Cell tmp = Cell(row, col, 0, Type::Doorway);
                std::shared_ptr<Cell> cell = std::make_shared<Cell>(tmp);
                cells.push_back(cell);
            }
            else if (strFloor[row][col] == '#')
            {
                Cell tmp = Cell(row, col, 0, Type::Passage);
                std::shared_ptr<Cell> cell = std::make_shared<Cell>(tmp);
                cells.push_back(cell);
            }
            else if (strFloor[row][col] == ' ')
            {
                Cell tmp = Cell(row, col, 0, Type::WhiteSpace);
                std::shared_ptr<Cell> cell = std::make_shared<Cell>(tmp);
                cells.push_back(cell);
            }
            else
            {
                Cell tmp = Cell(row, col, 0, Type::FloorTile);
                std::shared_ptr<Cell> cell = std::make_shared<Cell>(tmp);
                cells.push_back(cell);
            }
        }
        floor.push_back(cells);
    }
    setObjects(strFloor);
}

void Floor::setDragonHoard(int row, int col, std::vector<std::string> strFloor)
{
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (strFloor[i][j] == 'D')
            {
                std::shared_ptr<Dragon> d = std::make_shared<Dragon>();
                floor[i][j]->setObject(d);
                std::shared_ptr<DragonHoard> g = std::make_shared<DragonHoard>(d);
                floor[row][col]->setObject(g);
                td->notify(*floor[row][col]);
            }
        }
    }
}

void Floor::setObjects(std::vector<std::string> strFloor)
{
    int width = strFloor[0].size();
    int rowLength = strFloor.size();
    std::shared_ptr<Object> ob;
    for (int row = 0; row < rowLength; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (strFloor[row][col] == '0')
            {
                ob = std::make_shared<Potion>("RH");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '1')
            {
                ob = std::make_shared<Potion>("BA");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '2')
            {
                ob = std::make_shared<Potion>("BD");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '3')
            {
                ob = std::make_shared<Potion>("PH");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '4')
            {
                ob = std::make_shared<Potion>("WA");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '5')
            {
                ob = std::make_shared<Potion>("WD");
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '6')
            {
                ob = std::make_shared<normalhoard>();
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '7')
            {
                ob = std::make_shared<smallhoard>();
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '8')
            {
                ob = std::make_shared<merchanthoard>();
                floor[row][col]->setObject(ob);
                td->notify(*floor[row][col]);
            }
            else if (strFloor[row][col] == '9')
            {
                setDragonHoard(row, col, strFloor);
            }
            else if (strFloor[row][col] == '@')
            {
                floor[row][col]->setObject(p);
                player = floor[row][col];
            }
            else if (strFloor[row][col] == 'H')
            {
                ob = std::make_shared<Human>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == 'O')
            {
                ob = std::make_shared<Orc>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == 'L')
            {
                ob = std::make_shared<Halfling>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == 'M')
            {
                ob = std::make_shared<Merchant>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == 'E')
            {
                ob = std::make_shared<Elf>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == 'W')
            {
                ob = std::make_shared<Dwarf>();
                floor[row][col]->setObject(ob);
                enemies.push_back(floor[row][col]);
            }
            else if (strFloor[row][col] == '\\')
            {
                ob = std::make_shared<Stair>();
                floor[row][col]->setObject(ob);
            }
        }
    }
}

int Floor::getFloorNum()
{
    return floor_num;
}

void Floor::setFloorNum(int n)
{
    floor_num = n;
}

void Floor::setPlayer(std::shared_ptr<Player> player)
{
    p = player;
}

std::shared_ptr<Player> Floor::getPlayer()
{
    return p;
}

std::shared_ptr<Cell> Floor::getCell(int r, int c)
{
    return floor[r][c];
}

// void Floor::setObserver()
// {
// 	player->clearobservers();
//     int r = player->getInfo().row;
//     int c = player->getInfo().col;
//     for (int i = r - 1; i <= r + 1; i++)
//     {
//         for (int j = c - 1; j <= c + 1; j++)
//         {
// 	if (floor[i][j]->getObject() && floor[i][j]->getObject()->getRace() == "Dragon") {
// 		floor[i][j]->getObject()->setHasAttacked(false);
// 	 } else if(floor[i][j]->getObject() && floor[i][j]->getObject()->getDragon() &&floor[i][j]->getObject()->getType() == "dragonhoard") {
// 	 	if(floor[i][j]->getObject()->getDragon()->getHP() == 0) {
// 			floor[i][j]->getObject()->setDragon(nullptr);
// 		}
// 	 }
//             player->attach(floor[i][j]);
//         }
//     }
// }

void Floor::generate()
{
    floorclear();
    generatePlayerStair();
    generatePotion();
    generateGold();
    generateEnemy();
}

// find a valid position for an enemy
void Floor::generatePosition(int &r, int &c, int chamberNum)
{
    while (1)
    {
        r = rand() % floor.size();
        c = rand() % floor[0].size();
        std::shared_ptr<Cell> tmp = floor[r][c];
        int chamber = tmp->getInfo().chamberNum;
        if (tmp->getInfo().type == Type::FloorTile && tmp->getObject() == nullptr && chamber == chamberNum)
        {
            break;
        }
    }
}

void Floor::generatePlayerStair()
{
    int r;
    int c;
    int chaNumPlayer;
    int chaNumStair;
    std::shared_ptr<Object> s;
    s = std::make_shared<Stair>();
    while (1)
    {
        chaNumPlayer = rand() % 5 + 1;
        chaNumStair = rand() % 5 + 1;
        if (chaNumPlayer != chaNumStair)
        {
            break;
        }
    }
    generatePosition(r, c, chaNumPlayer);
    floor[r][c]->setObject(p);
    player = floor[r][c];
    td->notify(*floor[r][c]);
    generatePosition(r, c, chaNumStair);
    floor[r][c]->setObject(s);
    td->notify(*floor[r][c]);
}

void Floor::generatePotion()
{
    for (int i = 0; i < 10; i++)
    {
        int r;
        int c;
        int chamberNum = rand() % 5 + 1;
        int potiontype = rand() % 6;
        std::shared_ptr<Object> p;
        generatePosition(r, c, chamberNum);
        if (potiontype == 0)
        {
            p = std::make_shared<Potion>("RH");
        }
        else if (potiontype == 1)
        {
            p = std::make_shared<Potion>("BA");
        }
        else if (potiontype == 2)
        {
            p = std::make_shared<Potion>("BD");
        }
        else if (potiontype == 3)
        {
            p = std::make_shared<Potion>("PH");
        }
        else if (potiontype == 4)
        {
            p = std::make_shared<Potion>("WA");
        }
        else if (potiontype == 5)
        {
            p = std::make_shared<Potion>("WD");
        }
        floor[r][c]->setObject(p);
        td->notify(*floor[r][c]);
    }
}

void Floor::generateGold()
{
    for (int i = 0; i < 10; i++)
    {
        int gold = rand() % 8;
        int r, c;
        int chamberNum = rand() % 5 + 1;
        std::shared_ptr<Object> g;
        generatePosition(r, c, chamberNum);
        if (gold < 5)
        {
            g = std::make_shared<normalhoard>();
        }
        else if (gold < 6)
        {
            int dragonpos;
            std::shared_ptr<Dragon> d;
            while (1)
            {
                dragonpos = rand() % 8;
                std::shared_ptr<Cell> dragon = getNeighbour(directions[dragonpos], r, c);
                if (dragon->getInfo().type == Type::FloorTile && dragon->getObject() == nullptr)
                {
                    d = std::make_shared<Dragon>();
                    dragon->setObject(d);
                    g = std::make_shared<DragonHoard>(d);
                    td->notify(*dragon);
                    break;
                }
            }
        }
        else
        {
            g = std::make_shared<smallhoard>();
        }
        floor[r][c]->setObject(g);
        td->notify(*floor[r][c]);
    }
}

void Floor::generateEnemy()
{
    for (int i = 0; i < 20; i++)
    {
        int enemyrace = rand() % 18;
        int r, c;
        std::shared_ptr<Object> ob;
        int chamberNum = rand() % 5 + 1;
        generatePosition(r, c, chamberNum);
        if (enemyrace < 4)
        {
            ob = std::make_shared<Human>();
        }
        else if (enemyrace < 7)
        {
            ob = std::make_shared<Dwarf>();
        }
        else if (enemyrace < 12)
        {
            ob = std::make_shared<Halfling>();
        }
        else if (enemyrace < 14)
        {
            ob = std::make_shared<Elf>();
        }
        else if (enemyrace < 16)
        {
            ob = std::make_shared<Orc>();
        }
        else
        {
            ob = std::make_shared<Merchant>();
        }
        floor[r][c]->setObject(ob);
        enemies.push_back(floor[r][c]);
        td->notify(*floor[r][c]);
    }
}

void Floor::floorclear()
{
    int rowLength = floor.size();
    int colLength = floor[0].size();
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            if (!floor[i][j]->getObject())
            {
                continue;
            }
            floor[i][j]->setObject(nullptr);
            td->notify(*floor[i][j]);
        }
    }
    clearEnemies();
}

void Floor::clearEnemies()
{
    atstair = false;
    int enemysize = enemies.size();
    while (enemysize > 0)
    {
        enemies.erase(enemies.begin());
        enemysize--;
    }
}

void Floor::enemyMove()
{
    int enemySize = enemies.size();
    for (int i = 0; i < enemySize; i++)
    {
        if (enemies[i]->getObject())
        {

            if (enemies[i]->getObject()->getType() == "Enemy" && !enemies[i]->getObject()->getDuringAttack())
            {
                while (1)
                {
                    int direction = rand() % 8;
                    int r = enemies[i]->getInfo().row;
                    int c = enemies[i]->getInfo().col;
                    std::shared_ptr<Cell> cell = getNeighbour(directions[direction], r, c);
                    if (cell->getInfo().type == Type::FloorTile && cell->getObject() == nullptr)
                    {
                        // change the object to c and set enemies[i] to c
                        cell->setObject(enemies[i]->getObject());
                        enemies[i]->setObject(nullptr);
                        td->notify(*enemies[i]);
                        td->notify(*cell);
                        enemies[i] = cell;
                        td->notify(*enemies[i]);
                        break;
                    }
                }
            }
            else
            {
                enemies[i]->getObject()->setDuringAttack(false);
            }
        }
    }
}

std::shared_ptr<Cell> Floor::getNeighbour(std::string d, int r, int c)
{
    if (d == "no")
    {
        return floor[r - 1][c];
    }
    else if (d == "so")
    {
        return floor[r + 1][c];
    }
    else if (d == "ea")
    {
        return floor[r][c + 1];
    }
    else if (d == "we")
    {
        return floor[r][c - 1];
    }
    else if (d == "ne")
    {
        return floor[r - 1][c + 1];
    }
    else if (d == "nw")
    {
        return floor[r - 1][c - 1];
    }
    else if (d == "se")
    {
        return floor[r + 1][c + 1];
    }
    else
    {
        return floor[r + 1][c - 1];
    }
}

bool Floor::atStair()
{
    return atstair;
}

std::string Floor::attack(std::string direction)
{
    int r = player->getInfo().row;
    int c = player->getInfo().col;
    std::shared_ptr<Cell> cell = getNeighbour(direction, r, c);
    std::string msg;
    if (cell->getInfo().type == Type::WhiteSpace)
    {
        return "Nothing is in front of you, you cannot attack.";
    }
    else if (!cell->getObject())
    {
        return "You should attack an Enemy.";
    }
    else if (cell->getObject()->getType() != "Enemy")
    {
        return "You should attack an Enemy.";
    }
    else
    {
        std::shared_ptr<Enemy> enemy = std::dynamic_pointer_cast<Enemy>(cell->getObject());
        if (enemy->getRace() == "Halfling")
        {
            int chance = rand() % 2;
            if (chance == 1)
            {
                msg = "You miss it.";
                msg += notify();
                return msg;
            }
        }
        /*if (p->getRace() == "Troll")
        {
            p->heal(5);
        }
	 */
        else if (p->getRace() == "Vampire")
        {
            if (enemy->getRace() == "Dwarf")
            {
                p->heal(-5);
            }
            else
            {
                p->heal(5);
            }
        }
        else if (enemy->getRace() == "Merchant")
        {
            Merchant::hostile = true;
        }
	std::cout << "hp: " << p->getHP() << std::endl;
        double no = 100 * p->getATK();
        double de = 100 + enemy->getDEF();
        double res = no / de;
        int dmg = ceil(res);
        enemy->BeAttacked(dmg);
        msg += p->getRace() + " deals " + std::to_string(dmg) + " damage to " + enemy->getRace() + " (" + std::to_string(enemy->getHP()) + ") ";
        if (enemy->getHP() == 0)
        {
            msg += "The Enemy has been slained!";
            if (p->getRace() == "Goblin")
            {
                p->addGold(5);
            }
            if (enemy->getRace() == "Human")
            {
                // generate one normal gold on the enemy position
                std::shared_ptr<Object> nh = std::make_shared<normalhoard>();
                cell->setObject(nh);
                td->notify(*cell);
                // generate the other normal gold nearby
                int setSuccess = 0;
                for (int i = 0; i < 8; i++)
                {
                    std::shared_ptr<Cell> nhCell = getNeighbour(directions[i], cell->getInfo().row, cell->getInfo().col);
                    if (nhCell->getObject() == nullptr && nhCell->getInfo().type == Type::FloorTile)
                    {
                        std::shared_ptr<Object> nh2 = std::make_shared<normalhoard>();
                        nhCell->setObject(nh2);
                        td->notify(*nhCell);
                        setSuccess = 1;
                        break;
                    }
                }
                if (!setSuccess)
                {
                    int r;
                    int c;
                    int chamberNum = cell->getChamberNum();
                    generatePosition(r, c, chamberNum);
                    std::shared_ptr<Object> nh2 = std::make_shared<normalhoard>();
                    floor[r][c]->setObject(nh2);
                    td->notify(*floor[r][c]);
                }
            }
            else if (enemy->getRace() == "Merchant")
            {
                // generate a merchant hoard on the enemy position
                std::shared_ptr<Object> mh = std::make_shared<merchanthoard>();
                cell->setObject(mh);
                td->notify(*cell);
            }
            else if (enemy->getRace() == "Dragon")
            {
                cell->setObject(nullptr);
                td->notify(*cell);
            }
            else
            {
                int chance = rand() % 2;
                if (chance == 0)
                {
                    p->addGold(1);
                }
                else
                {
                    p->addGold(2);
                }
                cell->setObject(nullptr);
                td->notify(*cell);
            }
        }
    }
    msg += notify();
    return msg;
}

// go to a new floor
std::string Floor::Move(std::string d)
{
    int r = player->getInfo().row;
    int c = player->getInfo().col;
    std::shared_ptr<Cell> cell = getNeighbour(d, r, c);
    std::string msg;
    if (cell->getInfo().type == Type::WhiteSpace)
    {
        return "Nothing is in front of you, you cannot move.";
    }
    if (cell->getInfo().type == Type::FloorTile)
    {
        if (onDragonHoard)
        {
            floor[r][c]->setObject(dragonhoard.getObject());
            onDragonHoard = false;
            cell->setObject(p);
            player = cell;
            td->notify(*floor[r][c]);
            td->notify(*cell);
            msg += notify();
            return msg;
        }
        if (cell->getObject())
        {
            if (cell->getObject()->getType() == "dragonhoard")
            {

                if (cell->getObject()->getDragon())
                {
                    onDragonHoard = true;
                    dragonhoard = *cell;
                    msg = "PC moves " + d + "and sees a treasure. You cannot take the treasure, a dragon is guarding it.";
                }
                else
                {
                    onDragonHoard = false;
                    p->addGold(6);
                    msg = "PC moves " + d + "and takes a treasure.";
                }
            }
            else if (cell->getObject()->getType() == "smallhoard")
            {
                p->addGold(1);
                msg = "PC moves " + d + "and takes a treasure.";
            }
            else if (cell->getObject()->getType() == "normalhoard")
            {
                p->addGold(2);
                msg = "PC moves " + d + "and takes a treasure.";
            }
            else if (cell->getObject()->getType() == "merchanthoard")
            {
                p->addGold(4);
                msg = "PC moves " + d + "and takes a treasure.";
            }
            else if (cell->getObject()->getType() == "Enemy")
            {
                msg += cell->getObject()->getRace() + " is in front of you, you cannot move.";
                msg += notify();
                return msg;
            }
            else if (cell->getObject()->getType() == "potion")
            {
		    msg = "Potion is in front of you, you cannot move. ";
		msg  += notify();
                return msg;
            }
        }
        else
        { //empty floor
            msg = " PC moves " + d;
        }
    }
    else if (cell->getInfo().type == Type::Wall)
    {
	    msg = "You cannot move through the wall.";
	    msg += notify();
        return msg;
    }
    else
    {
        msg = " PC moves " + d;
    }
    if (cell->getObject())
    {
        if (cell->getObject()->getType() == "Stair")
        {
            atstair = true;
        }
    }
    cell->setObject(p);
    floor[r][c]->setObject(nullptr);
    player = cell;
    td->notify(*floor[r][c]);
    td->notify(*cell);
    msg += notify();
    return msg;
}

std::string Floor::notify()
{
    int r = player->getInfo().row;
    int c = player->getInfo().col;
    std::string msg = "";
    for (int i = r - 1; i <= r + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            if (i == r && j == c)
            {
                continue;
            }
            if (floor[i][j]->getObject() && floor[i][j]->getObject()->getRace() == "Dragon")
            {
                floor[i][j]->getObject()->setHasAttacked(false);
            }
            else if (floor[i][j]->getObject() && floor[i][j]->getObject()->getDragon() && floor[i][j]->getObject()->getType() == "dragonhoard")
            {
                if (floor[i][j]->getObject()->getDragon()->getHP() == 0)
                {
                    floor[i][j]->getObject()->setDragon(nullptr);
                }
	    }
                if (player->getObject() != nullptr && floor[i][j]->getObject() != nullptr)
                {
                    // if the subject is player, this means player is within a 1 block readius
                    // if an ememy is on this cell, it need to attack the player
                    if (player->getObject()->getType() == "Player")
                    {
                        if (floor[i][j]->getObject()->getType() == "Enemy")
                        {
                            if (floor[i][j]->getObject()->getRace() == "Merchant")
                            {
                                if (Merchant::hostile == false)
                                {
                                    floor[i][j]->getObject()->setDuringAttack(false);
                                    
                                }
                            }
                            else if (floor[i][j]->getObject()->getRace() == "Dragon")
                            {
                                if (floor[i][j]->getObject()->getHasAttacked())
                                {
                                    floor[i][j]->getObject()->setHasAttacked(false);
                                 
                                }
                                else
                                {
                                    floor[i][j]->getObject()->setHasAttacked(true);
                                    floor[i][j]->getObject()->setDuringAttack(true);
                                    msg += floor[i][j]->getObject()->attack(p);
                                }
                            }
                            floor[i][j]->getObject()->setDuringAttack(true);
                            msg += floor[i][j]->getObject()->attack(p);
                        }
                        else if (floor[i][j]->getObject()->getType() == "dragonhoard")
                        {
                            msg += "Sees a dragonhoard. ";
                            if (!floor[i][j]->getObject()->getDragon())
                            {
                                continue;    
                            }
                            if (floor[i][j]->getObject()->getDragon()->getHasAttacked())
                            {
                                floor[i][j]->getObject()->getDragon()->setHasAttacked(false);
                            }
                            else
                            {
                                floor[i][j]->getObject()->getDragon()->setHasAttacked(true);
                                msg += floor[i][j]->getObject()->getDragon()->attack(p);
                            }
           
                        }
                        else if (floor[i][j]->getObject()->getType() == "potion")
                        {
                            std::shared_ptr<Potion> potion = std::dynamic_pointer_cast<Potion>(floor[i][j]->getObject());
                            msg += potion->getDescription();
                        }
                        else if (floor[i][j]->getObject()->getType() == "smallhoard")
                        {
                            msg += "Sees a smallhoard. ";
                        }
                        else if (floor[i][j]->getObject()->getType() == "normalhoard")
                        {
                            msg += "Sees a normalhoard. ";
                        }
                        else if (floor[i][j]->getObject()->getType() == "merchanthoard")
                        {
                            msg += "Sees a merchanthoard. ";
                        }
                    }
                }
        }
    }
    return msg;
}

std::string Floor::usePotion(std::string s)
{
    int r = player->getInfo().row;
    int c = player->getInfo().col;
    std::shared_ptr<Cell> potionpos = getNeighbour(s, r, c);
    std::shared_ptr<Object> objpotion;
    objpotion = potionpos->getObject();
    std::string msg = "";
    if (!objpotion || objpotion->getType() != "potion")
    {
        msg = "There is no potion!";
        return msg;
    }
    else if (objpotion->getEffect() == "RH")
    {
        Potion::usedRH = true;
        int num = 10;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<HpDeco>(p);
        newplayer->setHP(num);
        msg = "PC uses RH";
    }
    else if (objpotion->getEffect() == "BA")
    {
        Potion::usedBA = true;
        int num = 5;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<AtkDeco>(p);
        newplayer->setATK(num);
        msg = "PC uses BA";
    }
    else if (objpotion->getEffect() == "BD")
    {
        Potion::usedBD = true;
        int num = 5;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<DefDeco>(p);
        newplayer->setDEF(num);
        msg = "PC uses BD";
    }
    else if (objpotion->getEffect() == "PH")
    {
        Potion::usedPH = true;
        int num = -10;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<HpDeco>(p);
        newplayer->setHP(num);
        msg = "PC uses PH";
    }
    else if (objpotion->getEffect() == "WA")
    {
        Potion::usedWA = true;
        int num = -5;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<AtkDeco>(p);
        newplayer->setATK(num);
        msg = "PC uses WA";
    }
    else if (objpotion->getEffect() == "WD")
    {
        Potion::usedWD = true;
        int num = -5;
        if (p->getRace() == "Drow")
        {
            num = num * 1.5;
        }
        std::shared_ptr<Player> newplayer = std::make_shared<DefDeco>(p);
        newplayer->setDEF(num);
        msg = "PC uses WD";
    }
    potionpos->setObject(p);
    // is is working
    player = potionpos;
    floor[r][c]->setObject(nullptr);
    td->notify(*floor[r][c]);
    td->notify(*potionpos);
    msg += notify();
    return msg;
}

std::ostream &operator<<(std::ostream &out, const Floor &f)
{
    out << *(f.td);
    return out;
}
