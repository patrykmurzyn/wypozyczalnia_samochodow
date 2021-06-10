#ifndef KLIENT_HPP
#define KLIENT_HPP
#include <string>
#include "Osoba.hpp"

using namespace std;

class Klient :public Osoba {
public:
    Klient(string , string, string, string);

    Klient();

    static void CreateObj();

    static void Add(string, string, string, string);

    static int Find(string pesel);
};

#endif