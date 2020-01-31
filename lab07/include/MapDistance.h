#pragma once
#include "MapPoint.h"
class MapDistance
{
    float longDist;
    float latDist;
    std::string name1;
    std::string name2;

    public:

    void Print();

    MapDistance(MapPoint, MapPoint);
    MapDistance();
};