#include "Attack.h"
#include "Armor.h"
#include <stdexcept>

Attack::Attack(int v) : Attribute(v) {
    if (v < 0) throw std::invalid_argument("Attack cannot be negative");
}

int Attack::calculateDamage(const Armor& targetArmor) const {
    return targetArmor.reduceDamage(value);
}