#pragma once
#include <iostream>

class Student
{
    public:

    Student(std::string = "", std::string = ""); // Konstruktor
    void Print() const; //Funkcja wypisujaca dane studenta

    private:

    std::string _name;  //Imie studenta
    std::string _surname;   //Nazwisko studenta
    int _id;    //Id studenta
    static int _ID;     //Licznik Id wszystkich studentow
};