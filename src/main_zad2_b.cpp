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

  int poz1, poz2;
  char myslnik, char_cel, dwukropek;
  string haslo;
  int poprawne_hasla = 0;

  while (file >> poz1 >> myslnik >> poz2 >> char_cel >> dwukropek >> haslo) {
    // brak indeksu zerowego - trzeba odjac 1;
    int index1 = poz1 - 1;
    int index2 = poz2 - 1;
    if (index1 >= haslo.size() || index2 >= haslo.size()) {
      continue; // indeks poza zakresem hasla
    }
    bool match1 = (haslo[index1] == char_cel);
    bool match2 = (haslo[index2] == char_cel);

    //mozna uzyc od razu xor
    if (match1 != match2) {
      poprawne_hasla++;
    }
  }
  println("Liczba poprawnych hasel to: {}", poprawne_hasla);

  return 0;
}