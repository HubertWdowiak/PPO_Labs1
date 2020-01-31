// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// *** ZADANIE ***
// Prosze napisac funkcje tworzace i operaujace na ciagach. Nalezy
// utworzyc ciagi harmoniczne o pierwszym wyrazie 1 i zadanym
// rozmiarze. Oprocz tego nalezy obliczyc sume oraz iloczyn wszystkich
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

// Skonczone zadanie nalezy wyslac na UPEL w formie spakowanego katalogu (lab_04)
// do archiwum lab_04.tar.gz
// tar -czvf lab_04.tar.gz lab_04/

#include "HarmonicSeries.h"

int main ()
{
  const Size size = 5;      // rozmiar ciagu harmonicznego
  
  // uwaga: pierwszy element ciagu to 1:
  //        a_0 = 1
  //        a_1 = 1 / 2
  //        a_2 = 1 / 3
  //        ...
  //        a_size-1 = 1 / size

  const SeriesPtr hSeriesPtr1 = InitializeHarmonicSeries (size);
  const SeriesPtr hSeriesPtr2 = InitializeHarmonicSeries (size);

  // proszę zadbać o odpowiednie formatowanie wyjścia:
  PrintSeries(hSeriesPtr1, size);
  PrintSeries(hSeriesPtr2, size); 
  
  SeriesType hSeriesSum = SeriesSum(hSeriesPtr1, size);
  
  printf("Sum of harmonic series: %.2f\n",hSeriesSum);
  
  // przypomnienie: SeriesFunctionPtr jest wskaźnikiem na funkcję:
  // - z odpowiednim typem zwracanym
  // - o odpowiednich parametrach formalnych
  // - wskaźnik tego typu definiujemy poprzez typedef ...

  SeriesFunctionPtr hSeriesFunContainer [] = { SeriesProduct  // funkcja zwraca iloczyn wszystkich elementów ciągu
                                              ,SeriesSum      // funkcja zwraca suma wszystkich elementów ciągu
                                              ,SeriesMax      // funkcja zwraca element o wartości maksymalanej 
                                              ,SeriesMin };   // funkcja zwraca element o wartości maksymalanej 
  
  const int nOperations = sizeof(hSeriesFunContainer)/sizeof(SeriesFunctionPtr);
  
  printf("Series operations:\n");
  for (int i = 0; i < nOperations; ++i)
    RunAndPrint (hSeriesFunContainer[i], hSeriesPtr2, size); // proszę zadbać o odpowiednie formatowanie wyjścia
  
  DeleteSeries();

  for (int i = 0; i < 99; ++i)
   InitializeHarmonicSeries(size);

  DeleteSeries();
  
}
/* wynik dzialania programu:
brachwal@vbox:[Lab04]$ ./run 
  1.00  0.50  0.33  0.25  0.20
  1.00  0.50  0.33  0.25  0.20
Sum of harmonic series: 2.28
Series operations:
Product: 0.01
Sum: 2.28
Maximum: 1.00
Minimum: 0.20
Deleting 2 series...
 *** Memory cleanded up ***
Deleting 99 series...
 *** Memory cleanded up ***
*/
