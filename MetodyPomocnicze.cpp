#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

string MetodyPomocnicze::wczytajLinie() {
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;
    cin.sync();
    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

char MetodyPomocnicze::wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string MetodyPomocnicze::sprawdzPoprawnoscTelefonu() {
    string numerTelefonu;
    int i, dlugoscNumeru;

    cin.sync();
    getline(cin,numerTelefonu);
    dlugoscNumeru = numerTelefonu.length();
    i=0;

    while (i<dlugoscNumeru) {
        if ((numerTelefonu [i] >= '0')&&(numerTelefonu[i] <='9') || (numerTelefonu[i] == 32)) {
            i++;
        } else {
            cout << "Numer telefonu jest bledny. Wprowadz ponownie numer telefonu: ";
            cin.sync();
            getline(cin,numerTelefonu);
            dlugoscNumeru = numerTelefonu.length();
            i=0;
        }
    }
    return numerTelefonu;
}

string MetodyPomocnicze::sprawdzPoprawnoscEmail() {
    string email;
    int dlugoscEmaila;
    int iloscMalp;  //sprawdzam czy jest znak @
    int iloscKropek;//sprawdzam czy jest kropka po znaku @
    int pozycjaMalpy, i, j;

    for (;;) {
        cin >> email;
        dlugoscEmaila = email.length();
        iloscMalp = 0;
        pozycjaMalpy = 0;
        iloscKropek = 0;
        i = 0;

        while (i < dlugoscEmaila) {
            if (email[i] == '@') {
                iloscMalp++;
                pozycjaMalpy = i;
            }
            i++;
        }

        j = pozycjaMalpy;

        while (j < dlugoscEmaila) {
            if (email[j] == '.') {
                iloscKropek++;
            }
            j++;
        }
        if ((iloscMalp == 1) && (iloscKropek > 0) && (dlugoscEmaila >4 )) {
            return email;
        } else {
            cout << "Niepoprawny adres email. Wprowadz ponownie: ";
        }
    }
}
