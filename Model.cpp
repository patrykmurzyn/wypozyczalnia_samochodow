#include "Model.hpp"
#include <iostream>
#include <fstream>

#include "vectors.hpp"

using namespace std;

Model::Model(string marka, string wersja, int moc_silnika,
    string skrzynia_biegow, string paliwo,
    float sr_spalanie, int ilosc_drzwi,
    int ilosc_miejsc, float poj_bagaznika,
    bool klimatyzacja, float koszt_godzina) {

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

Model::Model() {

}

void Model::CreateObjs() {
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

void Model::ReadAll() {
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") Marka: " << model[i].marka << endl;
        cout << "Wersja: " << model[i].wersja << endl;
        cout << "Moc silnika: " << model[i].moc_silnika << endl;
        cout << "Skrzynia biegow" << model[i].skrzynia_biegow << endl;
        cout << "Paliwo:" << model[i].paliwo << endl;
        cout << "Srednie spalanie: " << model[i].sr_spalanie << endl;
        cout << "Ilosc drzwi: " << model[i].ilosc_drzwi << endl;
        cout << "Ilosc miejsc: " << model[i].ilosc_miejsc << endl;
        cout << "Pojemnosc bagaznika: " << model[i].poj_bagaznika << endl;
        cout << "Klimatyzacja: " << model[i].klimatyzacja << endl;
        cout << "Koszt za godzine: " << model[i].koszt_godzina << endl << endl;
    }
}

void Model::ReadAllVersion() {
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") " << model[i].marka << endl;
    }
}