#include "GameField.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

GameField::GameField(int width, int height, int maxUnits)
    : width_(width), height_(height), maxUnits_(maxUnits) {
    if (width <= 0 || height <= 0 || maxUnits <= 0)
        throw std::invalid_argument("Invalid field dimensions");
}

GameField::GameField(const GameField& other)
    : width_(other.width_), height_(other.height_), maxUnits_(other.maxUnits_) {
    units_.reserve(other.units_.size());
    for (const auto& u : other.units_) {
        units_.push_back(u->clone());
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this == &other) return *this;
    GameField tmp(other);
    swap(width_, tmp.width_);
    swap(height_, tmp.height_);
    swap(maxUnits_, tmp.maxUnits_);
    units_.swap(tmp.units_);
    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width_(other.width_), height_(other.height_),
    maxUnits_(other.maxUnits_), units_(std::move(other.units_)) {
    other.width_ = other.height_ = other.maxUnits_ = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this == &other) return *this;
    units_ = std::move(other.units_);
    width_ = other.width_;
    height_ = other.height_;
    maxUnits_ = other.maxUnits_;
    other.width_ = other.height_ = other.maxUnits_ = 0;
    return *this;
}

GameField::~GameField() = default;

bool GameField::isOccupied(int x, int y) const {
    for (const auto& u : units_)
        if (u->x() == x && u->y() == y) return true;
    return false;
}

bool GameField::addUnit(unique_ptr<Unit> unit) {
    if (!unit) return false;
    if (static_cast<int>(units_.size()) >= maxUnits_) return false;
    if (!isInside(unit->x(), unit->y())) return false;
    if (isOccupied(unit->x(), unit->y())) return false;
    units_.push_back(move(unit));
    return true;
}

bool GameField::spawn(const UnitFactory& factory, const string& type, int x, int y) {
    return addUnit(factory.createUnit(type, x, y));
}

bool GameField::removeUnitAt(int x, int y) {
    auto it = std::find_if(units_.begin(), units_.end(),
        [x, y](const unique_ptr<Unit>& u) { return u->x() == x && u->y() == y; });
    if (it == units_.end()) return false;
    units_.erase(it);
    return true;
}

bool GameField::removeUnitAt(size_t index) {
    if (index >= units_.size()) return false;
    units_.erase(units_.begin() + static_cast<std::ptrdiff_t>(index));
    return true;
}

Unit* GameField::getUnit(int x, int y) {
    for (auto& u : units_)
        if (u->x() == x && u->y() == y) return u.get();
    return nullptr;
}

const Unit* GameField::getUnit(int x, int y) const {
    for (const auto& u : units_)
        if (u->x() == x && u->y() == y) return u.get();
    return nullptr;
}

Unit* GameField::getUnit(size_t index) {
    return index < units_.size() ? units_[index].get() : nullptr;
}

void GameField::draw() const {
    cout << "X";
    for (int x = 0; x < width_; ++x) cout << " X";
    cout << " X\n";
    for (int y = 0; y < height_; ++y) {
        cout << "X";
        for (int x = 0; x < width_; ++x) {
            const Unit* u = getUnit(x, y);
            if (u) {
                char c = '?';
                const string& t = u->type();
                if (t.find("Swordsman") != string::npos) c = 'S';
                else if (t.find("Spearman") != string::npos) c = 'P';
                else if (t.find("Light") != string::npos) c = 'L';
                else if (t.find("Heavy") != string::npos) c = 'H';
                else if (t.find("Cataphract") != string::npos) c = 'C';
                else if (t.find("HorseArcher") != string::npos) c = 'A';
                cout << " " << c;
            }
            else {
                cout << "  ";
            }
        }
        cout << " X\n";
    }
    cout << "X";
    for (int x = 0; x < width_; ++x) cout << " X";
    cout << " X\n";
}