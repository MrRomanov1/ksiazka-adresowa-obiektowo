#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami): NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci-tymczasowy.txt";
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami);
};

#endif
