#pragma once
#include <string>
#include <memory>
#include "Health.h"
#include "Armor.h"
#include "Attack.h"


using namespace std;

class Unit {
protected:
    int x_, y_;
    Health health_;
    Armor armor_;
    Attack attack_;
    string name_;

    void setPosition(int x, int y) { x_ = x; y_ = y; }

public:
    Unit(string name, int x, int y, Health h, Armor a, Attack atk);
    virtual ~Unit() = default;

    virtual void move(int dx, int dy, int maxW, int maxH) = 0;
    virtual string type() const = 0;
    virtual unique_ptr<Unit> clone() const = 0;

    int x() const { return x_; }
    int y() const { return y_; }

    const Health& health() const { return health_; }
    const Armor& armor() const { return armor_; }
    const Attack& attack() const { return attack_; }
    const string& name() const { return name_; }

    void takeDamage(int dmg) { health_.decrease(armor_.reduceDamage(dmg)); }
    bool isAlive() const { return !health_.isZero(); }

    string info() const;
};