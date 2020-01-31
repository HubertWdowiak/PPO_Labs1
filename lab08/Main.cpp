// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.
//
// Zadanie opiera się klase MapPoint, ktora reprezentuje punkt na
// mapie zawierajacy informacje o współrzędnych: dlugosci (longitude) i szerokosci
// (latitude) geograficznej, bez oznaczania polkol. Współrzędne te stanowią osobną
// klasę: Coordinates.
//
// UWAGA: Punktem startowym może być (ale nie musi, powinno wystarczyć czasu)
//        kod źródłowy z tygodnia poprzedniego
//
// UWAGA: Proszę zwrócić uwagę na CMakeLists.txt, cmake należy uruchamiać 
//        z odpowiednią flagą: -DBUILD_MAPLIB=ON
//
// UWAGA: Proszę zwrócić szczególną uwagę na const correctness

// Implementację i działanie metod poszczególnych klas proszę wywnioskować
// z treści main().
//
// Pliku Main.cpp, nie wolno modyfikowac.

// Strukturę plików w projekcie prosze wywnioskować z załączonego pliku CMakeLists.txt
// UWAGA: jest to krytyczny punkt brany pod uwagę w ocenie! W głównym katalogu projektu
//        mogą znajdować się pliki CMakelists.txt oraz Main.cpp oraz katologi src, include

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz Makefile lub CMakeLists.txt)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

//#ifdef MAPLIB
    #include "MapPoint.h"
//#endif

int main() {

  //========== KRK ========================
  MapPoint krk("KRK",19.938333,50.061389);
  krk.Print();

  //========== NYC ========================
  const double latitude = 40.7127;
  const double longitude = -74.0059;
  MapPoint nyc("NYC");
  Coordinates* nycCoordinates = nyc.GetCoordinatesPtr();
  nycCoordinates->Latitude(latitude);
  nycCoordinates->Longitude(longitude);
  nyc.Print();

  //========== PORTO ======================
  MapPoint porto;
  porto.SetId("PRT");
  porto.GetCoordinatesPtr()->Set(41.162142, -8.621953);
  porto.Print();

  //========== GENERAL MAP INTERFACE ======================
  std::cout << "Number of MapPoints defined: " 
            << MapPoint::NumberOfPoints() 
            << std::endl;

  // Pole zadane przez współrzedne trzech punktów:
  // pole = 1/2 * ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))
  std::cout << "Triangle area: " 
            << surfaceTriangleArea(&krk,&nyc,&porto) 
            << std::endl;

  return 0;
}

/** Wynik dzialania programu:
brachwal@vbox:[build]$ ./map 
Point: KRK (19.9383, 50.0614)
Point: NYC (40.7127, -74.0059)
Point: PRT (41.1621, -8.62195)
Number of MapPoints defined: 3
Triangle area: 707.036
*/
