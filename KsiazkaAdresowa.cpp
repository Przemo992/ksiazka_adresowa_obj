#include "KsiazkaAdresowa.h"



void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

    void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
    {
        adresatMenedzer.wyswietlWszystkichAdresatow();
    }

        void KsiazkaAdresowa::wylogowanie()
    {
        adresatMenedzer.wylogowanie();
    }

    void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
    {
       adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    }
