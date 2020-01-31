#pragma once
class Volume
{
    public:
    double operator() (double a, double b, double c){ return a*b*c; }
    double operator() (Box a)
    {
        return a.GetWidth() * a.GetHeight() * a.GetLength();
    }
};

Box* find_box_optimum( BContainer x, bool func (Box&, Box&))
{
    Box* max = x[0];
    for( int i=0; i<x.size_-1; i++)
    {
        if(func(*x[i], *max) == true)
            max = x[i];
        else max = max;
    }
    return max;
}
bool larger (Box& a, Box& b)
{
    if(a.GetHeight()*a.GetLength()*a.GetWidth() >= b.GetHeight()*b.GetLength()*b.GetWidth())
        return true;
    else return false;
}