#include "Wypozyczenie.hpp"
#include "Klient.hpp"
#include "Samochod.hpp"
#include "Pracownik.hpp"
#include "vectors.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Date::Date(string r = "", string m = "", string d = "", string g = "", string min = "") {
    rok = r;
    miesiac = m;
    dzien = d;
    godzina = g;
    minuty = min;
}

Wypozyczenie::Wypozyczenie(Date wyp_od, Date wyp_do, Klient k,
    Samochod s, Pracownik p, int wyp_przebieg, int zwr_przebieg, int status, int nr_zamowienia)
{
    this->wyp_do = wyp_do;
    this->wyp_do = wyp_do;
    this->k = k;
    this->s = s;
    this->p = p;
    this->wyp_przebieg = wyp_przebieg;
    this->zwr_przebieg = zwr_przebieg;
    this->nr_zamowienia = nr_zamowienia;
    this->status = status;
}

Wypozyczenie::Wypozyczenie() {

}

void Wypozyczenie::CreateObj() {
    Wypozyczenie temp;
    string k, s, p;

    fstream file;
    file.open("SaveWypozyczenie", ios::in);

    if (file.is_open()) {

        while (file >> temp.wyp_od.rok >> temp.wyp_od.miesiac >>
            temp.wyp_od.dzien >> temp.wyp_od.godzina >>
            temp.wyp_od.minuty >> temp.wyp_do.rok >> temp.wyp_do.miesiac >>
            temp.wyp_do.dzien >> temp.wyp_do.godzina >>
            temp.wyp_do.minuty >> k >> s >> p >> temp.wyp_przebieg >> temp.zwr_przebieg >>
            temp.status >> temp.nr_zamowienia) {

            temp.k = klient[Klient::FindKlient(k)];
            temp.s = samochod[Samochod::FindSamochod(s)];
            temp.p = pracownik[Pracownik::FindPracownik(p)];

            wypozyczenie.push_back(temp);
        }
        file.close();
    }
}