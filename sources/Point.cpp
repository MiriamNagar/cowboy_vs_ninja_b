#include <iostream>
#include "cmath"
#include "Point.hpp"

using namespace std;
using namespace ariel;

double Point::distance(const Point& other) const
{
    double x = this->getX() - other.getX();
    double y = this->getY() - other.getY();
    return sqrt(x*x + y*y);
}

std::string Point::print() const
{
    return "(" + to_string(getX()) + ", " + to_string(getY()) + ")" ;
}

Point Point::moveTowards(const Point& origin, const Point& destination, double distance)
{
    if(distance < 0) throw invalid_argument("Error: distance argument needs to be positive.");
    double currDistance = origin.distance(destination);
    if (currDistance < distance) return Point(destination.getX(), destination.getY());
    double div;
    if(currDistance <= 0) div = 0;
    else div = distance / currDistance;
    double newX = origin.getX() + div * (destination.getX() - origin.getX());
    double newY = origin.getY() + div * (destination.getY() - origin.getY());

    return Point(newX, newY);
}

