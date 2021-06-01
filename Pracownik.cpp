#include "Pracownik.hpp"
#include "Osoba.hpp"
#include <iostream>
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