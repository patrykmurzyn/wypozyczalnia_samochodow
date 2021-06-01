#ifndef PRACOWNIK_HPP
#define PRACOWNIK_HPP
#include <string>
#include "Osoba.hpp"

using namespace std;

class Pracownik :Osoba {
    string stanowisko;
public:

    Pracownik(string, string, string,
        string, string);

    Pracownik();
};

#endif