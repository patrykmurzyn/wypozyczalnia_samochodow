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

int GetInput() {
    int choice;
    cin >> choice;
    return choice;
}

void menu_kierownik();
void menu_serwisant();

void menu() {
repeat:
    system("CLS");
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|     ____                            |)" << endl;
    cout << R"(|  __/  |_\_          Wypożyczalnia   |)" << endl;
    cout << R"(| |  _     _``-.      Samochodów v0.2 |)" << endl;
    cout << R"(| '-(_)---(_)--'                      |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    cout << endl << "Menu:" << endl;
    cout << "1) Rezerwacja samochodu" << endl;
    cout << "2) Anulowanie rezerwacji" << endl;
    cout << "3) Wydanie samochodu" << endl;
    cout << "4) Zwrot samochodu" << endl;
    cout << "5) Przegląd samochodów" << endl;
    cout << "6) Operacje kierownika" << endl;
    cout << "7) Operacje serwisanta" << endl;

    cout << "Twój wybór: ";
    int choice = GetInput();

    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        system("CLS");
        menu_kierownik();
        break;
    case 7:
        system("CLS");
        menu_serwisant();
        break;
    }

}

void menu_kierownik() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|  .--.                               |)" << endl;
    cout << R"(| /.-. '----------.    Operacje       |)" << endl;
    cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
    cout << R"(|  '--'                               |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    string kod;
    cout << endl << "Podaj kod dostępu: ";
    cin >> kod;

    if (kod == "qwe123") {
    repeat:
        system("CLS");
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|  .--.                               |)" << endl;
        cout << R"(| /.-. '----------.    Operacje       |)" << endl;
        cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
        cout << R"(|  '--'                               |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << "Menu:" << endl;
        cout << "1) Dodanie samochodu do bazy" << endl;
        cout << "2) Usunięcie samochodu z bazy" << endl;
        cout << "3) Usunięcie modelu z bazy" << endl;
        cout << "4) Dodanie pracownika" << endl;
        cout << "5) Powrót do głównego menu" << endl;

        
        cout << "Twój wybór: ";
        int choice = GetInput();

        switch (choice)
        {
        case 1:
        {
        system("CLS");
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|  .--.                               |)" << endl;
        cout << R"(| /.-. '----------.    Operacje       |)" << endl;
        cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
        cout << R"(|  '--'                               |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << "Dodanie samochodu do bazy:" << endl;
        cout << "Wybierz model:" << endl;

        Model::ReadAllVersion();

        cout << model.size() + 1 << ") Dodaj nowy model" << endl;
        cout << model.size() + 2 << ") Powrót do menu" << endl;

        cout << "Twój wybór: ";
        int choice = GetInput();

        }
        break;
        default:
            break;
        }
    }
}

void menu_serwisant() {

}

int main()
{
    setlocale(LC_ALL, "pl_PL");

    Model::CreateObj();
    Samochod::CreateObj();
    Klient::CreateObj();
    Pracownik::CreateObj();
    Wypozyczenie::CreateObj();

    //Model::Add("1", "1", 1, "1", "1", 1, 1, 1, 1, 1, 1);

    Model::ReadAll();

    
    
    //menu();
}
