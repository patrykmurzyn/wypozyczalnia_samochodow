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

    friend class Model;
};

#endif