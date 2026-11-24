#include "InfantryFactory.h"
#include "Infantry.h"

 unique_ptr<Unit> InfantryFactory::createUnit(const string& variant, int x, int y) const {
    if (variant == "swordsman")
        return make_unique<Swordsman>(x, y, Health(120), Armor(20), Attack(35));
    if (variant == "spearman")
        return make_unique<Spearman>(x, y, Health(100), Armor(15), Attack(40));
    return nullptr;
}