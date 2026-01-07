#include <cmath>
#include <fstream>
#include <print>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  if (!file) {
    println(stderr, "Blad przy otwieraniu pliku");
    return 1;
  }
  // pozycja startowa statku
  long long x_statku = 0, y_statku = 0;
  // na start statek patrz na eaast
  long long waypoint_x = 10, waypoint_y = 1;
  char akcja;
  int wartosc;

  while (file >> akcja >> wartosc) {
    switch (akcja) {
    // najpierw sam ruch, bez obrotow
    case 'N':
      waypoint_y += wartosc;
      break;
    case 'S':
      waypoint_y += -wartosc;
      break;
    case 'E':
      waypoint_x += wartosc;
      break;
    case 'W':
      waypoint_x += -wartosc;
      break;

    case 'F': {
      x_statku += waypoint_x * wartosc;
      y_statku += waypoint_y * wartosc;
      break;
    }
    // teraz same obroty, bez zmiany wspolrzednych !!!!
    // Trzeba zrobic reszte z dzielenia przez 4, zeby wartosci nie wychodzily
    // glupie!!!
    case 'L': {
      int obroty_w_lewo = wartosc / 90;
      for (int i = 0; i < obroty_w_lewo; ++i) {
        long long stary_x = waypoint_x;
        waypoint_x = -waypoint_y;
        waypoint_y = stary_x;
      }
      break;
    }
    case 'R': {
      int obroty_w_prawo = wartosc / 90;
      for (int i = 0; i < obroty_w_prawo; ++i) {
        long long stary_x = waypoint_x;
        waypoint_x = waypoint_y;
        waypoint_y = -stary_x;
      }
      break;
    }
    }
  }
  int wynik = abs(x_statku) + abs(y_statku);
  println("Odleglosc Manhattanska wynosi: {} ", wynik);

  return 0;
}