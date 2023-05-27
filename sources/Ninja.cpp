#include <iostream>
#include "Ninja.hpp"

using namespace std;
using namespace ariel;


void Ninja::move(const Character* other)
{
    Point newLoc = Point::moveTowards(this->getLocation(), other->getLocation(), this->getSpeed());
    setLocation(newLoc);
}

void Ninja::slash(Character* other)
{
    if(!isAlive() || !other->isAlive()) throw runtime_error("ERROR: Ninja/enemy is dead, can't slash"); 
    if (this == other) throw runtime_error("ERROR: same person, can't slash itself");
    if(this->distance(other) <= 1.0) other->hit(40);
}

bool Ninja::slashSuccess(Character* other) const
{
    if(!isAlive()) return false;
    if(this->distance(other) > 1.0) return false;
    if (this == other) return false;
    return true;
}

string Ninja::print() const {
    return "N: " + Character::print();
}
