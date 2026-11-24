#include "CavalryFactory.h"
#include "Cavalry.h"

 unique_ptr<Unit> CavalryFactory::createUnit(const  string& variant, int x, int y) const {
    if (variant == "cataphract")
        return  make_unique<Cataphract>(x, y, Health(160), Armor(40), Attack(55));
    if (variant == "horsearcher")
        return  make_unique<HorseArcher>(x, y, Health(100), Armor(15), Attack(40));
    return nullptr;
}