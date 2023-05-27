#pragma once
#include <iostream>

#include "Ninja.hpp"

namespace ariel{
class OldNinja: public Ninja
{
    private:
    static const int D_SPEED = 8;
    static const int D_HIT = 150;

    public:
    OldNinja():Ninja("none", D_HIT, Point(), D_SPEED){}
    OldNinja(const std::string& name, const Point& loc):Ninja(name, D_HIT, loc, D_SPEED){}
    ~OldNinja() override = default;

    
    OldNinja(const OldNinja &) = delete;
    OldNinja &operator=(const OldNinja &) = delete;
    OldNinja(OldNinja &&) = delete;
    OldNinja &operator=(OldNinja &&) = delete;
};
}