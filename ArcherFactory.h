#pragma once
#include "UnitFactory.h"

class ArcherFactory : public UnitFactory {
public:
     unique_ptr<Unit> createUnit(const string& variant, int x, int y) const override;
};