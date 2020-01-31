#include <iostream>
#include "MapPoint.h"

int MapPoint::pointNum = 0;
int MapPoint::NumberOfPoints()
{
    return pointNum;
} 
MapPoint::MapPoint()
{
    name = "";
    Coor = Coordinates();
    pointNum ++;
}
MapPoint::MapPoint(std::string name)
{
    this->name = name;
    Coor = Coordinates();
    pointNum ++;

}
MapPoint::MapPoint(std::string name, float a, float b)
{
    this->name = name;
    Coor = Coordinates(a,b);
    pointNum ++;
}
void MapPoint::Print() const
{
    std::cout << "Point: "<< name <<" (" << Coor.latitude << ", " << Coor.longitude <<")\n";
}
void MapPoint::SetId(std::string name)
{
    this->name = name;
}
Coordinates* MapPoint::GetCoordinatesPtr()
{
    return &Coor;
}
float surfaceTriangleArea(MapPoint* a, MapPoint* b, MapPoint* c)
{
    float x1 = a->GetCoordinatesPtr()->latitude;
    float x2 = b->GetCoordinatesPtr()->latitude;
    float x3 = c->GetCoordinatesPtr()->latitude;
    float y1 = a->GetCoordinatesPtr()->longitude;
    float y2 = b->GetCoordinatesPtr()->longitude;
    float y3 = c->GetCoordinatesPtr()->longitude;

    float area = 1.0/2.0 * ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
    return area;
}