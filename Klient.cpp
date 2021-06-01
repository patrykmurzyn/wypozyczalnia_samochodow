#include "Klient.hpp"
#include "Osoba.hpp"
#include <iostream>
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