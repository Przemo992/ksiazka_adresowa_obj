#include <iostream>

#include "KsiazkaAdresowa.h"
#include "MenuGlowne.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

char wybor;
int idZalogowanegoUzytkownika;
int idOstatniegoAdresata = 0;

MenuGlowne menuGlowne;

    //wczytajUzytkownikowZPliku(uzytkownicy);

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = menuGlowne.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            //if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
            PlikZAdresatami plikZAdresatami;
            idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata(idZalogowanegoUzytkownika);

            wybor = menuGlowne.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata = ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            /*case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break;  */
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
           /* case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break; */
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
                ksiazkaAdresowa.wylogowanie();
                break;
            }
        }
    }
    return 0;
}



