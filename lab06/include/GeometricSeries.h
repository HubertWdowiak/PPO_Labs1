#pragma once
#include <iostream>
#include "HarmonicSeries.h"
//#include "counter.h"

//funkcja wypisuje wszystkie elementy ciagu
void PrintSeries(SeriesPtr, Size);

//funkcja inicjalizuje odpowiednia ilosc pamieci dla ciagu
SeriesPtr InitializeGeometricSeries(Size, float);

//funkcja zwraca sume wszystkich elementow ciagu
SeriesType SeriesSum(SeriesPtr, Size);

//funkcja wywoluje okreslona funkcje(pierwszy argument) dla wybranego ciagu 
void RunAndPrint(SeriesFunctionPtr, SeriesPtr, Size);

// funkcja zwalnia pamiec zajeta przez ciag
void DeleteSeries(SeriesPtr const*);

// funkcja zwraca iloczyn elementow ciagu
SeriesType SeriesProduct(SeriesPtr, Size);

// funkcja zwraca maksymalny element ciagu
SeriesType SeriesMax(SeriesPtr, Size);

//funkcja zwraca minimalny element ciagu
SeriesType SeriesMin(SeriesPtr, Size);
