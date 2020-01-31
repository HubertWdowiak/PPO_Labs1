#pragma once
#include <iostream>
#include "Student.h"

class StudentsList
{

    public:

    StudentsList( std::string = ""); // Konstruktor
    StudentsList( StudentsList& ); //Konstruktor kopiujacy
    StudentsList( StudentsList&& ); //Konstruktor kopiujacy z rvalue
    ~StudentsList(); //Destruktor
    void PrintInfo() const; // Funkcja wypisujaca opis listy studentow
    void AddStudent( Student* );   //Funkcja dodajaca studenta do listy
    void AddStudent( const Student* ); //Funkcja dodajaca studenta do listy
    void PrintList() const; //Funkcja wypisujaca opis listy i wszystkich studentow
    
    private:

    std::string _description; // Opis listy
    const Student** _tab; //Tablica do przechowania studentow
    static int _counter; //Licznik studentow w tablicy
};