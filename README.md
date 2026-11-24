Команда для сборки: g++ -std=c++17 -Wall -Wextra -o game *.cpp
Команда для запуска: game.exe
Отчет о лабораторной работе
  
Тема: Введение в ООП: создание классов, конструкторов классов, методов классов; наследование

  
Язык реализации: C++
Из-за формата отчета .md, пострадало форматитрование текста.
1)Программа спроектирована с использованием принципов инкапсуляции, наследования и полиморфизма. Все классы разделены на логические модули.

  
2)Выбран паттерн "Фабричный метод"(Factory Method), т.к. работаем с независимыми типами юнитов, которые на образуют жестких семейств. Создание конкретных фабрик позволяет инкапсулировать логику создания конкретных видов.

  
3)Для обхода юнитов на поле реализован собственный класс GameField::Iterator, совместимый со стандартной библиотекой. Тип - прямой итератор, позволяет обходить только занятые элементы контейнера независимо от их координат.Реализованы операторы \*, ->, ++, ==, !=

  
4)
  
Фрагмент 1: Глубокое копирование в GameField
  
GameField::GameField(const GameField& other)
  
    : width_(other.width_), height_(other.height_), maxUnits_(other.maxUnits_) {
    units_.reserve(other.units_.size());
    for (const auto& u : other.units_) { 
        units_.push_back(u->clone());
    }
}
  
Фрагмент 2: Фабричный метод
  
unique_ptr<Unit> InfantryFactory::createUnit(const string& variant, int x, int y) const {
  
    if (variant == "swordsman")
        return make\_unique<Swordsman>(x, y, Health(120), Armor(20), Attack(35));
    if (variant == "spearman")
    return make_unique<Spearman>(x, y, Health(100), Armor(15), Attack(40));
    return nullptr;
}
  
Фрагмент 3: Проверка границ при перемещении
  
void Swordsman::move(int dx, int dy, int maxW, int maxH) {

  
    int nx = x() + dx;
  
    int ny = y() + dy;
  
    if (nx < 0) nx = 0;
  
    if (nx >= maxW) nx = maxW - 1;
  
    if (ny < 0) ny = 0;
  
    if (ny >= maxH) ny = maxH - 1;
  
    setPosition(nx, ny);
  
}
  
5) Код выводит:
  
"1) Создание поля и юнитов
  
Поле (5 юнитов)
  
X X X X X X X X X X X X X X X X X X X X X X
  
X X
  
X S P X
  
X X
  
X L H X
  
X X
  
X C X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X X X X X X X X X X X X X X X X X X X X X
  
Список юнитов:
  
\[Infantry/Swordsman\] Swordsman (x=1, y=1) HP=120 Armor=20 Atk=35

  
\[Infantry/Spearman\] Spearman (x=2, y=1) HP=100 Armor=15 Atk=40

  
\[Archer/Light\] LightArcher (x=3, y=3) HP=70 Armor=5 Atk=45

  
\[Archer/Heavy\] HeavyArcher (x=4, y=3) HP=90 Armor=10 Atk=50

  
\[Cavalry/Cataphract\] Cataphract (x=5, y=5) HP=160 Armor=40 Atk=55

  
2) Копирование поля
  
Оригинал (1,1): \[Infantry/Swordsman\] Swordsman (x=1, y=1) HP=120 Armor=20 Atk=35

  
Копия (1,1): \[Infantry/Swordsman\] Swordsman (x=1, y=1) HP=90 Armor=20 Atk=35

  
3) Перемещение поля
  
После move размер оригинала = 0
  
Размер перемещённого поля = 5
  
4) Перемещение юнита (проверка границ)
  
До: \[Cavalry/Cataphract\] Cataphract (x=5, y=5) HP=160 Armor=40 Atk=55

  
После: \[Cavalry/Cataphract\] Cataphract (x=19, y=19) HP=160 Armor=40 Atk=55

  
5) Ошибки границ, лимита и занятой клетки
  
Ожидаемо: клетка (5,5) занята.

  
Ожидаемо: координата (100,100) вне поля.

  
Ожидаемо: превышен лимит maxUnits (5).

  
6) Удаление юнитов и проверка empty/clear
  
Поле (3 юнитов)
  
X X X X X X X X X X X X X X X X X X X X X X
  
X X
  
X X
  
X X
  
X L H X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X X
  
X C X
  
X X X X X X X X X X X X X X X X X X X X X X
  
Список юнитов:
  
\[Archer/Light\] LightArcher (x=3, y=3) HP=70 Armor=5 Atk=45

  
\[Archer/Heavy\] HeavyArcher (x=4, y=3) HP=90 Armor=10 Atk=50

  
\[Cavalry/Cataphract\] Cataphract (x=19, y=19) HP=160 Armor=40 Atk=55

  
После clear() поле пустое: да"
  
6)

| Этап | Критерий | Реализация |
|---------|---------|---------|
| 1 | Разбиение на файлы | 27 файлов .h/.cpp |
| 2 | Абстрактный класс Unit | Присутствует |
| 3 | Классы-атрибуты Health, Armor, Attack | Присутствуют |
| 4 | 3 типа юнитов, у каждого 2 вида | Cavalry, Archer, Infantry и их виды |
| 5 | Фабричный метод | UnitFactory и фабрики для типов юнитов |
| 6 | Базовые операции GameField | addUnit, removeUnit, clear, empty, size |
| 7 | Сценарии | 6 сценариев |