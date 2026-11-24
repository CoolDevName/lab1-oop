#include "Archer.h"

using namespace std;

LightArcher::LightArcher(int x, int y, Health h, Armor a, Attack atk)
    : Archer("LightArcher", x, y, h, a, atk) {
}

void LightArcher::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + dx;
    int ny = y() + dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> LightArcher::clone() const {
    return make_unique<LightArcher>(*this);
}

HeavyArcher::HeavyArcher(int x, int y, Health h, Armor a, Attack atk)
    : Archer("HeavyArcher", x, y, h, a, atk) {
}

void HeavyArcher::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + dx;
    int ny = y() + dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> HeavyArcher::clone() const {
    return make_unique<HeavyArcher>(*this);
}