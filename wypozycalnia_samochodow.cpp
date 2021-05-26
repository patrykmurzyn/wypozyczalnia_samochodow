#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void menu_kierownik();
void menu_serwisant();

void menu() {
    
repeat:
    system("CLS");
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|     ____                            |)" << endl;
    cout << R"(|  __/  |_\_          Wypozyczalnia   |)" << endl;
    cout << R"(| |  _     _``-.      Samochodow v0.0 |)" << endl;
    cout << R"(| '-(_)---(_)--'                      |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    cout << "Menu:" << endl;
    cout << "1) Rezerwacja samochodu" << endl;
    cout << "2) Anulowanie rezerwacji" << endl;
    cout << "3) Wydanie samochodu" << endl;
    cout << "4) Zwrot samochodu" << endl;
    cout << "5) Przeglad samochodow" << endl;
    cout << "6) Operacje kierownika" << endl;
    cout << "7) Operacje serwisanta" << endl;

    int wybor;
    cout << "Twoj wybor: ";
    cin >> wybor;

    switch (wybor) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        system("CLS");
        menu_kierownik();
        break;
    case 7:
        system("CLS");
        menu_serwisant();
        break;
    default:
        goto repeat;
        break;
    }
}

void menu_kierownik() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|  .--.                               |)" << endl;
    cout << R"(| /.-. '----------.    Operacje       |)" << endl;
    cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
    cout << R"(|  '--'                               |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    string kod;
    cout << endl << "Podaj kod dostepu: ";
    cin >> kod;

    if (kod == "qwe123") {
    repeat:
        system("CLS");
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|  .--.                               |)" << endl;
        cout << R"(| /.-. '----------.    Operacje       |)" << endl;
        cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
        cout << R"(|  '--'                               |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << "Menu:" << endl;
        cout << "1) Dodanie samochodu do bazy" << endl;
        cout << "2) Usuniecie samochodu z bazy" << endl;
        cout << "3) Powrot do glownego menu" << endl;

        int wybor;
        cout << "Twoj wybor: ";
        cin >> wybor;
        
        switch (wybor) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            menu();
            break;
        default:
            goto repeat;
            break;
        }

    }
    else {
        char wybor;
        cout << "Kod nieprawidlowy. Chcesz sprobowac ponownie? [T/ N]: ";
        cin >> wybor;

        if (wybor == 'T' || wybor == 't') {
            system("CLS");
            menu_kierownik();
        }
        else {
            system("CLS");
            menu();
        }
    }
}

void menu_serwisant() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|   ,-----.                           |)" << endl;
    cout << R"(|  / ,---. \                          |)" << endl;
    cout << R"(| / /     \ \          Operacje       |)" << endl;
    cout << R"(| \ \     / /          Serwisowe      |)" << endl;
    cout << R"(|  \ `---' /                          |)" << endl;
    cout << R"(|   `-----'                           |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    string kod;
    cout << endl << "Podaj kod dostepu: ";
    cin >> kod;

    if (kod == "qwe123") {
    repeat:
        system("CLS");
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|   ,-----.                           |)" << endl;
        cout << R"(|  / ,---. \                          |)" << endl;
        cout << R"(| / /     \ \          Operacje       |)" << endl;
        cout << R"(| \ \     / /          Serwisowe      |)" << endl;
        cout << R"(|  \ `---' /                          |)" << endl;
        cout << R"(|   `-----'                           |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << "Menu:" << endl;
        cout << "1) Potwierdzenie gotowosci samochodu" << endl;
        cout << "2) Raport serwisu samochodu" << endl;
        cout << "3) Raport kontroli samochodu" << endl;
        cout << "4) Powrot do glownego menu" << endl;

        int wybor;
        cout << "Twoj wybor: ";
        cin >> wybor;

        switch (wybor) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
            break;
        default:
            goto repeat;
            break;
        }

    }
    else {
        char wybor;
        cout << "Kod nieprawidlowy. Chcesz sprobowac ponownie? [T/ N]: ";
        cin >> wybor;

        if (wybor == 'T' || wybor == 't') {
            system("CLS");
            menu_kierownik();
        }
        else {
            system("CLS");
            menu();
        }
    }
}

class Model {
    string marka;
    string wersja;
    int moc_silnika;
    string skrzynia_biegow;
    string paliwo;
    float sr_spalanie;
    int ilosc_drzwi;
    int ilosc_miejsc;
    float poj_bagaznika;
    bool klimatyzacja;
    float koszt_godzina;

public:
    Model() {
        marka = "-";
        wersja = "-";
        moc_silnika = 0;
        skrzynia_biegow = "-";
        paliwo = "-";
        sr_spalanie = 0;
        ilosc_drzwi = 0;
        ilosc_miejsc = 0;
        poj_bagaznika = 0;
        klimatyzacja = 0;
        koszt_godzina = 0;
    }
    Model(string marka, string wersja, int moc_silnika, string skrzynia_biegow,
        string paliwo, float sr_spalanie, int ilosc_drzwi, int ilosc_miejsc,
        float poj_bagaznika, bool klimatyzacja, float koszt_godzina) {

        this->marka = marka;
        this->wersja = wersja;
        this->moc_silnika = moc_silnika;
        this->skrzynia_biegow = skrzynia_biegow;
        this->paliwo = paliwo;
        this->sr_spalanie = sr_spalanie;
        this->ilosc_drzwi = ilosc_drzwi;
        this->ilosc_miejsc = ilosc_miejsc;
        this->poj_bagaznika = poj_bagaznika;
        this->klimatyzacja = klimatyzacja;
        this->koszt_godzina = koszt_godzina;

        Save("SaveModel");
    }
    void Save(const string save_T) {
        ofstream file;
        file.open(save_T, ios::app);

        if (file.is_open()) {
            file << marka << endl << wersja << endl << moc_silnika << endl <<
                skrzynia_biegow << endl << paliwo << endl << sr_spalanie << endl <<
                ilosc_drzwi << endl << ilosc_miejsc << endl << poj_bagaznika << endl <<
                klimatyzacja << endl << koszt_godzina << endl;

            file.close();
        }
    }
    void ReadAll(const string save_T) {
        fstream file;
        file.open(save_T, ios::in);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
        file.close();
        }
    }
    void ReadVersion(const string save_T) {
        fstream file;
        file.open(save_T, ios::in);

        if (file.is_open()) {
            string line;
            int turn = 0;
            int index = 1;
            while (getline(file, line)) {
                if (turn == index) {
                    cout << line << endl;
                    index += 11;
                }
                turn++;
            }
            file.close();
        }
    }

    void RemoveModel(const string save_T, int index) {
        fstream file_i;
        file_i.open(save_T, ios::in);

        string line;
        vector<string> vec;

        while (getline(file_i, line)) {
            vec.push_back(line);
        }
        file_i.close();

        fstream file_o;
        file_o.open(save_T, ios::out);

        int start = 1 + (index - 1) * 10;

        for (int i = 0; i < vec.size(); i++) {
            if (i < start || i > start + 10) {
                file_o << vec[i] << endl;
            }
        }

        file_o.close();
        
    }
};

void clearFile(const string save_T) {
    ofstream file;
    file.open(save_T, ios::out);

    file.close();
    
}

class Samochod {
    Model model;
    string nr_rejestracyjny;
    string kolor;
    int przebieg;
    int rocznik;
public: 
    static int licznik;

public:
    Samochod(Model model, string nr_rejestracyjny, string kolor, int przebieg, int rocznik) {
        this->model = model;
        this->nr_rejestracyjny = nr_rejestracyjny;
        this->kolor = kolor;
        this->przebieg = przebieg;
        this->rocznik = rocznik;
        licznik++;
    }
    ~Samochod() {
        licznik--;
    }

    void dodaj() {
        cout << "dodaj" << endl;
    }
};

int Samochod::licznik = 0;

struct date {
    int rok;
    int miesiac;
    int dzien;
    int godzina;
};

class Wypozyczenie {
    date wyp_od;
    date wyp_do;
    int przebieg_wyp;
    int przebieg_zwr;
    bool czy_zwrocony;
    int nr_zamowienia;
};

class Osoba {
    string imie;
    string nazwisko;
    int pesel;
    string nr_tel;
};

class Pracownik {
    string stanowisko;
};

class Klient {

};

int main()
{
    clearFile("SaveModel");
    //menu();
    Model BMW_serii_1("BMW", "118i M Sport", 140, "automatyczna", "benzyna", 5.9, 5, 5, 380, true, 230);
    Model Yaris("Toyota", "Yaris", 125, "manualna", "benzyna", 8.5, 5, 5, 255, true, 120);
    Model Vivaro("Opel", "Vivaro", 144, "automatyczna", "Diesel", 13.2, 5, 9, 1400, true, 490);
    BMW_serii_1.RemoveModel("SaveModel", 3);
    BMW_serii_1.ReadVersion("SaveModel");
    Samochod samochod1(BMW_serii_1, "KNS 83674", "czarny", 52350, 2019);
    //bmw.dodaj();
}