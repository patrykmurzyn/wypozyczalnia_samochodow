#include "Samochod.hpp"
#include "vectors.hpp"
#include <iostream>
#include <fstream>

DateOC::DateOC() {
    rok = "";
    miesiac = "";
    dzien = "";
}

DateOC::DateOC(string rok, string miesiac, string dzien) {
    this->rok = rok;
    this->miesiac = miesiac;
    this->dzien = dzien;
}

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
            >> temp.przebieg >> temp.rocznik >> temp.OC.rok >> temp.OC.miesiac >> temp.OC.dzien) {

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

void Samochod::Add(Model m, string nr_rej, string kolor, int przebieg, int rocznik, DateOC oc) {
    ofstream file;
    file.open("SaveSamochod", ios::app);

    if (file.is_open()) {
        file << m.wersja << " " << nr_rej << " "
            << kolor << " " << przebieg << " " << rocznik 
            << " " << oc.rok << " " << oc.miesiac << " " << oc.dzien << endl;

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

void Samochod::ReadAll() {
    for (int i = 0; i < samochod.size(); i++) {
        cout << i + 1 << ") Model: " << samochod[i].SamModel.wersja << endl;
        cout << "Numer rejestracyjny: " << samochod[i].nr_rejestracyjny << endl;
        cout << "Kolor: " << samochod[i].kolor << endl;
        cout << "Przebieg: " << samochod[i].przebieg << endl;
        cout << "Rocznik: " << samochod[i].rocznik << endl << endl;
    }
}

string Samochod::GetNrRej(int index) {
    return samochod[index].nr_rejestracyjny;
}

string Samochod::GetNrRej() {
    return nr_rejestracyjny;
}

void Samochod::AddOC(string r, string m, string d) {
    OC.rok = r;
    OC.miesiac = m;
    OC.dzien = d;
}

void Samochod::ReadAllOC() {
    cout << "Numer rejestracyjny oraz termin wa¿noœci OC: " << endl;
    
    for (int i = 0; i < samochod.size(); i++) {
        
        cout << "Numer rejestracyjny: " << samochod[i].nr_rejestracyjny <<
            ": " << samochod[i].OC.rok << "-" << samochod[i].OC.miesiac <<
            "-" << samochod[i].OC.dzien << ", 00:00" << endl;
    }
}

void Samochod::ChangeOC(int index, string rok, string miesiac, string dzien) {
    samochod[index].OC.rok = rok;
    samochod[index].OC.miesiac = miesiac;
    samochod[index].OC.dzien = dzien;

    fstream file_o;
    file_o.open("SaveSamochod", ios::out);

    ofstream file_;
    file_.open("SaveSamochod", ios::app);

    if (file_.is_open()) {
        for (int i = 0; i < samochod.size(); i++) {
            file_ << samochod[i].SamModel.wersja << " " << samochod[i].nr_rejestracyjny << " "
                << samochod[i].kolor << " " << samochod[i].przebieg << " " << samochod[i].rocznik
                << " " << samochod[i].OC.rok << " " << samochod[i].OC.miesiac << " " << samochod[i].OC.dzien << endl;
        }
    }

    file_.close();

}