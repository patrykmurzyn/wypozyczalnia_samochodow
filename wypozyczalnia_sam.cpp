#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "vectors.hpp"
#include "Model.hpp"
#include "Samochod.hpp"
#include "Osoba.hpp"
#include "Klient.hpp"
#include "Pracownik.hpp"
#include "Wypozyczenie.hpp"

using namespace std;

int main()
{
    Model::CreateObjs();
    Model::ReadAll();
}
