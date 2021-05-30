#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Model;
class Samochod;
class Osoba;
class Klient;
class Pracownik;
class Wypozyczenie;

vector<Model> model;
vector<Samochod> samochod;
vector<Klient> klient;
vector<Pracownik> pracownik;
vector<Wypozyczenie> wypozyczenie;

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
    Model(string marka = "", string wersja = "", int moc_silnika = 0,
        string skrzynia_biegow = "", string paliwo = "",
        float sr_spalanie = 0.0f, int ilosc_drzwi = 0,
        int ilosc_miejsc = 0, float poj_bagaznika = 0.0f,
        bool klimatyzacja = 0, float koszt_godzina = 0.0f) {

        this->marka = marka;
        this->wersja = wersja;
        this->moc_silnika = moc_silnika;
        this->skrzynia_biegow = skrzynia_biegow;
        this->paliwo = paliwo;
        this->sr_spalanie = sr_spalanie;
        this->ilosc_drzwi = ilosc_drzwi;
        this->ilosc_miejsc = ilosc_miejsc;
        this->poj_bagaznika = poj_bagaznika;
        this->klimatyzacja = klimatyzacja;
        this->koszt_godzina = koszt_godzina;
    }

    static void CreateModelObj() {
        Model temp;

        fstream file;
        file.open("SaveModel", ios::in);

        if (file.is_open()) {
            while (file >> temp.marka >> temp.wersja >> temp.moc_silnika >>
                temp.skrzynia_biegow >> temp.paliwo >> temp.sr_spalanie >>
                temp.ilosc_drzwi >> temp.ilosc_miejsc >> temp.poj_bagaznika >>
                temp.klimatyzacja >> temp.koszt_godzina) {

                model.push_back(temp);
            }
            file.close();
        }
    }


};

class Samochod {

};

class Osoba {

};

class Klient :Osoba {

};

class Pracownik :Osoba {

};

class Wypozyczenie {

};

int main()
{
    std::cout << "Hello World!\n";
}
