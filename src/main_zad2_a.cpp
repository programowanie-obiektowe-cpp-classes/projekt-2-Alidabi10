#include <algorithm>
#include <fstream>
#include <print>
#include <string>
#include <vector>

using namespace std;

int main() {

  ifstream file("input.txt");
  if (!file) {
    println(stderr, "Blad przy otwieraniu pliku.");
    return 1;
  }

  int min, max;
  char myslnik, char_cel, dwukropek;
  string haslo;
  int poprawne_hasla = 0;


  //mozna uzyc count_if 
  //~getline(?)

  while (file >> min >> myslnik >> max >> char_cel >> dwukropek >> haslo) {
    long licz = ranges::count(haslo, char_cel);
    if (licz >= min && licz <= max) {
      poprawne_hasla++;
    }
  }
  println("Liczba poprawnych hasel to: {}", poprawne_hasla);

  return 0;
}
