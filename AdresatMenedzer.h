#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class AdresatMenedzer {

    vector <Adresat> adresaci;
    string nazwaPlikuZAdresatami;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void wypiszWszystkichAdresatow();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();

public:

    AdresatMenedzer();
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool czyWektorJestPusty();
    void wyswietlWszystkichAdresatow();

};
#endif
