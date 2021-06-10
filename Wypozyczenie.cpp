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

Wypozyczenie::Wypozyczenie()
{
    this->wyp_do = Date();
    this->wyp_do = Date();
    this->k = Klient();
    this->s = Samochod();
    this->p = Pracownik();
    this->wyp_przebieg = 0;
    this->zwr_przebieg = 0;
    this->nr_zamowienia = 0;
    this->status = -1;
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

void Wypozyczenie::Read() {
    cout << " Wypozyczenie od: " << wyp_od.rok << "-" << wyp_od.miesiac <<
        "-" << wyp_od.dzien << " godz: " << wyp_od.godzina << ":" <<
        wyp_od.minuty << endl;
    cout << " Wypozyczenie do: " << wyp_do.rok << "-" << wyp_do.miesiac <<
        "-" <<wyp_do.dzien << " godz: " << wyp_do.godzina << ":" <<
        wyp_do.minuty << endl;
    cout << " Pesel klienta: " << k.GetPesel() << endl;
    cout << " Numer rejestracyjny samochodu: " << s.GetNrRej() << endl;
    cout << " Status wypozyczenia: " << status << endl;
}

int Wypozyczenie::GetStatus() {
    return status;
}

void Wypozyczenie::Cancel(int index) {
    wypozyczenie[index].status = 0;

    ofstream file;
    file.open("SaveWypozyczenie", ios::out);
    file.close();

    ofstream file_;
    file_.open("SaveWypozyczenie", ios::app);

    if (file_.is_open()) {
        for (int i = 0; i < wypozyczenie.size(); i++) {
            file_ << wypozyczenie[i].wyp_od.rok << " " << wypozyczenie[i].wyp_od.miesiac << " " << wypozyczenie[i].wyp_od.dzien <<
                " " << wypozyczenie[i].wyp_od.godzina << " " << wypozyczenie[i].wyp_od.minuty << " " << wypozyczenie[i].wyp_do.rok <<
                " " << wypozyczenie[i].wyp_do.miesiac << " " << wypozyczenie[i].wyp_do.dzien <<
                " " << wypozyczenie[i].wyp_do.godzina << " " << wypozyczenie[i].wyp_do.minuty << " " <<
                wypozyczenie[i].k.GetPesel() << " " << wypozyczenie[i].s.GetNrRej() << " " << wypozyczenie[i].p.GetPesel() << " " << wypozyczenie[i].wyp_przebieg << " " <<
                wypozyczenie[i].zwr_przebieg << " " << wypozyczenie[i].status << " " << wypozyczenie[i].nr_zamowienia << endl;
        }
    }

    file_.close();
}

void Wypozyczenie::Release(int index, int wyp_przebieg) {
    wypozyczenie[index].status = 2;

    ofstream file;
    file.open("SaveWypozyczenie", ios::out);
    file.close();

    ofstream file_;
    file_.open("SaveWypozyczenie", ios::app);

    if (file_.is_open()) {
        for (int i = 0; i < wypozyczenie.size(); i++) {
            file_ << wypozyczenie[i].wyp_od.rok << " " << wypozyczenie[i].wyp_od.miesiac << " " << wypozyczenie[i].wyp_od.dzien <<
                " " << wypozyczenie[i].wyp_od.godzina << " " << wypozyczenie[i].wyp_od.minuty << " " << wypozyczenie[i].wyp_do.rok <<
                " " << wypozyczenie[i].wyp_do.miesiac << " " << wypozyczenie[i].wyp_do.dzien <<
                " " << wypozyczenie[i].wyp_do.godzina << " " << wypozyczenie[i].wyp_do.minuty << " " <<
                wypozyczenie[i].k.GetPesel() << " " << wypozyczenie[i].s.GetNrRej() << " " << wypozyczenie[i].p.GetPesel() << " " << wyp_przebieg << " " <<
                wypozyczenie[i].zwr_przebieg << " " << wypozyczenie[i].status << " " << wypozyczenie[i].nr_zamowienia << endl;
        }
    }

    file_.close();
}

void Wypozyczenie::Reception(int index, int zwr_przebieg) {
    wypozyczenie[index].status = 3;

    ofstream file;
    file.open("SaveWypozyczenie", ios::out);
    file.close();

    ofstream file_;
    file_.open("SaveWypozyczenie", ios::app);

    if (file_.is_open()) {
        for (int i = 0; i < wypozyczenie.size(); i++) {
            file_ << wypozyczenie[i].wyp_od.rok << " " << wypozyczenie[i].wyp_od.miesiac << " " << wypozyczenie[i].wyp_od.dzien <<
                " " << wypozyczenie[i].wyp_od.godzina << " " << wypozyczenie[i].wyp_od.minuty << " " << wypozyczenie[i].wyp_do.rok <<
                " " << wypozyczenie[i].wyp_do.miesiac << " " << wypozyczenie[i].wyp_do.dzien <<
                " " << wypozyczenie[i].wyp_do.godzina << " " << wypozyczenie[i].wyp_do.minuty << " " <<
                wypozyczenie[i].k.GetPesel() << " " << wypozyczenie[i].s.GetNrRej() << " " << wypozyczenie[i].p.GetPesel() << " " << wypozyczenie[i].wyp_przebieg << " " <<
                zwr_przebieg << " " << wypozyczenie[i].status << " " << wypozyczenie[i].nr_zamowienia << endl;
        }
    }

    file_.close();
}



/* Próba zrobienia kontroli dat rezerwacji samochodów

bool Wypozyczenie::CheckDate(Date wyp_od, Date wyp_do) {

    int ile1 = 0, ile2 = 0;

    while (wyp_od.rok == wyp_do.rok && wyp_od.miesiac == wyp_do.miesiac
        && wyp_od.dzien == wyp_do.dzien) {

        ile1++;

        wyp_od.dzien = atoi(wyp_od.dzien.c_str() + 1);

        if (atoi(wyp_od.dzien.c_str()) > 31) {
            wyp_od.dzien = "1";
            wyp_od.miesiac = atoi(wyp_od.miesiac.c_str() + 1);
        }
        if (atoi(wyp_od.miesiac.c_str()) > 12) {
            wyp_od.miesiac = "1";
            wyp_od.rok = atoi(wyp_od.rok.c_str() + 1);
        }
    }

    for (int i = 0; i < wypozyczenie.size(); i++) {
        if (wypozyczenie[i].status == 1 || wypozyczenie[i].status == 2) {

            Date wyp_od_zar = wypozyczenie[i].wyp_od;
            ile2 = 0;

            while (wyp_od_zar.rok == wypozyczenie[i].wyp_do.rok &&
                wyp_od_zar.miesiac == wypozyczenie[i].wyp_do.miesiac &&
                wyp_od_zar.dzien == wypozyczenie[i].wyp_do.dzien) {

                ile2++;

                wyp_od_zar.dzien = atoi(wyp_od_zar.dzien.c_str() + 1);

                if (atoi(wyp_od_zar.dzien.c_str()) > 31) {
                    wyp_od_zar.dzien = "1";
                    wyp_od_zar.miesiac = atoi(wyp_od_zar.miesiac.c_str() + 1);
                }
                if (atoi(wyp_od_zar.miesiac.c_str()) > 12) {
                    wyp_od_zar.miesiac = "1";
                    wyp_od_zar.rok = atoi(wyp_od_zar.rok.c_str() + 1);
                }
            }

            if (ile1 > ile2) {
                while (wyp_od.rok == wyp_do.rok && wyp_od.miesiac == wyp_do.miesiac
                    && wyp_od.dzien == wyp_do.dzien) {

                    if (wyp_od.rok == wypozyczenie[i].wyp_od.rok &&
                        wyp_od.miesiac == wypozyczenie[i].wyp_od.miesiac &&
                        wyp_od.dzien == wypozyczenie[i].wyp_od.dzien) {

                    }
                    if (wyp_od.rok == wypozyczenie[i].wyp_do.rok &&
                        wyp_od.miesiac == wypozyczenie[i].wyp_do.miesiac &&
                        wyp_od.dzien == wypozyczenie[i].wyp_do.dzien) {

                    }
                }
            }
            else {
                while (wyp_od_zar.rok == wypozyczenie[i].wyp_do.rok &&
                    wyp_od_zar.miesiac == wypozyczenie[i].wyp_do.miesiac &&
                    wyp_od_zar.dzien == wypozyczenie[i].wyp_do.dzien) {

                    if (wyp_od.rok == wypozyczenie[i].wyp_od.rok &&
                        wyp_od.miesiac == wypozyczenie[i].wyp_od.miesiac &&
                        wyp_od.dzien == wypozyczenie[i].wyp_od.dzien) {

                    }
                    if (wyp_od.rok == wypozyczenie[i].wyp_do.rok &&
                        wyp_od.miesiac == wypozyczenie[i].wyp_do.miesiac &&
                        wyp_od.dzien == wypozyczenie[i].wyp_do.dzien) {

                    }
                }
            }
        }
    }
    return 0;
}

*/
