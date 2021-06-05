#ifndef KLIENT_HPP
#define KLIENT_HPP
#include <string>
#include "Osoba.hpp"

using namespace std;

class Klient :public Osoba {
public:
    Klient(string , string, string, string);

    Klient();

    string GetName();

    static void CreateObj();

    static int FindKlient(string pesel);
};

#endif