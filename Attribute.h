#pragma once

template <typename T>
class Attribute {
protected:
    T value;
    explicit Attribute(T v) : value(v) {}
public:
    T getValue() const { return value; }
    void setValue(T v) { value = v; }
};