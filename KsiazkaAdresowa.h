#include <iostream>
#include <vector>

#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa {

    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    bool czyIstniejeLogin(string login);
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();


public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


};
