#pragma once
#include <iostream>
#include "Coordinates.h"

class MapPoint
{
    public:

    friend float surfaceTriangleArea(MapPoint*, MapPoint*, MapPoint*);

    MapPoint(std::string);
    MapPoint(std::string, float, float);
    MapPoint();

    void Print() const;
    Coordinates* GetCoordinatesPtr();
    void SetId(std::string);
    static int NumberOfPoints();



    private:

    static int pointNum;
    Coordinates Coor;
    std::string name;
};