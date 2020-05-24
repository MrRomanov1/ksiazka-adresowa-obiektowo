#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer {

    vector <Adresat> adresaci;
    string nazwaPlikuZAdresatami;

public:
    AdresatMenedzer();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void wypiszWszystkichAdresatow();
    bool czyWektorJestPusty();
};
#endif
