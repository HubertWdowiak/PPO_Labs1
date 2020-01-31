#include <iostream>
#include "MyString.h"
#include <cstring>


MyString::MyString(const char* sentence)
{
    _size=strlen(sentence);
    _sentence = new char[_size+1];
    for(size_t i=0; i<_size; i++)
    {
        _sentence[i]=sentence[i];
    }
    _sentence[_size]='\0';
}

MyString::~MyString()
{
    if(_sentence != nullptr) 
    {
        delete [] _sentence;
        _sentence = nullptr;
    }
}

bool MyString::operator==(const MyString s1) const
{
    if(_size == s1._size)
    {
            for(size_t i=0; i<_size; i++)
            {
                if(_sentence[i]!=s1._sentence[i])
                    return 0;
            }
            return 1;
    }
    else return 0;
}

MyString MyString::operator*(int a)
{

    size_t size=_size*a;
    char tab[size];
    for(size_t i=0; i<size; i++)
        tab[i]=_sentence[i%_size];
    tab[size-1]='\0';
    MyString* mS=new MyString(tab);
    return *mS;
}

MyString MyString::operator=(MyString s1)
{
    this->_size = s1._size;
    delete[] this->_sentence;
    this->_sentence = new char[_size];
    for( int i=0; i<_size; i++)
    {
        this->_sentence[i] = s1._sentence[i];
    }
    return *this;
}

char& MyString::operator[](int a)
{
    return _sentence[a];
}

void MyString::Print() const
{
    for(size_t i=0; i<_size+1; i++)
        std::cout<<_sentence[i];
    std::cout<<std::endl;
}

MyString MyString::substr(const int a, const int b) const 
{
    MyString temp;
    temp._size = b-a+1;
    for(int i=a; i<=b; i++)
        temp._sentence[i-a]=_sentence[i];
    return temp;
}
