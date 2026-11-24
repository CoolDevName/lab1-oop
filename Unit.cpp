#include "Unit.h"
#include <sstream>
#include <utility>


using namespace std;

Unit::Unit(string name, int x, int y, Health h, Armor a, Attack atk)
    : x_(x), y_(y), health_(h), armor_(a), attack_(atk), name_(std::move(name)) {
}

string Unit::info() const {
    ostringstream os;
    os << "[" << type() << "] " << name_
        << " (x=" << x_ << ", y=" << y_ << ")"
        << " HP=" << health_.getValue()
        << " Armor=" << armor_.getValue()
        << " Atk=" << attack_.getValue();
    return os.str();
}