// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// *** ZADANIE ***
// Zadanie jest w znacznej części oparte o poprzednie 2 zajęcie. W zasadzie
// polega od odpowiednim połączeniu dotychczas zaimplementowanego kodu.
// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi geometryczne i harmoniczne zdefiniowane poniżej w kodzie 
// źródłowym funkcji main(). Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.

// Prosze zadbac o dobre zarzadzanie pamiecia oraz niepowtarzający sie kod 
// (o tej samej funkcjonalności)

// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// *** ORGANIZACJA/STRUKTURA PROGRAMU***
// W zadaniu należy skorzystać z programu cmake, tak więc rozwiązanie 
// powinno zawierać CMakeLists.txt
// Pliki z kodem źródłowym mają być zorganizowane z wykorzystaniem katalogów:
// /Lab06/
//       /CMakeLists.txt
//       /Main.cpp
//       /src/GeometricSeries.cpp
//       /src/HarmonicSeries.cpp
//       /src/*.cpp
//       /include/GeometricSeries.h
//       /include/HarmonicSeries.h
//       /include/*.h
// *.cpp (*.h) oznaczają inne pliki z kodem źródłowym, które mogą zostać dodane do projektu


// *** OGRANICZENIA ***
// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików, oprócz Makefile)

// Kody źródłowe muszą znajdować się w katalogu ~/preoop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla właściciela).

// Skonczone zadanie nalezy wyslac na UPEL w formie spakowanego katalogu (lab_06)
// do archiwum lab_06.tar.gz
// tar -czvf lab_06.tar.gz lab_06/

#include "GeometricSeries.h"
#include "HarmonicSeries.h"

int main ()
{
  const Size size = 4;      // rozmiar ciagu geometrycznego
  
  // GEOMETRIC SERIES
  // uwaga: pierwszy element ciagu to 1:
  //        a_0 = 1
  //        a_1 = a_0 * ratio
  //        a_2 = a_1 * ratio
  //        ...
  //        a_size-1 = a_size-2 * ratio

  const float ratio = 2;   // iloraz ciągu
  const SeriesPtr gSeriesPtr = InitializeGeometricSeries (size, ratio);

  // HARMONIC SERIES
  // uwaga: pierwszy element ciagu to 1:
  //        a_0 = 1
  //        a_1 = 1 / 2
  //        a_2 = 1 / 3
  //        ...
  //        a_size-1 = 1 / size

  const SeriesPtr hSeriesPtr = InitializeHarmonicSeries (size);

  // proszę zadbać o odpowiednie formatowanie wyjścia:
  PrintSeries(gSeriesPtr, size);
  PrintSeries(hSeriesPtr, size); 
  
  SeriesType gSeriesSum = SeriesSum(gSeriesPtr, size);
  SeriesType hSeriesSum = SeriesSum(hSeriesPtr, size);
  
  printf("Sum of geometric series: %.2f\n",gSeriesSum);
  printf("Sum of harmonic series: %.2f\n",hSeriesSum);

  SeriesFunctionPtr seriesFunContainer [] = { SeriesProduct
                                              ,SeriesSum    
                                              ,SeriesMax    
                                              ,SeriesMin }; 
  
  const int nOperations = sizeof(seriesFunContainer)/sizeof(SeriesFunctionPtr);
  
  printf("** Geometric series operations **\n");
  for (int i = 0; i < nOperations; ++i)
    RunAndPrint (seriesFunContainer[i], gSeriesPtr, size);

  printf("** Harmonic series operations **\n");
  for (const auto& functionPtr : seriesFunContainer)
    RunAndPrint (functionPtr, hSeriesPtr, size);

  DeleteSeries();

  for (int i = 0; i < 66; ++i){
   InitializeGeometricSeries(10, 2.4);
   InitializeHarmonicSeries(10);
 }

  DeleteSeries();

}
/* wynik dzialania programu:
brachwal@vbox:[build]$ ./run 
 1.00 2.00 4.00 8.00
 1.00 0.50 0.33 0.25
Sum of geometric series: 15.00
Sum of harmonic series: 2.08
** Geometric series operations **
Product: 64
Sum: 15
Maximum: 8
Minimum: 1
** Harmonic series operations **
Product: 0.0416667
Sum: 2.08333
Maximum: 1
Minimum: 0.25
Deleting 2 series...
 *** Memory cleanded up ***
Deleting 132 series...
 *** Memory cleanded up ***
*/
