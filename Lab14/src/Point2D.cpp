#include "Point2D.h"

Point2D& Point2D::operator=(const Point2D& point)
{ 
	x = point.x;
	y = point.y;
	return (*this);
}

Point2D Point2D::operator+(const Point2D& point)
{ 
	return Point2D(x+point.x, y+point.y);
}


Point2D operator+(const double x, Point2D& point)
{ 
	return point.operator+(Point2D(x));
}

void* Point2D::operator new(size_t size)
{
	std::cout<<"Point2D:: alokowanie "<<size<<" bajtow"<<std::endl;
	return ::new Point2D;
}

Point2D Point2D::operator++(int t)
{ 
	Point2D temp(x++, y++);
	return temp;
}

Point2D& Point2D::operator--()
{ 
	--x;
	--y;
	return (*this);
}

void Point2D::Print() const
{
	std::cout<<"Point2D:: ("<<x<<","<<y<<")"<<std::endl;
}