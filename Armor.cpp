#include "Armor.h"
#include <stdexcept>

Armor::Armor(int v) : Attribute(v) {
    if (v < 0) throw std::invalid_argument("Armor cannot be negative");
}

int Armor::reduceDamage(int damage) const {
    if (damage < 0) return 0;
    int result = damage - value;
    return result > 0 ? result : 0;
}