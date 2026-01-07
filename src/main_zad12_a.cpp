#include <cmath>
#include <fstream>
#include <print>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("input.txt");
  if (!file) {
    println(stderr, "Blad przy otwieraniu pliku");
    return 1;
  }

  //pozycjani kierunek w strukturze
  // pozycja startowa statku
  int x = 0, y = 0;
  // na start statek patrz na eaast
  int aktualny_kierunek = 0;

  // kierunki po kolei (wschod, poludnei, zachod, polnoc)
  const int dx[] = {1, 0, -1, 0};
  const int dy[] = {0, -1, 0, 1};

  char akcja;
  int wartosc;

  while (file >> akcja >> wartosc) {
    switch (akcja) {
    // najpierw sam ruch, bez obrotow
    case 'N':
      y += wartosc;
      break;
    case 'S':
      y += -wartosc;
      break;
    case 'E':
      x += wartosc;
      break;
    case 'W':
      x += -wartosc;
      break;

    // teraz same obroty, bez zmiany wspolrzednych !!!!Trzeba zrobic reszte z
    // dzielenia przez 4, zeby wartosci nie wychodzily glupie!!!
    case 'L': {
      int obroty_w_lewo = wartosc / 90;
      aktualny_kierunek = (aktualny_kierunek - obroty_w_lewo + 4) % 4;
      break;
    }
    case 'R': {
      int obroty_w_prawo = wartosc / 90;
      aktualny_kierunek = (aktualny_kierunek + obroty_w_prawo) % 4;
      break;
    }
    case 'F': {
      x += dx[aktualny_kierunek] * wartosc;
      y += dy[aktualny_kierunek] * wartosc;
      break;
    }
    }
  }
  int wynik = abs(x) + abs(y);
  println("Odleglosc Manhattanska wynosi: {} ", wynik);

  return 0;
}