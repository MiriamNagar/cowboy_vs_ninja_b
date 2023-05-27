#pragma once
#include <iostream>

#include "Character.hpp"

namespace ariel{
class Cowboy: public Character
{
    private:
    static const int D_BULLETS = 6;
    static const int D_HIT = 110;
    int bullets;

    public:
    Cowboy():Character("none", Point(), D_HIT),bullets(D_BULLETS){}
    Cowboy(const std::string& name, const Point& loc):Character(name, loc, D_HIT), bullets(D_BULLETS){}
    ~Cowboy() override{}

    void shoot(Character* other);
    bool hasboolets() const;
    void reload();
    std::string print() const override;

    int getBullets() const{return bullets;}

    //for smart team
    bool shootSuccess(Character* other);

    Cowboy(const Cowboy &) = delete;
    Cowboy &operator=(const Cowboy &) = delete;
    Cowboy(Cowboy &&) = delete;
    Cowboy &operator=(Cowboy &&) = delete;
};
}