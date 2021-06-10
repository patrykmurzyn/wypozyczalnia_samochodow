#ifndef WYPOZYCZENIE_HPP
#define WYPOZYCZENIE_HPP
#include <string>
#include "Samochod.hpp"
#include "Klient.hpp"
#include "Pracownik.hpp"

using namespace std;

struct Date {
    string rok;
    string miesiac;
    string dzien;
    string godzina;
    string minuty;

    Date(string, string, string, string, string);
};

class Wypozyczenie {
    Date wyp_od;
    Date wyp_do;
    Klient k;
    Samochod s;
    Pracownik p;
    int wyp_przebieg;
    int zwr_przebieg;
    int status; //0 - anulowny, 1 - zarezerwowany, 2 - oderbrany, 3 -zwrocony
    int nr_zamowienia;
public:

    Wypozyczenie(Date, Date, Klient, Samochod, Pracownik, int, int, int, int);

    Wypozyczenie();

    static void CreateObj();

    static void Add(Date, Date, string, string, string,
        int, int, int, int);

    int GetNo();
    int GetStatus();
    static int Find(int);
    void Read();

    static void Cancel(int);
    static void Release(int, int);
    static void Reception(int, int);



    //Próba zrobienia kontroli dat rezerwacji samochodów
    //static bool CheckDate(Date, Date);
};


#endif