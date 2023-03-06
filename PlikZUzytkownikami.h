#ifndef PLIKIZUZYTKOWNIKAMI_H
#define PLIKIZUZYTKOWNIKAMI_H

#include <vector>

#include "PlikTekstowy.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZUzytkownikami :public PlikTekstowy {
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:

    PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif // PLIKIZUZYTKOWNIKAMI_H
