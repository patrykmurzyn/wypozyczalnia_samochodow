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

//Date::Date() {

//}

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

            temp.k = klient[Klient::Find(k)];
            temp.s = samochod[Samochod::Find(s)];
            temp.p = pracownik[Pracownik::Find(p)];

            wypozyczenie.push_back(temp);
        }
        file.close();
    }
}

void Wypozyczenie::Add(Date wod, Date wdo, string k, string s, string p,
    int wyp_przebieg, int zwr_przebieg, int status, int nr_zam) {

    ofstream file;
    file.open("SaveWypozyczenie", ios::app);

    if (file.is_open()) {
        file << wod.rok << " " << wod.miesiac << " " << wod.dzien <<
            " " << wod.godzina << " " << wod.minuty << " " << wdo.rok <<
            " " << wdo.miesiac << " " << wdo.dzien <<
            " " << wdo.godzina << " " << wdo.minuty << " " <<
            k << " " << s << " " << p << " " << wyp_przebieg << " " <<
            zwr_przebieg << " " << status << " " << nr_zam << endl;

        file.close();
    }

    wypozyczenie.clear();
    Wypozyczenie::CreateObj();
}

int Wypozyczenie::GetNo() {
    return nr_zamowienia;
}

int Wypozyczenie::Find(int nr_zam) {
    for (int i = 0; i < wypozyczenie.size(); i++) {
        if (nr_zam == wypozyczenie[i].nr_zamowienia) {
            return i;
        }
    }
    return -1;
}

void Wypozyczenie::Read(int nr_zam) {
    cout << " Wypozyczenie od: " << wypozyczenie[nr_zam].wyp_od.rok << "-" << wypozyczenie[nr_zam].wyp_od.miesiac <<
        "-" << wypozyczenie[nr_zam].wyp_od.dzien << " godz: " << wypozyczenie[nr_zam].wyp_od.godzina << " : " <<
        wypozyczenie[nr_zam].wyp_od.minuty << endl;
    cout << " Wypozyczenie do: " << wypozyczenie[nr_zam].wyp_do.rok << "-" << wypozyczenie[nr_zam].wyp_do.miesiac <<
        "-" << wypozyczenie[nr_zam].wyp_do.dzien << " godz: " << wypozyczenie[nr_zam].wyp_do.godzina << " : " <<
        wypozyczenie[nr_zam].wyp_do.minuty << endl;
    cout << " Pesel klienta: " << wypozyczenie[nr_zam].k.GetPesel() << endl;
    cout << " Numer rejestracyjny samochodu: " << wypozyczenie[nr_zam].s.GetNrRej(nr_zam) << endl;
    cout << " Status wypozyczenia: " << wypozyczenie[nr_zam].status << endl;
}