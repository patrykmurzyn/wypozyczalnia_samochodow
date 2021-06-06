#include "Samochod.hpp"
#include "vectors.hpp"
#include <iostream>
#include <fstream>

bool Samochod::IsModel(int index) {
    for (int i = 0; i < samochod.size(); i++) {
        if (model[index].wersja == samochod[i].SamModel.wersja) {
            return true;
        }
    }
    return false;
}

Model Samochod::GetModel(string nazwa) {
    for (int i = 0; i < model.size(); i++) {
        if (model[i].wersja == nazwa) {
            return model[i];
        }
    }
}

void Samochod::CreateObj() {
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

void Samochod::RemoveObjModel(int index) {

    if (Samochod::IsModel(index)) {
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
        Model::CreateObj();
    }
}

int Samochod::Find(string nr_rej) {
    for (int i = 0; i < samochod.size(); i++) {
        if (nr_rej == samochod[i].nr_rejestracyjny) {
            return i;
        }
    }
    return -1;
}

void Samochod::Add(Model m, string nr_rej, string kolor, int przebieg, int rocznik) {
    ofstream file;
    file.open("SaveSamochod", ios::app);

    if (file.is_open()) {
        file << m.wersja << " " << nr_rej << " "
            << kolor << " " << przebieg << " " << rocznik << endl;

        file.close();
    }

    samochod.clear();
    CreateObj();
}

void Samochod::Remove(int index) {
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

    for (int i = 0; i < vec.size() - 1; i++) {
        if (i != index) {
            file_o << vec[i] << endl;
        }
    }

    file_o.close();

    samochod.clear();
    CreateObj();
}