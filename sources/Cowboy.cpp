
#include <iostream>

#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

void Cowboy::shoot(Character* other)
{
    if(!isAlive() || !other->isAlive()) throw runtime_error("ERROR: Cowboy/enemy is dead, can't slash"); 
    if (this == other) throw runtime_error("ERROR: same person, can't slash itself");
    if(this->hasboolets())
    {
        other->hit(10);
        this->bullets--;
    }
}

bool Cowboy::shootSuccess(Character* other)
{
    if(!isAlive()) return false;
    if(!this->hasboolets()) return false;
    if (this == other) return false;
    return true;
}

bool Cowboy::hasboolets() const
{
    return this->bullets > 0;
}

void Cowboy::reload()
{
    if(isAlive()){
        this->bullets = 6;
    }
    else throw runtime_error("Error: can't load, cowboy dead.");
}

std::string Cowboy::print() const{
    return "C: " + Character::print();
}