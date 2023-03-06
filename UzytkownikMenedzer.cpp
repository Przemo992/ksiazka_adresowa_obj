#include "UzytkownikMenedzer.h"


int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (unsigned int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
