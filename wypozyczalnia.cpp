#include <iostream>
#include <string>
#include <fstream>
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

    Model(string marka = "", string wersja = "", int moc_silnika = 0,
        string skrzynia_biegow = "", string paliwo = "", 
        float sr_spalanie = 0.0f, int ilosc_drzwi = 0,
        int ilosc_miejsc = 0, float poj_bagaznika = 0.0f, 
        bool klimatyzacja = 0, float koszt_godzina = 0.0f) {

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
    }

    void Save() {
        ofstream file;
        file.open("SaveModel", ios::app);

        if (file.is_open()) {
            file << marka << " " << wersja << " " << moc_silnika 
                << " " << skrzynia_biegow << " " << paliwo << " " 
                << sr_spalanie << " " << ilosc_drzwi << " " << 
                ilosc_miejsc << " " << poj_bagaznika << " " <<
                klimatyzacja << " " << koszt_godzina;

            file.close();
        }
    }


    friend void CreateModelObj();
    friend void ReadAllModel();
    friend void AddModel(string, string, int, string, string, float ,
        int, int, float, bool, float);
    friend void RemoveObjModel(int);
    friend class Samochod;
    friend void ReadAllSamochod();
    friend void AddSamochod(Model, string, string, int, int);
    friend void ReadAllModelVersion();
};

vector<Model> model;
vector<Samochod> samochod;

class Samochod {
    Model SamModel;
    string nr_rejestracyjny;
    string kolor;
    int przebieg;
    int rocznik;
public:
    static int licznik;

public:
    Samochod(Model model = Model(), string nr_rejestracyjny = "",
        string kolor = "", int przebieg = 0, int rocznik = 0) {
        this->SamModel = model;
        this->nr_rejestracyjny = nr_rejestracyjny;
        this->kolor = kolor;
        this->przebieg = przebieg;
        this->rocznik = rocznik;
    }

    static Model GetModel(string nazwa) {
        for (int i = 0; i < model.size(); i++) {
            if (model[i].wersja == nazwa) {
                return model[i];
            }
        }
    }



    friend void CreateSamochodObj();
    friend void ReadAllSamochod();
    friend void RemoveObjModel(int);
    friend void AddSamochod(Model, string, string, int, int);
};

struct Date {
    short rok;
    short miesiac;
    short dzien;
    short godzina;
    short minuty;
};

class Wypozyczenie {
    Date wyp_od;
    Date wyp_do;
    int wyp_przebieg;
    int zwr_przebieg;
    int nr_zamowienia;
public:
    Wypozyczenie(Date wyp_od = Date(), Date wyp_do = Date(), int wyp_przebieg = 0,
        int zwr_przebieg = 0, int nr_zamowienia = 0) {
        this->wyp_od = wyp_od;
        this->wyp_do = wyp_do;
        this->wyp_przebieg = wyp_przebieg;
        this->zwr_przebieg = zwr_przebieg;
        this->nr_zamowienia = nr_zamowienia;
    }

    friend void CreateWypozyczenieObj();
    friend void ReadAllWypozyczenia();
};

vector<Wypozyczenie> wypozyczenie;

class Osoba {
protected:
    string imie;
    string nazwisko;
    string pesel;
    string nr_tel;
public:
    Osoba(string imie = "", string nazwisko = "", string pesel = "",
        string nr_tel = "") {

        this->imie = imie;
        this->nazwisko = nazwisko;
        this->pesel = pesel;
        this->nr_tel = nr_tel;
    }
    virtual void dodaj() = 0;
};

class Klient :Osoba {
public:
    Klient(string imie = "", string nazwisko = "", string pesel = "",
        string nr_tel = "") : Osoba(imie, nazwisko, pesel, nr_tel) {}
    
    void dodaj() {

    }
    void znajdz(int pesel) {

    }
    void znajdz(string telefon) {

    }

    friend void CreateKlientObj();
    friend void ReadAllKlient();
};

vector<Klient> klient;

class Pracownik :Osoba {
    string stanowisko;
public:
    Pracownik(string imie = "", string nazwisko = "", string pesel = "",
        string nr_tel = "", string stanowisko = "") 
        : Osoba(imie, nazwisko, pesel, nr_tel), stanowisko(stanowisko) {}
    
    void dodaj() {

    }
    void usun() {

    }
    friend void CreatePracownikObj();
    friend void ReadAllPracownik();
};

vector<Pracownik> pracownik;

void CreatePracownikObj() {
    Pracownik temp;

    fstream file;
    file.open("SavePracownik", ios::in);

    if (file.is_open()) {
        while (file >> temp.imie >> temp.nazwisko >> temp.pesel >> temp.nr_tel >> temp.stanowisko) {
            pracownik.push_back(temp);
        }
        file.close();
    }
}

void ReadAllPracownik() {
    for (int i = 0; i < pracownik.size(); i++) {
        //cout << "Imie: " << pracownik[i].imie << endl;
        cout << "Nazwisko: " << pracownik[i].nazwisko << endl;
        //cout << "Pesel: " << pracownik[i].pesel << endl;
        //cout << "Telefon: " << pracownik[i].nr_tel << endl;
        //cout << "Stanowisko: " << pracownik[i].stanowisko << endl;
    }
}

void CreateKlientObj() {
    Klient temp;

    fstream file;
    file.open("SaveKlient", ios::in);

    if (file.is_open()) {
        while (file >> temp.imie >> temp.nazwisko >> temp.pesel >> temp.nr_tel) {
            klient.push_back(temp);
        }
        file.close();
    }
}

void ReadAllKlient() {
    for (int i = 0; i < klient.size(); i++) {
        //cout << "Imie: " << klient[i].imie << endl;
        cout << "Nazwisko: " << klient[i].nazwisko << endl;
        //cout << "Pesel: " << klient[i].pesel << endl;
        //cout << "Telefon: " << klient[i].nr_tel << endl;
    }
}

void AddKlient(string imie, string nazwisko, string pesel, string nr_tel) {
    ofstream file;
    file.open("SaveKlient", ios::app);

    if (file.is_open()) {
        file << endl << imie << " " << nazwisko << " " << pesel << " " << nr_tel;

        file.close();
    }

    klient.clear();
    CreateKlientObj();
}

void AddPracownik(string imie, string nazwisko, string pesel, string nr_tel, string stanowisko) {
    ofstream file;
    file.open("SaveKlient", ios::app);

    if (file.is_open()) {
        file << endl << imie << " " << nazwisko << " " << pesel << " " 
            << nr_tel << " " << stanowisko;

        file.close();
    }

    pracownik.clear();
    CreatePracownikObj();
}

void CreateWypozyczenieObj() {
    Wypozyczenie temp;

    fstream file;
    file.open("SaveWypozyczenie", ios::in);

    if (file.is_open()) {
        while (file >> temp.wyp_od.rok >> temp.wyp_od.miesiac >> 
            temp.wyp_od.dzien >> temp.wyp_od.godzina >> 
            temp.wyp_od.minuty >> temp.wyp_do.rok >> temp.wyp_do.miesiac >>
            temp.wyp_do.dzien >> temp.wyp_do.godzina >>
            temp.wyp_do.minuty >> temp.wyp_przebieg >> temp.zwr_przebieg >>
            temp.nr_zamowienia) {

            wypozyczenie.push_back(temp);
        }
        file.close();
    }
}

void ReadAllWypozyczenia() {
    for (int i = 0; i < wypozyczenie.size(); i++) {
        //cout << "Data wypozyczenia: " << 
            //wypozyczenie[i].wyp_od.rok << " " <<
            //wypozyczenie[i].wyp_od.miesiac << " " <<
            //wypozyczenie[i].wyp_od.dzien << " " << 
            //wypozyczenie[i].wyp_od.godzina << ":" <<
            //wypozyczenie[i].wyp_od.minuty << endl;
        //cout << "Data Oddania: " <<
            //wypozyczenie[i].wyp_do.rok << " " <<
            //wypozyczenie[i].wyp_do.miesiac << " " <<
            //wypozyczenie[i].wyp_do.dzien << " " <<
            //wypozyczenie[i].wyp_do.godzina << ":" <<
            //wypozyczenie[i].wyp_do.minuty << endl;
        //cout << "Wypozyczony przebieg: " <<
            //wypozyczenie[i].wyp_przebieg << endl;
        //cout << "Zwrocony przebieg: " <<
            //wypozyczenie[i].zwr_przebieg << endl;
        cout << "Numer zamowienia: " <<
            wypozyczenie[i].nr_zamowienia << endl;
    }
}

void CreateSamochodObj() {
    Samochod temp;

    fstream file;
    file.open("SaveSamochod", ios::in);

    if (file.is_open()) {
        string nazwa;
        while (file >> nazwa >> temp.nr_rejestracyjny >> temp.kolor
            >> temp.przebieg >> temp.rocznik) {

            temp.SamModel = Samochod::GetModel(nazwa);
            samochod.push_back(temp);
        }
        file.close();
    }
}

void ReadAllSamochod() {
    for (int i = 0; i < samochod.size(); i++) {
        //cout << "Model: " << samochod[i].SamModel.wersja << endl;
        cout << "Numer rejestracyjny: " << samochod[i].nr_rejestracyjny << endl;
        //cout << "Kolor: " << samochod[i].kolor << endl;
        //cout << "Przebieg: " << samochod[i].przebieg << endl;
        //cout << "Rocznik: " << samochod[i].rocznik << endl;
    }
}

void AddSamochod(Model m, string nr_rej, string kolor, int przebieg, int rocznik) {
    ofstream file;
    file.open("SaveSamochod", ios::app);

    if (file.is_open()) {
        file << endl << m.wersja << " " << nr_rej << " "
            << kolor << " " << przebieg << " " << rocznik;

        file.close();
    }

    samochod.clear();
    CreateSamochodObj();
}

void RemoveObjSamochod(int index) {
    fstream file_i;
    file_i.open("SaveSamochod", ios::in);

    string line;
    vector<string> vec;

    while (getline(file_i, line)) {
        vec.push_back(line);
    }
    file_i.close();

    fstream file_o;
    file_o.open("SaveSamochod", ios::out);

    for (int i = 0; i < vec.size(); i++) {
        if (i != index) {
            file_o << vec[i] << endl;
        }
    }

    file_o.close();

    samochod.clear();
    CreateSamochodObj();
}

void CreateModelObj() {
    Model temp;

    fstream file;
    file.open("SaveModel", ios::in);

    if (file.is_open()) {
        while (file >> temp.marka >> temp.wersja >> temp.moc_silnika >>
            temp.skrzynia_biegow >> temp.paliwo >> temp.sr_spalanie >>
            temp.ilosc_drzwi >> temp.ilosc_miejsc >> temp.poj_bagaznika >>
            temp.klimatyzacja >> temp.koszt_godzina) {

            model.push_back(temp);
        }
        file.close();
    }

}

void AddModel(string marka, string wersja, int moc_silnika,
    string skrzynia_biegow, string paliwo, float sr_spalanie,
    int ilosc_drzwi, int ilosc_miejsc, float poj_bagaznika,
    bool klimatyzacja, float koszt_godzina) {

    ofstream file;
    file.open("SaveModel", ios::app);

    if (file.is_open()) {
        file << endl << marka << " " << wersja << " "
            << moc_silnika << " " << skrzynia_biegow << " " 
            << paliwo << " " << sr_spalanie << " " << ilosc_drzwi 
            << " " << ilosc_miejsc << " " << poj_bagaznika << " " 
            << klimatyzacja << " " <<  koszt_godzina;

        file.close();
    }

    model.clear();
    CreateModelObj();
}

void RemoveObjModel(int index) {
    bool IsSamochod = false;

    for (int i = 0; i < samochod.size(); i++) {
        if (model[index].wersja == samochod[i].SamModel.wersja) {
            IsSamochod = true;
        }
    }
    if (IsSamochod) {
        cout << "Usun samochod o tym modelu przed ta operacja!" << endl;
    }
    else {
        fstream file_i;
        file_i.open("SaveModel", ios::in);

        string line;
        vector<string> vec;

        while (getline(file_i, line)) {
            vec.push_back(line);
        }
        file_i.close();

        fstream file_o;
        file_o.open("SaveModel", ios::out);

        for (int i = 0; i < vec.size(); i++) {
            if (i != index) {
                file_o << vec[i] << endl;
            }
        }

        file_o.close();

        model.clear();
        CreateModelObj();
    }
}

void ReadAllModel() {
    for (int i = 0; i < model.size(); i++) {
        cout << "Marka: " << model[i].marka << endl;
        cout << "Wersja: " << model[i].wersja << endl;
        cout << "Moc silnika: " <<model[i].moc_silnika << endl;
        cout << "Skrzynia biegow" << model[i].skrzynia_biegow << endl;
        cout << "Paliwo:" << model[i].paliwo << endl;
        cout << "Srednie spalanie: " << model[i].sr_spalanie << endl;
        cout << "Ilosc drzwi: " << model[i].ilosc_drzwi << endl;
        cout << "Ilosc miejsc: " << model[i].ilosc_miejsc << endl;
        cout << "Pojemnosc bagaznika: "<< model[i].poj_bagaznika << endl;
        cout << "Klimatyzacja: " << model[i].klimatyzacja << endl;
        cout << "Koszt za godzine: " << model[i].koszt_godzina << endl;
    }
}

void ReadAllModelVersion() {
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") " << model[i].marka << endl;
    }
}

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
                ReadAllModelVersion();
                cout << model.size() + 1 << ") Dodaj nowy model" << endl;
                cout << model.size() + 2 << ") Powrot do menu" << endl;

                int wybor;
                cout << "Twoj wybor: ";
                cin >> wybor;

                if (wybor >= 1 && wybor <= model.size()) {
                    
                } else if (wybor == model.size() + 1) {

                    string marka, wersja, skrzynia_biegow, paliwo;
                    int moc_silnika, ilosc_drzwi, ilosc_miejsc;
                    float sr_spalanie, poj_bagaznika, koszt_godzina;
                    bool klimatyzycja;
                    cout << "Wartosci nalezy wprowadzac bez uzycia spacji!" << endl;
                    cout << "Podaj marke: ";
                    cin >> marka;

                    cout << "Podaj wersje: ";
                    cin >> wersja;

                    cout << "Podaj rodzaj skrzyni biegow: ";
                    cin >> skrzynia_biegow;

                    cout << "Podaj rodzaj paliwa: ";
                    cin >> paliwo;

                    cout << "Podaj moc silnika: ";
                    cin >> moc_silnika;

                    cout << "Podaj ilosc drzwi: ";
                    cin >> ilosc_drzwi;

                    cout << "Podaj ilosc miejsc: ";
                    cin >> ilosc_miejsc;

                    cout << "Podaj srednie spalanie: ";
                    cin >> sr_spalanie;

                    cout << "Podaj pojemnosc bagaznika: ";
                    cin >> poj_bagaznika;

                    cout << "Podaj koszt godzinny: ";
                    cin >> koszt_godzina;

                    cout << "Czy posiada klimatyzacje? [0/ 1]: ";
                    cin >> klimatyzycja;

                    AddModel(marka, wersja, moc_silnika, skrzynia_biegow, paliwo, sr_spalanie,
                        ilosc_drzwi, ilosc_miejsc, poj_bagaznika, klimatyzycja, koszt_godzina);
                    goto repeat;

                } else if (wybor == model.size() + 2) {
                    goto repeat;
                }
                else {
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
    CreateModelObj();
    CreateKlientObj();
    CreatePracownikObj();
    CreateSamochodObj();
    CreateWypozyczenieObj();

    menu();
}