#include "Klient.hpp"
#include "Osoba.hpp"
#include "vectors.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Klient::Klient(string imie, string nazwisko, string pesel,
    string nr_tel) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->pesel = pesel;
    this->nr_tel = nr_tel;
}

Klient::Klient() {
    this->imie = "";
    this->nazwisko = "";
    this->pesel = "";
    this->nr_tel = "";
}

int Klient::Find(string pesel) {
    for (int i = 0; i < klient.size(); i++) {
        if (pesel == klient[i].pesel) {
            return i;
        }
    }
    return -1;
}

void Klient::CreateObj() {
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

void Klient::Add(string imie, string nazwisko, string pesel, string nr_tel) {
    ofstream file;
    file.open("SaveKlient", ios::app);

    if (file.is_open()) {
        file << imie << " " << nazwisko << " " << pesel << " " << nr_tel << endl;

        file.close();
    }

    klient.clear();
    Klient::CreateObj();
}