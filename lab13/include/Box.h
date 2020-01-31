#pragma once
#include <iostream>

class Box
{
    friend std::ostream& operator<< (std::ostream&, Box&);
    public:
    Box(double a, double b, double c): x(a), y(b), z(c) {};
    Box(size_t a, size_t b, size_t c): x(a), y(b), z(c) {};
    

    double GetWidth()const { return y; }
    double GetLength()const { return x; }
    double GetHeight()const { return z; }

    private:
    double x;
    double y; 
    double z;
};

