#include "Pracownik.hpp"
#include "Osoba.hpp"
#include "vectors.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Pracownik::Pracownik(string imie, string nazwisko, string pesel,
    string nr_tel, string stanowisko)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->pesel = pesel;
    this->nr_tel = nr_tel;
    this->stanowisko = stanowisko;
}

Pracownik::Pracownik() {

}

void Pracownik::CreateObj() {
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

int Pracownik::FindPracownik(string pesel) {
    for (int i = 0; i < pracownik.size(); i++) {
        if (pesel == pracownik[i].pesel) {
            return i;
        }
    }
    return -1;
}