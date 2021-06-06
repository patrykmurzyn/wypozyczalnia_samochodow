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

    static void CreateObj();

    static void Add(string, string, string, string, string);

    static int Find(string pesel);
};

#endif