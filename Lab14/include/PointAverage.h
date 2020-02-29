#pragma once

#include <iostream>
#include "Point2D.h"

class PointAverage
{
public:
	PointAverage() = default;

	/// function operator realising partial sums
	void operator()(const Point2D& point);

	/// compute and print average
	void Print() const;
	
	/// reset all private variables
	void Reset();

private:
	double X = 0;
	double Y = 0;
	size_t counter = 0;
};
