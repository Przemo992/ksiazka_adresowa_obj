#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"
#include "MenuGlowne.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy {
    int idOstatniegoAdresata;

    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami, int idAdresata);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:

    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};

    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void usunAdresataZPliku(vector <Adresat> &adresaci, int idUsuwanegoAdresata);

};

#endif // PLIKIZADRESATAMI_H
