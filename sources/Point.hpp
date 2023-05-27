#pragma once
#include <iostream>

namespace ariel{
class Point
{
private:
    double coor_x;
    double coor_y;

public:
    Point():coor_x(0.0), coor_y(0.0){}
    Point(double c_x, double c_y):coor_x(c_x), coor_y(c_y){}

    double getX() const{return coor_x;}
    double getY() const{return coor_y;}

    double distance(const Point& other) const;
    std::string print() const;
    static Point moveTowards(const Point& origin, const Point& destination, double distance);
};
}
