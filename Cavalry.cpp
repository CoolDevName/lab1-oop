#include "Cavalry.h"

using namespace std;

Cataphract::Cataphract(int x, int y, Health h, Armor a, Attack atk)
    : Cavalry("Cataphract", x, y, h, a, atk) {
}

void Cataphract::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + 2 * dx;
    int ny = y() + 2 * dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> Cataphract::clone() const {
    return make_unique<Cataphract>(*this);
}

HorseArcher::HorseArcher(int x, int y, Health h, Armor a, Attack atk)
    : Cavalry("HorseArcher", x, y, h, a, atk) {
}

void HorseArcher::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + 2 * dx;
    int ny = y() + 2 * dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> HorseArcher::clone() const {
    return make_unique<HorseArcher>(*this);
}