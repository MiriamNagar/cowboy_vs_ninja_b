#pragma once
#include <iostream>

#include "Ninja.hpp"

namespace ariel{
class TrainedNinja: public Ninja
{
    private:
    static const int D_SPEED = 12;
    static const int D_HIT = 120;
    
    public:
    TrainedNinja():Ninja("none", D_HIT, Point(), D_SPEED){}
    TrainedNinja(const std::string& name, const Point& loc):Ninja(name, D_HIT, loc, D_SPEED){}
    ~TrainedNinja() override = default;


    TrainedNinja(const TrainedNinja &) = delete;
    TrainedNinja &operator=(const TrainedNinja &) = delete;
    TrainedNinja(TrainedNinja &&) = delete;
    TrainedNinja &operator=(TrainedNinja &&) = delete;
};
}