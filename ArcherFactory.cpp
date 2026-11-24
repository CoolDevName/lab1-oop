#include "ArcherFactory.h"
#include "Archer.h"

unique_ptr<Unit> ArcherFactory::createUnit(const  string& variant,int x, int y) const {
    if (variant == "light")
        return  make_unique<LightArcher>(x, y, Health(70), Armor(5), Attack(45));
    if (variant == "heavy")
        return  make_unique<HeavyArcher>(x, y, Health(90), Armor(10), Attack(50));
    return nullptr;
}