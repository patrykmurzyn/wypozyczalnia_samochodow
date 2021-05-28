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
    friend void RemoveObjModel(int);
    friend class Samochod;
    friend void ReadAllSamochod();
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

    void Save() {
        ofstream file;
        file.open("SaveSamochod", ios::app);

        if (file.is_open()) {
            file << SamModel.wersja << " " << nr_rejestracyjny << " " 
                << kolor << " " << przebieg << " " << rocznik;

            file.close();
        }
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
        //cout << "Wersja: " << model[i].wersja << endl;
        //cout << "Moc silnika: " <<model[i].moc_silnika << endl;
        //cout << "Skrzynia biegow" << model[i].skrzynia_biegow << endl;
        //cout << "Paliwo:" << model[i].paliwo << endl;
        //cout << "Srednie spalanie: " << model[i].sr_spalanie << endl;
        //cout << "Ilosc drzwi: " << model[i].ilosc_drzwi << endl;
        //cout << "Ilosc miejsc: " << model[i].ilosc_miejsc << endl;
        //cout << "Pojemnosc bagaznika: "<< model[i].poj_bagaznika << endl;
        //cout << "Klimatyzacja: " << model[i].klimatyzacja << endl;
        //cout << "Koszt za godzine: " << model[i].koszt_godzina << endl;
    }
}



int main()
{
    CreateModelObj();
    ReadAllModel();

    cout << "##########################" << endl;

    CreateSamochodObj();
    ReadAllSamochod();

    cout << "##########################" << endl;

    CreateWypozyczenieObj();
    ReadAllWypozyczenia();

    cout << "##########################" << endl;

    CreateKlientObj();
    ReadAllKlient();

    cout << "##########################" << endl;

    CreatePracownikObj();
    ReadAllPracownik();
}

//SaveModel
//BMW 118i 140 automatyczna benzyna 5.9 5 5 380 1 230
//Toyota Yaris 125 manualna benzyna 8.5 5 5 255 1 120
//Opel Vivaro 144 automatyczna Diesel 13.2 5 9 1400 1 490

//SaveSamochod
//118i KRSPEED czerwony 15000 2020
//Yaris KR93483 czarny 22000  2020
//Vivaro KR84934 bialy 35000 2019

//SaveWypozyczenie
//2021 05 26 13 30 2021 05 28 15 00 18000 18040 0
//2021 05 30 13 30 2021 05 31 16 00 18000 18040 1
//2021 06 02 12 00 2021 06 05 19 00 18000 18040 2
//2021 06 03 09 30 0 0 0 0 0 18000 0 3
//2021 06 04 17 15 0 0 0 0 0 18000 0 4

//SaveKlient
//Jan Nowak 97061304653 495483940
//Adam Kowalski 92012246125 945563649
//Klaudia Wisniewska 601101324507 639823695
//Artur Zielinski 72030892834 926394036

//SavePracownicy
//Szymon Kowalczyk 96101008793 937493023 recepcjonista
//Kamil Lewandowski 94032303943 935643294 recepcjonista
//Grzegorz Kaminski 70120393234 372935394 serwisant
