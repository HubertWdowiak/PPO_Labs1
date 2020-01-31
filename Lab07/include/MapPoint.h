#pragma once
#include <iostream>

class MapDistance;

class MapPoint
{
    friend class MapDistance;
    std::string name;
    float longitude;
    float latitude;

    public:

    void SetId(std:: string);
    void Coordinates(float, float);    
    void Print();
    void Longitude(float);
    void Latitude(float);

    MapDistance Distance(MapPoint);
    MapPoint Farthest(MapPoint, MapPoint);
    MapPoint();
    MapPoint(std::string);
    MapPoint(std::string, float, float);

};