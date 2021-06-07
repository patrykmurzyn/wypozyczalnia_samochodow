#ifndef SAMOCHOD_HPP
#define SAMOCHOD_HPP
#include <string>

using namespace std;

#include "Model.hpp"

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

    static Model GetModel(string nazwa);

    static void CreateObj();

    static int Find(string nr_rej);

    static void Add(Model, string, string, int, int);

    static void Remove(int);

    static void ReadAll();

    friend class Model;
};

#endif