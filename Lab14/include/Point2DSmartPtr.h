#pragma once

#include "Point2D.h"

class Point2DSmartPtr
{
	using T = Point2D;
	using TP = T*;

public:
	Point2DSmartPtr(const TP raw = nullptr) : raw(raw) {}

	Point2DSmartPtr(const Point2DSmartPtr& vec) = delete;

	/// free old pointer and assign new one
	Point2DSmartPtr& operator=(const TP ptr)
	{
		if(raw)
			delete raw;

		raw = ptr;
		return (*this);
	}

	~Point2DSmartPtr() 
	{ 
		std::cout << "Point2D:: zwalnianie wskaznika" << std::endl;
		delete raw; 
	}

	/// getter for raw pointer
	TP get() const { return raw; }

	/// dereference operator
	T& operator*() const { return *raw; }

	/// arrow operator
	TP operator->() const { return raw; }
private:
	TP raw;
};