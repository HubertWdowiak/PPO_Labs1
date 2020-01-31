#include "StudentsList.h"

int StudentsList::_counter = 0;

StudentsList::StudentsList( std::string a )
{
    _tab = new const Student*[_counter];
    _description = a;
}
void StudentsList::PrintInfo() const
{
    std::cout << "[StudentsList]: " << _description << std::endl;
}
void StudentsList::AddStudent( Student* a )
{
    _counter++;
    const Student** _tab2 = new const Student*[_counter];
    for( int i=0; i<_counter-1;  i++)
    {
        _tab2[i] = _tab[i];
    }
    _tab2[_counter-1] = a;
    delete[] _tab;
    _tab = _tab2;
}
void StudentsList::AddStudent(const Student* a )
{
    _counter++;
    const Student** _tab2 = new const Student*[_counter];
    for( int i=0; i<_counter-1; i++)
    {
        _tab2[i] = _tab[i];
    }
    _tab2[_counter-1] = a;
    delete[] _tab;
    _tab = _tab2;
}
void StudentsList::PrintList()const
{
    PrintInfo();
    for( int i=0; i<_counter; i++)
    {
        _tab[i]->Print();
        std::cout << std::endl;
    }
}
StudentsList::~StudentsList()
{
    for( int i=0; i<_counter; i++)
        delete _tab[i];
    delete[] _tab;
    
}
StudentsList::StudentsList(StudentsList&  a ) : _description {""}
{
    _tab = new const Student*[a._counter];
    for( int i=0; i<a._counter; i++)
    {
        _tab[i] = new const Student( *(a._tab[i]) );
    }

} 
StudentsList::StudentsList(StudentsList&&  a ) : _description {""}
{
    _tab = new const Student*[a._counter];
    for( int i=0; i<a._counter; i++)
    {
        _tab[i] = new const Student( *(a._tab[i]) );
    }
} 
