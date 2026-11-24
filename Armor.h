#pragma once
#include "Attribute.h"

class Armor : public Attribute<int> {
public:     
    explicit Armor(int v = 0);
    int reduceDamage(int damage) const;
}; 