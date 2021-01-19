#include "Treasure.h"
#include "Enemy.h"

Treasure::Treasure(char symbol, std::string type,
                   int gold) : Item{'G', type}, gold{gold} {}

Treasure::~Treasure() {}

int Treasure::getGold()
{
        return gold;
}

smallhoard::smallhoard() : Treasure{'G', "smallhoard", 1} {}

smallhoard::~smallhoard() {}

normalhoard::normalhoard() : Treasure{'G', "normalhoard", 2} {}

normalhoard::~normalhoard() {}

merchanthoard::merchanthoard() : Treasure{'G', "merchanthoard", 4} {}

merchanthoard::~merchanthoard() {}

DragonHoard::DragonHoard(std::shared_ptr<Dragon> drag) : Treasure{'G', "dragonhoard", 6}, dragon{drag} {}

DragonHoard::~DragonHoard() {}

std::shared_ptr<Dragon> DragonHoard::getDragon()
{
        return dragon;
}

void DragonHoard::setDragon(std::shared_ptr<Dragon> d) {
	dragon = d;
}
