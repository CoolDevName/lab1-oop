#include <iostream>
#include <memory>
#include "GameField.h"
#include "InfantryFactory.h"
#include "ArcherFactory.h"
#include "CavalryFactory.h"
#include "ConsoleUtils.h"

using namespace std;

static void printField(const GameField& field) {
    cout << "\nПоле (" << field.size() << " юнитов)\n";
    field.draw();

    cout << "\nСписок юнитов:\n";
    for (const auto& u : field) {
        cout << "  " << u.info() << "\n";
    }
    cout << "\n";
}

int main() {
    setupConsoleUtf8();

    cout << "1) Создание поля и юнитов\n";

    GameField field(20, 20, 5);

    InfantryFactory infFactory;
    ArcherFactory   arcFactory;
    CavalryFactory  cavFactory;

    field.spawn(infFactory, "swordsman", 1, 1);
    field.spawn(infFactory, "spearman", 2, 1);
    field.spawn(arcFactory, "light", 3, 3);
    field.spawn(arcFactory, "heavy", 4, 3);
    field.spawn(cavFactory, "cataphract", 5, 5);

    printField(field);

    cout << "2) Копирование поля\n";

    GameField copy = field;

    if (auto* u = copy.getUnit(1, 1)) u->takeDamage(50);

    if (auto* orig = field.getUnit(1, 1))
        cout << "Оригинал (1,1): " << orig->info() << "\n";
    if (auto* cp = copy.getUnit(1, 1))
        cout << "Копия    (1,1): " << cp->info() << "\n";

    cout << "\n3) Перемещение поля\n";

    GameField moved = move(field);
    cout << "После move размер оригинала = " << field.size() << "\n";
    cout << "Размер перемещённого поля    = " << moved.size() << "\n";

    cout << "\n4) Перемещение юнита (проверка границ)\n";

    if (auto* cata = moved.getUnit(5, 5)) {
        cout << "До:    " << cata->info() << "\n";
        cata->move(10, 10, moved.width(), moved.height());
        cout << "После: " << cata->info() << "\n";
    }

    cout << "\n5) Ошибки границ, лимита и занятой клетки\n";

    if (!moved.spawn(cavFactory, "horsearcher", 5, 5)) {
        cout << "Ожидаемо: клетка (5,5) занята.\n";
    }
    if (!moved.spawn(infFactory, "swordsman", 100, 100)) {
        cout << "Ожидаемо: координата (100,100) вне поля.\n";
    }
    if (!moved.spawn(infFactory, "swordsman", 10, 10)) {
        cout << "Ожидаемо: превышен лимит maxUnits (5).\n";
    }

    cout << "\n6) Удаление юнитов и проверка empty/clear \n";

    moved.removeUnitAt(1, 1);
    moved.removeUnitAt(0);
    printField(moved);

    moved.clear();
    cout << "После clear() поле пустое: " << (moved.empty() ? "да" : "нет") << "\n";

    return 0;
}