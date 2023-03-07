#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <sstream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"
#include "MenuGlowne.h"


class AdresatMenedzer {

    PlikZAdresatami plikZAdresatami;

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector <Adresat> adresaci;

    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void wyswietlDaneAdresata(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int podajIdWybranegoAdresata();
    Adresat podajDaneNowegoAdresata();

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wylogowanie();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    void usunAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif // ADRESATMENEDZER_H
