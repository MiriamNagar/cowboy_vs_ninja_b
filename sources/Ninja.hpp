#pragma once
#include <iostream>

#include "Character.hpp"

namespace ariel{
class Ninja: public Character
{
    private:
    int speed;

    public:
    Ninja(): speed(0){}
    Ninja(const std::string& name,int hit, const Point& loc, int speed):Character(name, loc, hit), speed(speed){}
    ~Ninja() override{}

    void move(const Character* other);
    void slash(Character* other);

    int getSpeed()const{return speed;};
    std::string print() const override;

    bool slashSuccess(Character* other) const;

    Ninja(const Ninja &) = delete;
    Ninja &operator=(const Ninja &) = delete;
    Ninja(Ninja &&) = delete;
    Ninja &operator=(Ninja &&) = delete;
};

}