// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy: Grade, ktora reprezentuje ocene studenta, oraz
// GradeBook, ktora reprezentuje dziennik ocen. Kazda ocena ma
// przypisany unikatowy numer ID, inicjalizowany w momencie tworzenia
// danej oceny.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// UWAGA!!!
// Tablice powinny dostosowywac swoj rozmiar do liczby przechowywanych
// elementow. Nie wolno używać std::vector

// UWAGA!!!
// Nie wolno uzywac jawnego rzutowania. Uzycie jawnego rzutownia
// bedzie traktowane jak blad kompilacji, czyli 0 punktow.

// UWAGA!!!
// W tym zadaniu nie wolno uzywac mutable. Uzycie tego slowa
// kluczowego oznacza 0 punktow za zadanie.

// UWAGA!!!
// Uzycie const_cast z obiektem const powoduje niezdefiniowane
// dzialanie programu, dlatego w takiej sytuacji nie wolno uzyc
// const_cast.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow. Można użyć wcześniejszego CMakeLists.txt

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, CMakeLists.txt i Main.cpp)
// nalezy wgrac do UPEL w formie archiwum, spakowany folder projektu do Lab09.tar.gz

#include <iostream>
#include "Grade.h"
#include "GradeBook.h"

int main() {

  Grade* firstGrade = new Grade (4.5);

  firstGrade->Print();

  std::cout<<"\n";
  GradeBook goodStudents;

  goodStudents.Insert(firstGrade);

  goodStudents.Print();
  goodStudents.Insert(new Grade(4),"Complex numbers calculation");
  
  goodStudents.AddGrade(3.5);

  const Grade* secondGrade = new const Grade (5);
  goodStudents.Insert(secondGrade,"Final exam");
  goodStudents.Print();
  goodStudents.Summary();

  return 0;
}
/**
brachwal@vbox:[cmake-build-debug]$ ./grades
Grade ID=1 value=4.5
[GradeBook]: Set of grades in the book:
Grade ID=1 value=4.5

[GradeBook]: Set of grades in the book:
Grade ID=1 value=4.5
Grade ID=2 value=4 "Complex numbers calculation"
Grade ID=3 value=3.5
Grade ID=4 value=5 "Final exam"

[GradeBook]: Summary: Number of grades in the book: 4
[GradeBook]: Summary: Average of grades: 4.25
*/
