﻿#include <iostream>
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

    RemoveObjModel(1);
}

//BMW 118i 140 automatyczna benzyna 5.9 5 5 380 1 230
//Toyota Yaris 125 manualna benzyna 8.5 5 5 255 1 120
//Opel Vivaro 144 automatyczna Diesel 13.2 5 9 1400 1 490