#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
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
    while (!(cin >> choice))
    {
        cout << endl << " Podano nieprawidłowe dane! Podaj ponownie twój wybór: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void menu_kierownik();
void menu_serwisant();

void logo_operacja_kierownika() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|  .--.                               |)" << endl;
    cout << R"(| /.-. '----------.    Operacje       |)" << endl;
    cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
    cout << R"(|  '--'                               |)" << endl;
    cout << R"(|_____________________________________|)" << endl;
}

void menu() {
repeat:
    system("CLS");
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|     ____                            |)" << endl;
    cout << R"(|  __/  |_\_          Wypożyczalnia   |)" << endl;
    cout << R"(| |  _     _``-.      Samochodów v0.2 |)" << endl;
    cout << R"(| '-(_)---(_)--'                      |)" << endl;
    cout << R"(|_____________________________________|)" << endl;
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|  Menu:                              |)" << endl;
    cout << R"(|                                     |)" << endl;
    cout << R"(|  1) Rezerwacja samochodu            |)" << endl;
    cout << R"(|  2) Anulowanie rezerwacji           |)" << endl;
    cout << R"(|  3) Wydanie samochodu               |)" << endl;
    cout << R"(|  4) Zwrot samochodu                 |)" << endl;
    cout << R"(|  5) Przegląd samochodów             |)" << endl;
    cout << R"(|  6) Operacje kierownika             |)" << endl;
    cout << R"(|  7) Operacje serwisanta             |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    cout << endl << " Twój wybór: ";
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
    default:
        menu();
        break;
    }

}

void menu_kierownik() {
    logo_operacja_kierownika();

    string kod;
    cout << endl << " Podaj kod dostępu: ";
    cin >> kod;

    if (kod == "qwe123") {
    repeat:
        system("CLS");
        logo_operacja_kierownika();
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|  Menu Kierownika:                   |)" << endl;
        cout << R"(|                                     |)" << endl;
        cout << R"(|  1) Dodanie samochodu do bazy       |)" << endl;
        cout << R"(|  2) Usunięcie samochodu z bazy      |)" << endl;
        cout << R"(|  3) Usunięcie modelu z bazy         |)" << endl;
        cout << R"(|  4) Dodanie pracownika              |)" << endl;
        cout << R"(|  5) Powrót do głównego menu         |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << " Twój wybór: ";
        int choice = GetInput();

        switch (choice)
        {
        case 1:
        {
            system("CLS");
            logo_operacja_kierownika();

            cout << endl << " Menu - dodanie samochodu:" << endl << endl;

            Model::ReadAllVersion();
            cout << model.size() + 1 << ") Dodaj nowy model" << endl;
            cout << model.size() + 2 << ") Powrot do menu" << endl;

            cout << endl << " Twój wybór: ";
            int choice = GetInput();
            if (choice >= 1 && choice <= model.size()) {
                Model m = model[choice - 1];
                string nr_rej, kolor;
                int przebieg, rocznik;

                cout << " Wartosci nalezy wprowadzac bez uzycia spacji!" << endl;
                cout << " Podaj numer rejestracyjny: ";
                cin >> nr_rej;
                cout << " Podaj kolor: ";
                cin >> kolor;
                cout << " Podaj przebieg: ";
                cin >> przebieg;
                cout << " Podaj rocznik: ";
                cin >> rocznik;

                Samochod::Add(m, nr_rej, kolor, przebieg, rocznik);

                goto repeat;
            }
            else if (choice == model.size() + 1) {
                string marka, wersja, skrzynia_biegow, paliwo;
                int moc_silnika, ilosc_drzwi, ilosc_miejsc;
                float sr_spalanie, poj_bagaznika, koszt_godzina;
                bool klimatyzycja;
                cout << " Wartosci nalezy wprowadzac bez uzycia spacji!" << endl;
                cout << " Podaj marke: ";
                cin >> marka;
                cout << " Podaj wersje: ";
                cin >> wersja;
                cout << " Podaj rodzaj skrzyni biegow: ";
                cin >> skrzynia_biegow;
                cout << " Podaj rodzaj paliwa: ";
                cin >> paliwo;
                cout << " Podaj moc silnika: ";
                cin >> moc_silnika;
                cout << " Podaj ilosc drzwi: ";
                cin >> ilosc_drzwi;
                cout << " Podaj ilosc miejsc: ";
                cin >> ilosc_miejsc;
                cout << " Podaj srednie spalanie: ";
                cin >> sr_spalanie;
                cout << " Podaj pojemnosc bagaznika: ";
                cin >> poj_bagaznika;
                cout << " Podaj koszt godzinny: ";
                cin >> koszt_godzina;
                cout << " Czy posiada klimatyzacje? [0/ 1]: ";
                cin >> klimatyzycja;

                Model::Add(marka, wersja, moc_silnika, skrzynia_biegow, paliwo, sr_spalanie,
                    ilosc_drzwi, ilosc_miejsc, poj_bagaznika, klimatyzycja, koszt_godzina);
                goto repeat;
            }
            else if (choice == model.size() + 2) {
                system("CLS");
                menu_kierownik();
            }
            else {
                goto repeat;
            }
            break;
        }
        case 2:
            cout << endl << "Wybierz samochod do usuniecia: " << endl << endl;
            Samochod::ReadAll();
            cout << samochod.size() + 1 << ") Powrot do menu" << endl;
            cout << "Twoj wybor: ";
            cin >> choice;
            if (choice >= 1 && choice <= samochod.size()) {
                //RemoveObjSamochod(wybor - 1);
                goto repeat;
            }
            else if (choice == samochod.size() + 1) {
                goto repeat;
            }
            else {
                goto repeat;
            }
            break;
        case 3:
            cout << endl << "Wybierz model do usuniecia: " << endl << endl;
            Model::ReadAll();
            cout << model.size() + 1 << ") Powrot do menu" << endl;
            cout << "Twoj wybor: ";
            choice = GetInput();
            if (choice >= 1 && choice <= model.size()) {
                Model::Remove(choice - 1);
                goto repeat;
            }
            else if (choice == model.size() + 1) {
                goto repeat;
            }
            else {
                goto repeat;
            }
            break;
        case 5:
            system("CLS");
            menu();
            break;
        default:
            goto repeat;
            break;
        }
    }
    else {
        char wybor;
        cout << endl << " Kod dostępu nieprawidlowy. Chcesz sprobowac ponownie? [T/N]: ";
        cin >> wybor;

        if (wybor == 'T' || wybor == 't') {
            system("CLS");
            menu_kierownik();
        }
        else {
            system("CLS");
            menu();
        }
    }

}

void menu_serwisant() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|   ,-----.                           |)" << endl;
    cout << R"(|  / ,---. \                          |)" << endl;
    cout << R"(| / /     \ \          Operacje       |)" << endl;
    cout << R"(| \ \     / /          Serwisowe      |)" << endl;
    cout << R"(|  \ `---' /                          |)" << endl;
    cout << R"(|   `-----'                           |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    string kod;
    cout << endl << "Podaj kod dostepu: ";
    cin >> kod;

    if (kod == "qwe123") {
    repeat:
        system("CLS");
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|   ,-----.                           |)" << endl;
        cout << R"(|  / ,---. \                          |)" << endl;
        cout << R"(| / /     \ \          Operacje       |)" << endl;
        cout << R"(| \ \     / /          Serwisowe      |)" << endl;
        cout << R"(|  \ `---' /                          |)" << endl;
        cout << R"(|   `-----'                           |)" << endl;
        cout << R"(|_____________________________________|)" << endl;
        cout << R"( _____________________________________ )" << endl;
        cout << R"(|  Menu Serwisanta:                   |)" << endl;
        cout << R"(|                                     |)" << endl;
        cout << R"(|  1) Przygotowanie samochodu         |)" << endl;
        cout << R"(|  2) Raport serwisu samochodu        |)" << endl;
        cout << R"(|  3) Usunięcie modelu z bazy         |)" << endl;
        cout << R"(|  4) Powrot do glownego menu         |)" << endl;
        cout << R"(|_____________________________________|)" << endl;

        cout << endl << " Twój wybór: ";
        int choice = GetInput();

        switch (choice) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
            break;
        default:
            goto repeat;
            break;
        }
    }
    else {
        char wybor;
        cout << endl << " Kod dostępu nieprawidlowy. Chcesz sprobowac ponownie? [T/N]: ";
        cin >> wybor;

        if (wybor == 'T' || wybor == 't') {
            system("CLS");
            menu_kierownik();
        }
        else {
            system("CLS");
            menu();
        }
    }
}

int main()
{
    setlocale(LC_ALL, "pl_PL");

    Model::CreateObj();
    Samochod::CreateObj();
    Klient::CreateObj();
    Pracownik::CreateObj();
    Wypozyczenie::CreateObj();

    menu();
    Model BMW_serii_1("BMW", "118i M Sport", 140, "automatyczna", "benzyna", 5.9, 5, 5, 380, true, 230);
    Model Yaris("Toyota", "Yaris", 125, "manualna", "benzyna", 8.5, 5, 5, 255, true, 120);
    Model Vivaro("Opel", "Vivaro", 144, "automatyczna", "Diesel", 13.2, 5, 9, 1400, true, 490);
    Model Mondeo("Ford", "Mondeo", 140, "manualna", "Diesel", 6.0, 5, 5, 550, true, 150);
    
    Model::ReadAll();
    system("pause>0");
}