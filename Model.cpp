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
    this->marka = "";
    this->wersja = "";
    this->moc_silnika = 0;
    this->skrzynia_biegow = "";
    this->paliwo = "";
    this->sr_spalanie = 0;
    this->ilosc_drzwi = 0;
    this->ilosc_miejsc = 0;
    this->poj_bagaznika = 0;
    this->klimatyzacja = 0;
    this->koszt_godzina = 0;
}

void Model::CreateObj() {
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
    setlocale(LC_ALL, "pl_PL");
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") Marka: " << model[i].marka << endl;
        cout << "Wersja: " << model[i].wersja << endl;
        cout << "Moc silnika: " << model[i].moc_silnika << endl;
        cout << "Skrzynia biegów" << model[i].skrzynia_biegow << endl;
        cout << "Paliwo:" << model[i].paliwo << endl;
        cout << "Œrednie spalanie: " << model[i].sr_spalanie << endl;
        cout << "Iloœc drzwi: " << model[i].ilosc_drzwi << endl;
        cout << "Iloœc miejsc: " << model[i].ilosc_miejsc << endl;
        cout << "Pojemnoœc baga¿nika: " << model[i].poj_bagaznika << endl;
        cout << "Klimatyzacja: " << model[i].klimatyzacja << endl;
        cout << "Koszt za godzine: " << model[i].koszt_godzina << endl << endl;
    }
}

void Model::ReadAllVersion() {
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") " << model[i].wersja << endl;
    }
}

void Model::Add(string marka, string wersja, int moc_silnika,
    string skrzynia_biegow, string paliwo, float sr_spalanie,
    int ilosc_drzwi, int ilosc_miejsc, float poj_bagaznika,
    bool klimatyzacja, float koszt_godzina) {

    ofstream file;
    file.open("SaveModel", ios::app);

    if (file.is_open()) {
        file << marka << " " << wersja << " "
            << moc_silnika << " " << skrzynia_biegow << " "
            << paliwo << " " << sr_spalanie << " " << ilosc_drzwi
            << " " << ilosc_miejsc << " " << poj_bagaznika << " "
            << klimatyzacja << " " << koszt_godzina << endl;

        file.close();
    }

    model.clear();
    Model::CreateObj();
}

void Model::Remove(int index) {
    bool IsSamochod = false;

    for (int i = 0; i < samochod.size(); i++) {
        if (model[index].wersja == samochod[i].SamModel.wersja) {
            IsSamochod = true;
        }
    }
    if (IsSamochod) {
        setlocale(LC_ALL, "pl_PL");
        cout << "Usuñ samochód o tym modelu przed t¹ operacj¹!" << endl;
        system("pause");
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
        CreateObj();
    }
}
bool Model::Compare(Model mod) {
    if (marka == mod.marka && wersja == mod.wersja
        && moc_silnika == mod.moc_silnika && skrzynia_biegow == mod.skrzynia_biegow
        && paliwo == mod.paliwo && sr_spalanie == mod.sr_spalanie
        && ilosc_drzwi == mod.ilosc_drzwi && ilosc_miejsc == mod.ilosc_miejsc
        && poj_bagaznika == mod.poj_bagaznika && klimatyzacja == mod.klimatyzacja
        && koszt_godzina == mod.koszt_godzina) {

        return 1;
    }
    else {
        return 0;
    }
}