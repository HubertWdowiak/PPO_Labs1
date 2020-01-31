#include <iostream>
typedef float SeriesType;
typedef SeriesType* SeriesPtr;
typedef int Size;
typedef SeriesType(*SeriesFunctionPtr)(SeriesPtr array, Size);


//funkcja wypisuje wszystkie elementy ciagu
void PrintSeries(SeriesPtr, Size);

//funkcja inicjalizuje odpowiednia ilosc pamieci dla ciagu
SeriesPtr InitializeHarmonicSeries(Size);

//funkcja zwraca sume wszystkich elementow ciagu
SeriesType SeriesSum(SeriesPtr, Size);

//funkcja wywoluje okreslona funkcje(pierwszy argument) dla wybranego ciagu 
void RunAndPrint(SeriesFunctionPtr, SeriesPtr, Size);

// funkcja zwalnia pamiec zajeta przez ciag
void DeleteSeries();

// funkcja zwraca iloczyn elementow ciagu
SeriesType SeriesProduct(SeriesPtr, Size);

// funkcja zwraca maksymalny element ciagu
SeriesType SeriesMax(SeriesPtr, Size);

//funkcja zwraca minimalny element ciagu
SeriesType SeriesMin(SeriesPtr, Size);