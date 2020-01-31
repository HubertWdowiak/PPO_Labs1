#include "Grade.h"
#include <iostream>

int Grade::ID = 1;

Grade::Grade(float a)
{
    _mark = a;
    _id = ID;
    ID++;
}