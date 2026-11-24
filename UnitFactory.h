#pragma once
#include <memory>
#include "Unit.h"

using namespace std;

class UnitFactory {
public:
    virtual ~UnitFactory() = default;
    virtual  unique_ptr<Unit> createUnit(const  string& variant, int x, int y) const = 0;
};