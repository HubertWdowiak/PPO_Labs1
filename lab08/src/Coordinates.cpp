#include <iostream>
#include "Coordinates.h"

Coordinates::Coordinates()
{
    longitude = 0;
    latitude = 0;
}
Coordinates::Coordinates(float a, float b)
{
    longitude = b;
    latitude = a;
}
void Coordinates::Longitude(float a)
{
    longitude = a;
}
void Coordinates::Latitude(float a)
{
    latitude = a;
}
void Coordinates::Set(float a, float b)
{
    longitude = b;
    latitude = a;
}