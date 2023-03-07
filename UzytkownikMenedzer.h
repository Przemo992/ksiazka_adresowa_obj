#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;

    vector <Uzytkownik> uzytkownicy;

    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;
    Uzytkownik podajDaneNowegoUzytkownika();
public:

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika = 0;
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    bool czyUzytkownikJestZalogowany();
    int pobierzIdNowegoUzytkownika();
};

#endif // UZYTKOWNIKMENEDZER_H
