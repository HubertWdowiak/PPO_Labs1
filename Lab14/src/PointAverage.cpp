#include "PointAverage.h"

void PointAverage::operator()(const Point2D& point)
{ 
    X += point.x;
    Y += point.y;
    counter++;
}

void PointAverage::Print() const
{
    std::cout << "Average Point:: (" << X/counter << "," << Y/counter <<")" << std::endl; 
}

void PointAverage::Reset()
{
    X = 0;
    Y = 0;
    counter = 0;
}