#pragma once
#include "UnitFactory.h"

class CavalryFactory : public UnitFactory {
public:
     unique_ptr<Unit> createUnit(const  string& variant, int x, int y) const override;
};