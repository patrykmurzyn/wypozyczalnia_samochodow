#ifndef OSOBA_HPP
#define OSOBA_HPP
#include <string>

using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
    string pesel;
    string nr_tel;
public:

    Osoba(string, string, string, string);

    Osoba();

    string GetPesel();

    //virtual void dodaj() = 0;
};

#endif