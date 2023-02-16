#include <iostream>
#include <sstream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
   int idOstatniegoAdresata;

   vector <Adresat> adresaci;

   PlikZAdresatami plikZAdresatami;

   public:
       int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
       Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
       void wyswietlWszystkichAdresatow();
       void wyswietlDaneAdresata(Adresat adresat);
       void wylogowanie();
       void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

};
