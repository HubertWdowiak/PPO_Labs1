#pragma once

#include <iostream>

class PointAverage;

class Point2D
{
public:
	friend PointAverage;
	friend Point2D& operator+(const double x, const Point2D& point);

	Point2D(const double x = 0, const double y = 0) : x(x), y(y) {}

	/// overloaded new for printing additional info about block size
	void* operator new(size_t size);

	/// assignment operator
	Point2D& operator=(const Point2D& point);
	Point2D operator+(const Point2D& point);

	Point2D operator++(int t);
	Point2D& operator--();

	void Print() const;
private:
	double x, y;
};

Point2D operator+(const double x, Point2D& point);