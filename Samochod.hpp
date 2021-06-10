#ifndef SAMOCHOD_HPP
#define SAMOCHOD_HPP
#include <string>

using namespace std;

#include "Model.hpp"

struct DateOC {
    string rok;
    string miesiac;
    string dzien;
    DateOC();
    DateOC(string, string, string);
};

class Samochod {
    Model SamModel;
    string nr_rejestracyjny;
    string kolor;
    int przebieg;
    int rocznik;
    DateOC OC;

public:

    Samochod(Model model = Model(), string nr_rejestracyjny = "",
        string kolor = "", int przebieg = 0, int rocznik = 0, DateOC OC = DateOC()) {
        this->SamModel = model;
        this->nr_rejestracyjny = nr_rejestracyjny;
        this->kolor = kolor;
        this->przebieg = przebieg;
        this->rocznik = rocznik;
    }

    static bool IsModel(int index);

    static void RemoveObjModel(int index);

    static Model GetModel(string nazwa);

    static void CreateObj();

    static int Find(string nr_rej);

    static void Add(Model, string, string, int, int, DateOC);

    static void Remove(int);

    static void ReadAll();

    static string GetNrRej(int);

    string GetNrRej();

    void AddOC(string, string, string);

    void ChangeOC(int);

    static void ReadAllOC();

    friend class Model;
};

#endif