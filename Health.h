#pragma once
#include "Attribute.h"

class Health : public Attribute<int> {
public:
    explicit Health(int v = 0);
    void decrease(int amount);
    void increase(int amount);
    bool isZero() const { return value == 0; }
};