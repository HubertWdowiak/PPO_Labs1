#pragma once
#include <iostream>
class MapPoint;
class Coordinates
{
    friend float surfaceTriangleArea(MapPoint*, MapPoint*, MapPoint*);
    friend class MapPoint;
    public:

    Coordinates();
    Coordinates(float, float);

    void Latitude(float);
    void Longitude(float);
    void Set(float, float);

    private:

    float longitude;
    float latitude;
};