#include "MapDistance.h"
#include <iostream>
void MapDistance::Print()
{
    if(name1 != "")
    {
        std::cout <<"Distance : " << name1 <<"-" << name2 << " ("<< this->longDist << ", " 
        << this->latDist << ")" << std::endl;
    }
    else
    {
        std::cout << "Dostance : None(0, 0)" << std::endl;
    }
}
MapDistance::MapDistance(MapPoint a, MapPoint b)
{
    name1 = a.name;
    name2 = b.name;
    longDist = a.longitude - b.longitude;
    latDist = a.latitude - b.latitude;
    if(longDist < 0)  this->longDist *=(-1);
    if(latDist < 0)  this->latDist *=(-1);
}
MapDistance::MapDistance()
{
    name1 ="";
    name2 = "";
    latDist = 0;
    longDist = 0;
}