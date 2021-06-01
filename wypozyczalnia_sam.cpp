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

    static void CreateObjs();

    static void ReadAll();

    friend class Samochod;

};

void Model::CreateObjs() {
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

void Model::ReadAll() {
    for (int i = 0; i < model.size(); i++) {
        cout << i + 1 << ") Marka: " << model[i].marka << endl;
        cout << "Wersja: " << model[i].wersja << endl;
        cout << "Moc silnika: " << model[i].moc_silnika << endl;
        cout << "Skrzynia biegow" << model[i].skrzynia_biegow << endl;
        cout << "Paliwo:" << model[i].paliwo << endl;
        cout << "Srednie spalanie: " << model[i].sr_spalanie << endl;
        cout << "Ilosc drzwi: " << model[i].ilosc_drzwi << endl;
        cout << "Ilosc miejsc: " << model[i].ilosc_miejsc << endl;
        cout << "Pojemnosc bagaznika: " << model[i].poj_bagaznika << endl;
        cout << "Klimatyzacja: " << model[i].klimatyzacja << endl;
        cout << "Koszt za godzine: " << model[i].koszt_godzina << endl << endl;
    }
}

class Samochod {
    Model SamModel;
    string nr_rejestracyjny;
    string kolor;
    int przebieg;
    int rocznik;

public:

    Samochod(Model model = Model(), string nr_rejestracyjny = "",
        string kolor = "", int przebieg = 0, int rocznik = 0) {
        this->SamModel = model;
        this->nr_rejestracyjny = nr_rejestracyjny;
        this->kolor = kolor;
        this->przebieg = przebieg;
        this->rocznik = rocznik;
    }

    static bool IsModel(int index);

    static void RemoveObjModel(int index);

    friend class Model;
};

bool Samochod::IsModel(int index){
    for (int i = 0; i < samochod.size(); i++) {
        if (model[index].wersja == samochod[i].SamModel.wersja) {
            return true;
        }
    }
    return false;
}

void Samochod::RemoveObjModel(int index) {

    if (Samochod::IsModel(index)) {
        cout << "Usun samochod o tym modelu przed ta operacja!" << endl;
        system("pause");
    }
    else {
        fstream file_i;
        file_i.open("SaveModel", ios::in);

        string line;
        vector<string> vec;

        while (getline(file_i, line)) {
            vec.push_back(line);
        }
        file_i.close();

        fstream file_o;
        file_o.open("SaveModel", ios::out);

        for (int i = 0; i < vec.size(); i++) {
            if (i != index) {
                file_o << vec[i] << endl;
            }
        }

        file_o.close();

        model.clear();
        Model::CreateObjs();
    }
}

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
    Model::CreateObjs();
    Model::ReadAll();
    Samochod::RemoveObjModel(2);
    Model::ReadAll();
}
