#include "BContainer.h"

std::ostream& operator<< (std::ostream& strm, Box& a)
{
    strm << "The largest box: Box(length:" << a.GetLength() << ", width:" << a.GetWidth() <<", height:" << a.GetHeight() << ")\n";
    return strm;
}

void BContainer::Insert(Box* a)
{
    size_ += 1;
    Box** tmp = new Box* [size_];

    if(size_ != 1)
    {
        for( int i=0; i<size_-1; i++)
        {
            if(tab[i])
            tmp[i] = tab[i];
        }
        tmp[size_-1] = a;
        if(tab)
            delete[] tab;
        tab = tmp;
    }
    else
    {
        tmp[0] = a;
        tab = tmp;
    }
}
std::ostream& operator<<(std::ostream& strm, BContainer& a)
{
    std::cout << "Box Container:\n" << std::endl;
    for( int i=0; i< a.size_; i++)
    {
        strm << "[" << i << "] Box(length:" << a[i]->GetLength() << ", width:" << a[i]->GetWidth() <<", height:" << a[i]->GetHeight() << ")\n";
    }
    return strm;
}
Box* BContainer::operator[](int a)
{
    return tab[a];
}

