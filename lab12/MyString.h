#pragma once
#include <iostream>
#include <cstring>

class MyString{

    //zmienna przechowujaca wyraz

     char*_sentence;
    
    //zmienna przechowujaca rozmiar wyrazu

     size_t _size;

  public:

    //konstruktor klasy MyString

    MyString(const char* sentence="");
    
    //destruktor klasy MyString

    ~MyString();
    
    //operator porownania klas MyString

    bool operator==(const MyString s1) const;
    
    //operator mnozenia klasy MyString przez inta
    
    MyString operator*(int a);

    //operator przypisania klas MyString

    MyString operator=(MyString s1);
    
    //operator tablicowy 

    char& operator[](int a);
    
    //funkcja wypisujaca wyraz przechowywany w klasie MyString

    void Print() const;
    
    //funkcja zwracajaca fragment wyrazu, ograniczony podanymi indeksami

    MyString substr(const int a, const int b) const;

};