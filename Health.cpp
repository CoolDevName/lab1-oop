#include "Health.h"
#include <stdexcept>

using namespace std;

Health::Health(int v) : Attribute(v) {
    if (v < 0) throw invalid_argument("Health cannot be negative");
}

void Health::decrease(int amount) {
    if (amount < 0) return;
    value -= amount;
    if (value < 0) value = 0;
}

void Health::increase(int amount) {
    if (amount < 0) return;
    value += amount;
}