#include <iostream>
#include "MapPoint.h"
#include "MapDistance.h"
#include <math.h>
MapPoint* tab[10] = {};
int counter = 0;

MapDistance MapPoint::Distance(MapPoint a)
{
    MapDistance dist = MapDistance(*this,  a);
    return dist;
}

void MapPoint::SetId(std::string name2)
{
    this-> name = name2;
}
void MapPoint::Coordinates(float a, float b)
{
    this-> longitude = a;
    this-> latitude = b;
}
void MapPoint::Print()
{
    std::cout << this->name << " (" << this->longitude << ", "
    << this->latitude << ")" << std::endl;
}
void MapPoint::Longitude(float a)
{
    this->longitude = a;
}
void MapPoint::Latitude(float a)
{
    this->latitude = a;
}
MapPoint::MapPoint()
{
    this -> name = "";
    this ->longitude = 0;
    this -> latitude = 0;
    tab[counter] = this;
    counter +=1;
}
MapPoint::MapPoint(std::string name2)
{  
    this->name = name2;
    this->longitude = 0;
    this->latitude = 0;
    tab[counter] = this;
    counter +=1;
}
MapPoint::MapPoint(std::string name2, float a, float b)
{
    this->name = name2;
    this->longitude = a;
    this->latitude = b;
    tab[counter] = this;
    counter +=1;
}
MapPoint MapPoint::Farthest(MapPoint a, MapPoint b)
{
    float deltaX1 = a.latitude-this->latitude;
    float deltaY1 = a.longitude-this->longitude;
    float deltaX2 = b.latitude-this->latitude;
    float deltaY2 = b.longitude-this->longitude;
    
    float z1 = sqrt(deltaX1*deltaX1 + deltaY1* deltaY1);
    float z2 = sqrt(deltaX2*deltaX2 + deltaY2* deltaY2);
    
    if(z1>z2)
        return a;
    else 
        return b;
}