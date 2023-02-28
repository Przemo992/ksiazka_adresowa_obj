#include <iostream>

#include "KsiazkaAdresowa.h"
#include "MenuGlowne.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    MenuGlowne menuGlowne;

    char wybor;

    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = menuGlowne.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
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

            wybor = menuGlowne.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika());
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
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
                ksiazkaAdresowa.wylogowanie();
                break;
            }
        }
    }
    return 0;
}



