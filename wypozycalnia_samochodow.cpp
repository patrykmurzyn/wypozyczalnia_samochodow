#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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
    static int licznik;
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
        licznik++;
    }
    ~Model() {
        licznik--;
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
    static int ReadVersion(const string save_T) {
        fstream file;
        file.open(save_T, ios::in);

        if (file.is_open()) {
            string line;
            int turn = 0;
            int index = 1;
            int i = 1;
            while (getline(file, line)) {
                if (turn == index) {
                    cout << i << ") " << line << endl;
                    index += 11;
                    i++;
                }
                turn++;
            }
            file.close();
            return i;
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

    void RemoveModel(const string save_T, string version) {
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
    }

    static void clearFile(const string save_T) {
        ofstream file;
        file.open(save_T, ios::out);

        file.close();

    }
};

int Model::licznik = 0;

void Dodajmodel() {

    cout << "Podaj marke: ";
    string marka;
    cin >> marka;

    cout << "Podaj wersje: ";
    string wersja;
    cin >> wersja;

    cout << "Podaj moc silnika: ";
    int moc_silnika;
    cin >> moc_silnika;

    cout << "Podaj rodzaj skrzyni biegow: ";
    string skrzynia_biegow;
    cin >> skrzynia_biegow;

    cout << "Podaj rodzaj paliwa: ";
    string paliwo;
    cin >> paliwo;

    cout << "Podaj srednie spalanie: ";
    float sr_spalanie;
    cin >> sr_spalanie;

    cout << "Podaj ilosc drzwi: ";
    int ilosc_drzwi;
    cin >> ilosc_drzwi;

    cout << "Podaj ilosc miejsc: ";
    int ilosc_miejsc;
    cin >> ilosc_miejsc;

    cout << "Podaj pojemnosc bagaznika: ";
    float poj_bagaznika;
    cin >> poj_bagaznika;

    cout << "Czy posiada klimatyzację? [1/ 0]: ";
    bool klimatyzacja;
    cin >> klimatyzacja;

    cout << "Podaj koszt godzinowy: ";
    float koszt_godzina;
    cin >> koszt_godzina;
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

    void Save(const string save_T) {
        ofstream file;
        file.open(save_T, ios::app);

        if (file.is_open()) {


            file.close();
        }
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
            system("CLS");
            cout << R"( _____________________________________ )" << endl;
            cout << R"(|  .--.                               |)" << endl;
            cout << R"(| /.-. '----------.    Operacje       |)" << endl;
            cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
            cout << R"(|  '--'                               |)" << endl;
            cout << R"(|_____________________________________|)" << endl;

            cout << endl << "Dodanie samochodu do bazy:" << endl;
            cout << "Wybierz model:" << endl;
            
            {
                int i = Model::ReadVersion("SaveModel");
                cout << i << ") Dodaj nowy model" << endl;
                cout << i + 1 << ") Powrot do menu" << endl;

                int wybor;
                cout << "Twoj wybor: ";
                cin >> wybor;

                if (wybor == i) {
                    
                    Dodajmodel();
                    
                }
                if (wybor == i + 1) {
                    goto repeat;
                }
            }

            

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


int main()
{
    Model::clearFile("SaveModel");
    Model BMW_serii_1("BMW", "118i M Sport", 140, "automatyczna", "benzyna", 5.9, 5, 5, 380, true, 230);
    Model Yaris("Toyota", "Yaris", 125, "manualna", "benzyna", 8.5, 5, 5, 255, true, 120);
    Model Vivaro("Opel", "Vivaro", 144, "automatyczna", "Diesel", 13.2, 5, 9, 1400, true, 490);
    menu();
    
    //BMW_serii_1.RemoveModel("SaveModel", 3);
    //BMW_serii_1.ReadVersion("SaveModel");
    //Samochod samochod1(BMW_serii_1, "KNS 83674", "czarny", 52350, 2019);
    //bmw.dodaj();
}