#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>


#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;

    vector <Uzytkownik> uzytkownicy;


    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
         uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
           idZalogowanegoUzytkownika = 0;
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    bool czyUzytkownikJestZalogowany();
   int pobierzIdNowegoUzytkownika();
};

#endif // UZYTKOWNIKMENEDZER_H
