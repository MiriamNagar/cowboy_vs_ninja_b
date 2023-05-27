#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;
using namespace ariel;


bool Character::isAlive() const
{
    return getHitP() > 0;
}

double Character::distance(const Character* other) const
{
    return getLocation().distance(other->getLocation());
}

void Character::hit(int hits)
{
    if (hits < 0) throw invalid_argument("entered negative hit points");
    if(hits > this->getHitP()) this->hit_points = 0;
    else this->hit_points -= hits;
}

string Character::print() const
{
    string res = "";
    if(!isAlive()){
        res += "(" + this->getName() + ")";
    } else{
        res += "Name: " + getName() +"\nHit points: " + to_string(getHitP()) + "\nLocation: (" + to_string(getLocation().getX()) + ","+to_string(getLocation().getY())+")";
    }
    return res;
}
