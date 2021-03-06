#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout <<"Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()));

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {

    for (int i=0; i<uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin()==login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::logowanieUzytkownika() {

    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo) {
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
                    getch();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
            getch();
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
    return;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {

    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
            getch();
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
