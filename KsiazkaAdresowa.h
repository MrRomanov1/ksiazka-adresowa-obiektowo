#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <conio.h>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        :uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {

        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa() {

        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };
    void zmianaHaslaZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    static char wybierzOpcjeZMenuEdycja();
    void edytujAdresata();

};

#endif
