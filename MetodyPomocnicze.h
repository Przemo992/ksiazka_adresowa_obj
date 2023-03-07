#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <conio.h>

using namespace std;

class MetodyPomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
    static string zakrywanieHasla();
};

#endif // METODYPOMOCNICZE_H
