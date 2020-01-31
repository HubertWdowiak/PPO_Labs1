// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase MyString. Klasa ta posluzyc ma do ulatwienia
// operacji na napisach. W tym celu do klasy dodano np operator *, czy też
// metodę do uzyskiwania części MyString, czyli substr(...).
// Mozna również obiekty tej klasy wypisywac funkcją Print().
// Dostepne sa takze naturalne operatory = i == oraz [].
// Trudnoscia w zadaniu jest sprawne zarzadzanie pamiecia.

// Założenia projektowe:
// Przy wykonaniu tego zadania nie wolno korzystac z std::string!

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow. Można użyć wcześniejszego CMakeLists.txt

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, CMakeLists.txt i Main.cpp)
// nalezy wgrac do UPEL w formie archiwum, spakowany folder projektu do Lab12.tar.gz


#include <iostream>
#include "MyString.h"

int main() {
  const MyString s0("Witaj Swiecie ");
  const MyString s1("Witaj swiecie ");
  MyString s2("Witaj Swiecie ");

  if (s0 == s1 )
    std::cout << " s0 i s1 sa identyczne" << std::endl;
  else
    std::cout << " s0 i s1 nie sa identyczne" << std::endl;

  if (s0 == s2 )
    std::cout << " s0 i s2 sa identyczne" << std::endl;

  if (s2 == s0 )  // To jest intencjonalne -> Const Correctness!
    std::cout << " s2 i s0 sa identyczne" << std::endl;

  MyString s3 = s2 * 2;
  s3.Print();
  s3 = s1;
  s3.Print();
  s3[6] = 'S';
  s3.Print();
  s3 = s1.substr(6,12);
  s3.Print();
  
}
/* wynik
brachwal@vbox:[build]$ ./StringStory 
 s0 i s1 nie sa identyczne
 s0 i s2 sa identyczne
 s2 i s0 sa identyczne
Witaj Swiecie Witaj Swiecie
Witaj swiecie
Witaj Swiecie
swiecie
*/
