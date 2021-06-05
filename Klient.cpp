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

}

string Klient::GetName() {
    return imie;
}

int Klient::FindKlient(string pesel) {
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