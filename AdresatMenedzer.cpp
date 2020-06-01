#include "AdresatMenedzer.h"
#include "KsiazkaAdresowa.h"

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Dodano nowego adresata" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    } else {
        cout << "Nie udalo sie dodac adresata do pliku." << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawIdAdresata((plikZAdresatami.pobierzIdOstatniegoAdresata()+1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);
    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);
    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::sprawdzPoprawnoscTelefonu();
    adresat.ustawNumerTelefonu(numerTelefonu);
    cout << "Podaj email: ";
    email = MetodyPomocnicze::sprawdzPoprawnoscEmail();
    adresat.ustawEmail(email);
    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzIdAdresata() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

int AdresatMenedzer::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::usunAdresata() {
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzIdAdresata() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Usuwasz " << itr -> pobierzImie() <<" "<< itr -> pobierzNazwisko() << endl;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                itr--;
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
                getch();
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
                getch();
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    string imie, nazwisko, numerTelefonu, email, adres;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzIdAdresata() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;

            cout << "Edytujesz:" << endl << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
            cout << adresaci[i].pobierzNumerTelefonu() << endl << adresaci[i].pobierzEmail() << endl << adresaci[i].pobierzAdres() << endl;
            wybor = KsiazkaAdresowa::wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                imie = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nazwisko = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::sprawdzPoprawnoscTelefonu());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::sprawdzPoprawnoscEmail());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (!czyIstniejeAdresat) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}
