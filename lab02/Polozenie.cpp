#include "Polozenie.h"
#include "Operacje.h"
#include "PolozeniePoczatkowe.h"
#include "Czas.h"
#include "Predkosc.h"
#include "Przyspieszenie.h"
#include <iostream>
float Polozenie()
{
    float tpow2 = iloczyn(Czas(), Czas());
    float y = iloczyn(Przyspieszenie(), tpow2)/2;
    float z = iloczyn(Predkosc(), Czas());
    return y + z + PolozeniePoczatkowe();
}