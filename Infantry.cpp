#include "Infantry.h"

using namespace std;

Swordsman::Swordsman(int x, int y, Health h, Armor a, Attack atk)
    : Infantry("Swordsman", x, y, h, a, atk) {
}

void Swordsman::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + dx;
    int ny = y() + dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> Swordsman::clone() const {
    return make_unique<Swordsman>(*this);
}

Spearman::Spearman(int x, int y, Health h, Armor a, Attack atk)
    : Infantry("Spearman", x, y, h, a, atk) {
}

void Spearman::move(int dx, int dy, int maxW, int maxH) {
    int nx = x() + dx;
    int ny = y() + dy;
    if (nx < 0) nx = 0;
    if (nx >= maxW) nx = maxW - 1;
    if (ny < 0) ny = 0;
    if (ny >= maxH) ny = maxH - 1;
    setPosition(nx, ny);
}

unique_ptr<Unit> Spearman::clone() const {
    return make_unique<Spearman>(*this);
}