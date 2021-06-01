#include "Osoba.hpp"
#include <iostream>
#include <string>

using namespace std;

Osoba::Osoba(string imie, string nazwisko, string pesel,
    string nr_tel) {

    this->imie = imie;
    this->nazwisko = nazwisko;
    this->pesel = pesel;
    this->nr_tel = nr_tel;
}

Osoba::Osoba() {

    this->imie = "";
    this->nazwisko = "";
    this->pesel = "";
    this->nr_tel = "";
}