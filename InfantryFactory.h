#pragma once
#include "UnitFactory.h"

class InfantryFactory : public UnitFactory {
public:
     unique_ptr<Unit> createUnit(const  string& variant, int x, int y) const override;
};