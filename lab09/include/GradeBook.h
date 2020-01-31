#pragma once
#include "Grade.h"
class GradeBook 
{
public:
    void Insert( Grade* );
    void Insert( Grade*, std::string );
    void Insert( const Grade*, std::string );

    void Print();
    void AddGrade(float);
    void Summary();
    ~GradeBook();
private:

    static int counter;
    const Grade** tab;
    std::string* comments;
};
