#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}
string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
string MetodyPomocnicze::zakrywanieHasla() {

    constexpr char c_enter  = 13;
    constexpr char c_backspace = 8;

    string passwd;
    char input_character;

    input_character = getch();

    while(input_character != c_enter) {

        if(input_character == c_backspace && passwd.size()) {
            cout << "\b \b";
            passwd.pop_back();
        } else if(input_character != c_backspace) {
            cout.put('*');
            passwd += input_character;
        }

        input_character = getch();
    }
    return passwd;
}
