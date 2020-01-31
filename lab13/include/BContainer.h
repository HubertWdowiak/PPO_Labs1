#pragma once
#include <iostream>
#include "Box.h"
class BContainer
{
    public:
    friend std::ostream& operator<<(std::ostream&, BContainer&); 
    int size_;

    BContainer() 
    { 
        tab = nullptr; 
        size_ = 0;
    }
    ~BContainer()
    {
        for( int i=0; i<size_; i++ )
        {
            if( tab[i] )
            {
                delete tab[i];
                tab[i] = nullptr;
            }
        }
        if(tab)
        {
            delete[] tab;
            tab = nullptr;
            size_= 0;
        }
    }
    void Insert(Box*);
    Box* operator[](int);

    private:
    Box** tab;
};