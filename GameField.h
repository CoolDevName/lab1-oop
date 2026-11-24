#pragma once
#include <memory>
#include <vector>
#include <cstddef>
#include <iterator>
#include "Unit.h"
#include "UnitFactory.h"


using namespace std;

class GameField {
public:
    class Iterator {
    public:
        using iterator_category = forward_iterator_tag;
        using value_type = Unit;
        using difference_type = ptrdiff_t;
        using pointer = Unit*;
        using reference = Unit&;

        Iterator(std::vector<std::unique_ptr<Unit>>* v, std::size_t idx)
            : vec_(v), idx_(idx) {
        }

        Unit& operator*()  const { return *(*vec_)[idx_]; }
        Unit* operator->() const { return  (*vec_)[idx_].get(); }

        Iterator& operator++() { ++idx_; return *this; }
        Iterator  operator++(int) { Iterator t = *this; ++idx_; return t; }

        bool operator==(const Iterator& o) const { return idx_ == o.idx_; }
        bool operator!=(const Iterator& o) const { return idx_ != o.idx_; }

    private:
        vector<std::unique_ptr<Unit>>* vec_;
        size_t idx_;
    };

    class ConstIterator {
    public:
        using iterator_category = forward_iterator_tag;
        using value_type = Unit;
        using difference_type = ptrdiff_t;
        using pointer = const Unit*;
        using reference = const Unit&;

        ConstIterator(const vector<std::unique_ptr<Unit>>* v, size_t idx)
            : vec_(v), idx_(idx) {
        }

        const Unit& operator*()  const { return *(*vec_)[idx_]; }
        const Unit* operator->() const { return  (*vec_)[idx_].get(); }

        ConstIterator& operator++() { ++idx_; return *this; }
        ConstIterator  operator++(int) { ConstIterator t = *this; ++idx_; return t; }

        bool operator==(const ConstIterator& o) const { return idx_ == o.idx_; }
        bool operator!=(const ConstIterator& o) const { return idx_ != o.idx_; }

    private:
        const vector<std::unique_ptr<Unit>>* vec_;
        size_t idx_;
    };

    GameField(int width, int height, int maxUnits);
    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept;
    ~GameField();

    int width()  const { return width_; }
    int height() const { return height_; }
    int maxUnits() const { return maxUnits_; }
    std::size_t size() const { return units_.size(); }
    bool empty() const { return units_.empty(); }
    void clear() { units_.clear(); }

    bool isInside(int x, int y) const {
        return x >= 0 && x < width_ && y >= 0 && y < height_;
    }
    bool isOccupied(int x, int y) const;

    bool addUnit(unique_ptr<Unit> unit);
    bool spawn(const UnitFactory& factory, const string& type, int x, int y);

    bool removeUnitAt(int x, int y);
    bool removeUnitAt(size_t index);

    Unit* getUnit(int x, int y);
    const Unit* getUnit(int x, int y) const;
    Unit* getUnit(size_t index);

    Iterator begin() { return Iterator(&units_, 0); }
    Iterator end() { return Iterator(&units_, units_.size()); }

    ConstIterator begin() const { return ConstIterator(&units_, 0); }
    ConstIterator end()   const { return ConstIterator(&units_, units_.size()); }

    void draw() const;

private:
    int width_, height_, maxUnits_;
    vector<std::unique_ptr<Unit>> units_;
};