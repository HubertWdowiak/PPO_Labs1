#include "Student.h"

int Student::_ID = 0;

Student::Student(std::string a, std::string b)
{
    _ID++;
    _name = a;
    _surname = b;
    _id = _ID;
}
void Student::Print() const
{
    std::cout << "Student ID: " << _id << ", Name: " << _name <<", Surname: " << _surname;
}
