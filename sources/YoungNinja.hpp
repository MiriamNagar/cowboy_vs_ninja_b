#pragma once
#include <iostream>

#include "Ninja.hpp"

namespace ariel{
class YoungNinja: public Ninja
{
    private:
    static const int D_SPEED = 14;
    static const int D_HIT = 100;

    public:
    YoungNinja():Ninja("none", D_HIT, Point(), D_SPEED){}
    YoungNinja(const std::string& name, const Point& loc):Ninja(name, D_HIT, loc, D_SPEED){}
    ~YoungNinja() override = default;


    YoungNinja(const YoungNinja &) = delete;
    YoungNinja &operator=(const YoungNinja &) = delete;
    YoungNinja(YoungNinja &&) = delete;
    YoungNinja &operator=(YoungNinja &&) = delete;
};
}