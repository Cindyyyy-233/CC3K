#include "controller.h"
#include <sstream>

Controller::Controller() {}

Controller::~Controller() {}

bool Controller::isMove(std::string cmd)
{
    if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
        cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Controller::init()
{
    std::cout << "Welcome to the cc3k game! 你好！" << std::endl;
    std::cout << "Please choose the race you want to play: " << std::endl;
    std::cout << "s->shade; d->drow; v->vampire; t->troll; g->goblin" << std::endl;
    std::string race = "default";
    std::cin >> race;
    createPlayer(race);
    if (defaultMap)
    {
        floor->generate();
    }
}

void Controller::play()
{
    init();
    std::string cmd;
    std::cout << *floor << std::endl;
    printstate();
    std::cout << "Please type a command.\n";
    while (std::cin >> cmd)
    {
        message = "";
        if (isMove(cmd))
        {
            message = floor->Move(cmd);
        }
        else if (cmd[0] == 'u')
        {
            std::string s;
            std::cin >> s;
            if (isMove(s))
            {
                message = floor->usePotion(s);
            }
            else
            {
                std::cout << "Invalid Command\n";
                continue;
            }
        }
        else if (cmd[0] == 'a')
        {
            std::string s;
            std::cin >> s;
            if (isMove(s))
            {
                message = floor->attack(s);
            }
            else
            {
                std::cout << "Invalid Command" << std::endl;
                continue;
            }
        }
        else if (cmd == "f")
        {
            Enemy::moved = !Enemy::moved;
        }
        else if (cmd == "r")
        {
            restarts();
            std::cout << *floor << std::endl;
            printstate();
            continue;
        }
        else if (cmd == "q")
        {
            floor->floorclear();
            break;
        }
        else
        {
            std::cout << "Invalid Command" << std::endl;
            continue;
        }
        // move enemy
        if (Enemy::moved)
        {
            floor->enemyMove();
        }
        if (floor->getPlayer()->getHP() == 0)
        {
            std::cout << "You are Dead!" << std::endl;
            floor->floorclear();
            break;
        }
        // determine if win
        if (floor->getFloorNum() == 5 && floor->atStair())
        {
            int score;
            if (floor->getPlayer()->getRace() == "Shade")
            {
                score = floor->getPlayer()->getGold() * 1.5;
            }
            else
            {
                score = floor->getPlayer()->getGold();
            }
            std::cout << "You Win!\n Your score is: " << score << std::endl;
            break;
        }
        if (floor->atStair() && !defaultMap)
        {
            floor->floorclear();
	    floor->setFloorNum(floor->getFloorNum() + 1);
            int floorNum = floor->getFloorNum();
            int startRow = 25 * (floorNum - 1);
            std::vector<std::string> tmp(strFloor.begin() + startRow, strFloor.begin() + startRow + 25);
            floor->init2(tmp);
        floor->getPlayer()->setATK(floor->getPlayer()->getBasicATK());
            floor->getPlayer()->setDEF(floor->getPlayer()->getBasicDEF());
	}
        else if (floor->atStair() && defaultMap)
        {
            floor->floorclear();
            floor->generate();
            floor->getPlayer()->setATK(floor->getPlayer()->getBasicATK());
            floor->getPlayer()->setDEF(floor->getPlayer()->getBasicDEF());
            floor->setFloorNum(floor->getFloorNum() + 1);
        }
	if (floor->getPlayer()->getRace() == "Troll") {
		floor->getPlayer()->heal(5);
	}
        std::cout << *floor << std::endl;
        printstate();
    }
}

void Controller::readmap(std::string &file)
{
	std::shared_ptr<std::istream> infile = std::make_shared< std::ifstream>(file);
    if (infile == nullptr || infile->fail())
    {
        std::cout << "ERROR: " << file << " cannot be opened for input\n";
        return;
    }
    int i = 0;
    std::string line;
    while (std::getline(*infile, line))
    {
        strFloor.push_back(line);
        i++;
    }
    floor = std::make_shared<Floor>();
    if (file == "default_map.txt")
    {
        defaultMap = true;
        floor->init(strFloor);
    }
    else
    {
        defaultMap = false;
        std::vector<std::string> tmp(strFloor.begin(), strFloor.begin() + 25);
        floor->init2(tmp);
    }

    //delete infile;
}

void Controller::createPlayer(std::string type)
{
    std::shared_ptr<Player> player = NULL;
    std::cout << "You chosed ";
    if (type == "d")
    {
        std::cout << "drow.\n150HP, 25Atk, 15Def, all potions have their effect magnified by 1.5 " << std::endl;
        player = std::make_shared<Drow>();
    }
    else if (type == "v")
    {
        std::cout << "vampire.\n50HP, 25Atk, 25Def, gain 5 HP every succeddful attack and has no maximum HP " << std::endl;
        player = std::make_shared<Vampire>();
    }
    else if (type == "t")
    {
        std::cout << "troll.\n120HP, 25Atk, 15Def, regains 5 HP every turn, HP is capped at 120 HP " << std::endl;
        player = std::make_shared<Troll>();
    }
    else if (type == "g")
    {
        std::cout << "goblin.\n110HP, 15Atk, 20Def, steals 5 gold from every slain enemy " << std::endl;
        player = std::make_shared<Goblin>();
    }
    else
    {
        std::cout << "shade.\n125HP, 25Atk, 25Def" << std::endl;
        player = std::make_shared<Shade>();
    }
    floor->setPlayer(player);
}

void Controller::printstate()
{
    std::string floor_num = std::to_string(floor->getFloorNum());
    std::shared_ptr<Player> player = floor->getPlayer();
    std::string race = "Not decided yet";
    std::string gold = "0";
    std::string atk = "0";
    std::string def = "0";
    std::string hp = "0";
    if (player != nullptr)
    {
        race = player->getRace();
        gold = std::to_string(player->getGold());
        atk = std::to_string(player->getATK());
        def = std::to_string(player->getDEF());
        hp = std::to_string(player->getHP());
    }
    std::cout << "Race: " << race << " Gold: " << gold << std::setw(60) << "Floor: " << floor->getFloorNum() << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "Atk: " << atk << std::endl;
    std::cout << "Def: " << def << std::endl;
    std::cout << "Action: " << message << std::endl;
}

void Controller::restarts()
{
    floor->setFloorNum(1);
    Merchant::hostile = false;
    Potion::usedPH = false;
    Potion::usedRH = false;
    Potion::usedBA = false;
    Potion::usedBD = false;
    Potion::usedWA = false;
    Potion::usedWD = false;
    if (defaultMap)
    {
        floor->floorclear();
    }
    else
    {
        floor->floorclear();
        std::vector<std::string> tmp(strFloor.begin(), strFloor.begin() + 25);
        floor->init2(tmp);
    }
    init();
    floor->getPlayer()->setGold(0);
}
