#pragma once
#include "Attribute.h"

class Armor;

class Attack : public Attribute<int> {
public:
    explicit Attack(int v = 0);
    int calculateDamage(const Armor& targetArmor) const;
};