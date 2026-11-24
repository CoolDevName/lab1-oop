#pragma once
#include "Unit.h"

using namespace std;

class Infantry : public Unit {
public:
    Infantry(string name, int x, int y, Health h, Armor a, Attack atk)
        : Unit(std::move(name), x, y, h, a, atk) {
    }
};

class Swordsman : public Infantry {
public:
    Swordsman(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Infantry/Swordsman"; }
    unique_ptr<Unit> clone() const override;
};

class Spearman : public Infantry {
public:
    Spearman(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Infantry/Spearman"; }
    unique_ptr<Unit> clone() const override;
};