#ifndef MODEL_HPP
#define MODEL_HPP
#include <string>

using namespace std;

class Model {
    string marka;
    string wersja;
    int moc_silnika;
    string skrzynia_biegow;
    string paliwo;
    float sr_spalanie;
    int ilosc_drzwi;
    int ilosc_miejsc;
    float poj_bagaznika;
    bool klimatyzacja;
    float koszt_godzina;

public:

    Model(string, string, int, string, string, float, int, int, float, bool, float);

    Model();

    static void CreateObjs();

    static void ReadAll();

    friend class Samochod;

};

#endif