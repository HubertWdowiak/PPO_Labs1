#pragma once
#include <iostream>

class GradeBook;

class Grade
{
    friend class GradeBook;

public:

    Grade( float );

    void Print()
    {
        std::cout << "Grade ID=" << _id << " value=" << _mark;
    }

private:

    float _mark;
    int _id;
    static int ID;
};

