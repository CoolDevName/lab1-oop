#pragma once
#include "Unit.h"

using namespace std;

class Archer : public Unit {
public:
    Archer(string name, int x, int y, Health h, Armor a, Attack atk)
        : Unit(std::move(name), x, y, h, a, atk) {
    }
};

class LightArcher : public Archer {
public:
    LightArcher(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Archer/Light"; }
    unique_ptr<Unit> clone() const override;
};

class HeavyArcher : public Archer {
public:
    HeavyArcher(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Archer/Heavy"; }
    unique_ptr<Unit> clone() const override;
};