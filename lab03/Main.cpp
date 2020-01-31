// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// *** ZADANIE ***
// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi geometryczne o pierwszym wyrazie 1 i zadanym
// ilorazie. Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy i najmniejszy element.
// Uwaga: odpowiednie komentarze są również w kodzie źródłowym funkcji main()

// Prosze zadbac o dobre zarzadzanie pamiecia.

// Plik Main.cpp, w ostatecznej wersji programu nie powinien być zmodyfikowany!

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// *** MAKEFILE ***
// Nie wymagany, można skorzystać z własnego lub udostępnionego na UPEL

// *** OGRANICZENIA ***
// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików, oprócz Makefile)

// Kody źródłowe muszą znajdować się w katalogu ~/preoop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla właściciela).

// Skonczone zadanie nalezy wyslac na UPEL w formie spakowanego katalogu (lab_03)
// do archiwum lab_03.tar.gz
// tar -czvf lab_03.tar.gz lab_03/

#include "GeometricSeries.h"

int main ()
{
  const Size size = 6;      // rozmiar ciagu geometrycznego
  
  // uwaga: pierwszy element ciagu to 1:
  //        a_0 = 1
  //        a_1 = a_0 * ratio
  //        a_2 = a_1 * ratio
  //        ...
  //        a_size-1 = a_size-2 * ratio

  const float ratio1 = 2;   // iloraz ciągu
  const SeriesPtr gSeriesPtr1 = InitializeGeometricSeries (size, ratio1);
  
  
  const float ratio2 = 3.;  // iloraz ciągu
  const SeriesPtr gSeriesPtr2 = InitializeGeometricSeries (size, ratio2);

  // proszę zadbać o odpowiednie formatowanie wyjścia:
  PrintSeries(gSeriesPtr1, size);
  PrintSeries(gSeriesPtr2, size); 
  
  SeriesType gSeriesSum = SeriesSum(gSeriesPtr1, size);
  
  printf("Sum of geometric series: %.2f\n",gSeriesSum);
  
  // przypomnienie: SeriesFunctionPtr jest wskaźnikiem na funkcję:
  // - z odpowiednim typem zwracanym
  // - o odpowiednich parametrach formalnych
  // - wskaźnik tego typu definiujemy poprzez typedef ...

  SeriesFunctionPtr gSeriesFunContainer [] = { SeriesProduct  // funkcja zwraca iloczyn wszystkich elementów ciągu
                                              ,SeriesSum      // funkcja zwraca suma wszystkich elementów ciągu
                                              ,SeriesMax      // funkcja zwraca element o wartości maksymalanej 
                                              ,SeriesMin };   // funkcja zwraca element o wartości maksymalanej 
  
  const int nOperations = sizeof(gSeriesFunContainer)/sizeof(SeriesFunctionPtr);
  
  printf("Series operations:\n");
  for (int i = 0; i < nOperations; ++i)
    RunAndPrint (gSeriesFunContainer[i], gSeriesPtr1, size);

  DeleteSeries(&gSeriesPtr1);
  DeleteSeries(&gSeriesPtr2);
}
/* wynik dzialania programu:
brachwal@vbox:[Lab03]$ ./run 
   1   2   4   8  16  32
   1   3   9  27  81 243
Sum of geometric series: 63.00
Series operations:
Product: 32768
Sum: 63
Maximum: 32
Minimum: 1
*/
