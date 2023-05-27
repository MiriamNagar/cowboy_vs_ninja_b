#pragma once
#include <iostream>

#include "Point.hpp"

namespace ariel{
class Character
{
    private:
    Point location;
    int hit_points;
    std::string name;
    bool isMember = false;

    public:
    Character():name("none"), hit_points(0){}
    Character(const std::string& name, const Point& loc, int hit):name(name), location(loc), hit_points(hit){}
    virtual ~Character(){}

    virtual bool isAlive() const;
    virtual double distance(const Character* other) const;
    virtual void hit(int hits);
    virtual std::string getName() const{return name;}
    virtual const Point& getLocation() const{return location;}
    virtual std::string print() const;

    virtual bool getMember(){return isMember;}
    virtual void setMember(bool member){isMember = member;}
    virtual void setLocation(Point other){this->location = other;}
    virtual int getHitP() const {return hit_points;}

    Character(const Character&) = delete; // delete copy constructor
    Character& operator=(const Character&) = delete; // delete copy assignment operator
    Character(Character&&) = delete; // delete move constructor
    Character& operator=(Character&&) = delete; // delete move assignment operator
};
}