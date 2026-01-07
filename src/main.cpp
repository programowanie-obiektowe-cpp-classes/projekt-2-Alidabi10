#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  /*
      //czesc a
  //otwieram plik
  ifstream file("entries.txt");

  if (!file) {
  println("Blad, nie mozna otworzyc pliku");
  }
  //tworze haszmape, zeby iterowac sie tylko raz po pliku - mniejsza zlozonosc
  obliczeniowa (N) unordered_set<int> entries;

  int a;
  while (file >> a) {
  int cel = 2020 - a;
  if (entries.contains(cel)) {
  println("Znaleziono {} i {} w entries. Wynik mnozenia: {}", a, cel, a * cel);
  return 0;
  }
  entries.insert(a);
  }
  println("Brak liczb sumujacych sie do 2020");




  return 0;}
  */

  // czesc b
  ifstream file("entries.txt");

  if (!file) {
    println("Blad, nie mozna otworzyc pliku");
  }

  // tworze wektor, bo kilka razy musze sie przebiec po pliku
  vector<int> entries;
  int b;
  while (file >> b) {
    entries.push_back(b);
  }

  for (size_t i = 0; i < entries.size(); ++i) {
    int pierwsza_liczba = entries[i];
    int pozostala_suma = 2020 - pierwsza_liczba;
    unordered_set<int> pozostale_liczby;
    for (size_t j = i + 1; j < entries.size(); ++j) {
      int druga_liczba = entries[j];
      int trzecia_liczba = pozostala_suma - druga_liczba;
      if (pozostale_liczby.contains(trzecia_liczba)) {
        println("Znaleziono {}, {} oraz {}.", pierwsza_liczba, druga_liczba,
                trzecia_liczba);
        long iloczyn =
            static_cast<long>(pierwsza_liczba * druga_liczba * trzecia_liczba);
        println("Wynik mnozenia tych liczb to : {}", iloczyn);
        return 0;
      }
      pozostale_liczby.insert(druga_liczba);
    }
  }
  println("Brak trzech liczb, ktore sumowalyby sie do 2020");
  return 0;
}
*/