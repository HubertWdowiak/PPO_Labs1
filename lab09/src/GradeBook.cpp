#include "GradeBook.h"
#include <iostream>

int GradeBook::counter = 0;

void GradeBook::Insert( Grade* a)
{
    counter++;
    const Grade** tab2 = new const Grade*[counter];
    std::string* comments2 = new std::string[counter];

    for( int i=0; i<counter-1; i++)
    {
        tab2[i] = tab[i];
        comments2[i] = comments[i];
    }
    
    tab2[counter-1] = a;

    comments2[counter - 1] = "";
    tab = tab2;
    comments = comments2;
}
void GradeBook::Insert( Grade* a, std::string com)
{
    counter++;
    const Grade** tab2 = new const Grade*[counter];
    std::string* comments2 = new std::string[counter];

    for( int i=0; i<counter-1; i++)
    {
        tab2[i] = tab[i];
        comments2[i] = comments[i];
    }
    tab2[counter-1] = a;
    comments2[counter - 1] = com;

    delete[] comments;
    delete[] tab;
    tab = tab2;
    comments = comments2;
}
void GradeBook::Insert( const Grade* a, std::string com)
{
    counter++;
    const Grade** tab2 = new const Grade*[counter];
    std::string* comments2 = new std::string[counter];

    for( int i=0; i<counter-1; i++)
    {
        tab2[i] = tab[i];
        comments2[i] = comments[i];

    }
    tab2[counter-1] = a;
    comments2[counter - 1] = com;

    delete[] comments;
    delete[] tab;
    tab = tab2;
    comments = comments2;
}
void GradeBook::Print()
{
    std::cout <<"[GradeBook]: Set of grades in the book:\n";
    for( int i=0; i<counter; i++)
    {
        std::cout << "Grade ID=" << tab[i]->_id << " value=" << tab[i]->_mark;
        if(comments[i] != "")   std::cout <<" \"" <<  comments[i] << "\"";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void GradeBook::AddGrade(float a)
{
    counter++;
    const Grade** tab2 = new const Grade*[counter];
    std::string* comments2 = new std::string[counter];
    for( int i=0; i<counter-1; i++)
    {
        tab2[i] = tab[i];
        comments2[i] = comments[i];
    }
    tab2[counter-1] = new Grade(a);
    comments2[counter - 1] = "";
    delete[] comments;
    delete[] tab;
    tab = tab2;
    comments = comments2;

}
void GradeBook::Summary()
{
    std::cout << "[GradeBook]: Summary: Number of grades in the book: " << counter << std::endl;

    float suma = 0;
    for( int i=0; i<counter; i++)
    {
        suma += tab[i]->_mark;
    }
    suma /= counter;
    std::cout << "[GradeBook]: Summary: Average of grades: " << suma << std::endl;
}
GradeBook::~GradeBook()
{
    for( int i=0; i<counter;i++)
    {
        delete tab[i];
    }
    delete[] tab;
    delete[] comments;
}