#pragma once
#include "Unit.h"

using namespace std;

class Cavalry : public Unit {
public:
    Cavalry(string name, int x, int y, Health h, Armor a, Attack atk)
        : Unit(std::move(name), x, y, h, a, atk) {
    }
};

class Cataphract : public Cavalry {
public:
    Cataphract(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Cavalry/Cataphract"; }
    unique_ptr<Unit> clone() const override;
};

class HorseArcher : public Cavalry {
public:
    HorseArcher(int x, int y, Health h, Armor a, Attack atk);
    void move(int dx, int dy, int maxW, int maxH) override;
    string type() const override { return "Cavalry/HorseArcher"; }
    unique_ptr<Unit> clone() const override;
};