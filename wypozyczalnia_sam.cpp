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

void logo_operacja_kierownika() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|  .--.                               |)" << endl;
    cout << R"(| /.-. '----------.    Operacje       |)" << endl;
    cout << R"(| \'-' .--"--""-"-'    Kierownika     |)" << endl;
    cout << R"(|  '--'                               |)" << endl;
    cout << R"(|_____________________________________|)" << endl;
}

void logo_glowne() {
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|     ____                            |)" << endl;
    cout << R"(|  __/  |_\_          Wypożyczalnia   |)" << endl;
    cout << R"(| |  _     _``-.      Samochodów v1.0 |)" << endl;
    cout << R"(| '-(_)---(_)--'                      |)" << endl;
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
    cout << R"(|  7) Przegląd OC                     |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    cout << endl << " Twój wybór: ";
    int choice = GetInput();

    switch (choice) {
    case 1:
    {
        {
            system("CLS");
            logo_glowne();
            cout << endl << " Rezerwacja samochodu: " << endl << endl;

            Date wod("", "", "", "", "");
            Date wdo("", "", "", "", "");
            string k, s, p;
            int wyp_przebieg, zwr_przebieg, nr_zam;

            cout << " Podaj rok wypozyczenia: ";
            cin >> wod.rok;

            cout << " Podaj miesiac wypozyczenia: ";
            cin >> wod.miesiac;

            cout << " Podaj dzien wypozyczenia: ";
            cin >> wod.dzien;

            cout << " Podaj godzine wypozyczenia: ";
            cin >> wod.godzina;

            cout << " Podaj minuty wypozyczenia: ";
            cin >> wod.minuty;

            cout << " Podaj rok zwrotu: ";
            cin >> wdo.rok;

            cout << " Podaj miesiac zwrotu: ";
            cin >> wdo.miesiac;

            cout << " Podaj dzien zwrotu: ";
            cin >> wdo.dzien;

            cout << " Podaj godzine zwrotu: ";
            cin >> wdo.godzina;

            cout << " Podaj minuty zwrotu: ";
            cin >> wdo.minuty;

            cout << " Podaj pesel klienta: ";
            cin >> k;

            if (Klient::Find(k) == -1) {
                cout << " Nie ma klienta w bazie. Prosze wprowadzic dane:" << endl;

                string imie, nazwisko, nr_tel;

                cout << " Podaj imie: ";
                cin >> imie;

                cout << " Podaj nazwisko: ";
                cin >> nazwisko;

                cout << " Podaj nr telefonu: ";
                cin >> nr_tel;

                Klient::Add(imie, nazwisko, k, nr_tel);
            }

            cout << endl << " Prosze wybrac samochod: " << endl;
            Samochod::ReadAll();

            cout << " Twoj wybor: ";
            cin >> choice;

            s = Samochod::GetNrRej(choice - 1);

            cout << " Podaj pesel pracownika: ";
            cin >> p;

            if (Pracownik::Find(p) == -1) {
                cout << "Nie ma takiego pracownika w bazie." << endl;
                cout << "Spróbuj ponownie!" << endl;

                system("pause");
                goto repeat;
            }

            nr_zam = wypozyczenie[wypozyczenie.size() - 1].GetNo() + 1;

            Wypozyczenie::Add(wod, wdo, k, s, p, 0, 0, 1, nr_zam);
            goto repeat;
        }
        break;
    }
    case 2:
    {
        {
            system("CLS");
            logo_glowne();
            cout << "Wybierz rezerwacje do anulowania: " << endl;
            int j = 0;
            vector<int> num;
            for (int i = 0; i < wypozyczenie.size(); i++) {
                if (wypozyczenie[i].GetStatus() == 1) {
                    j++;
                    cout << j << ") ";
                    wypozyczenie[i].Read();
                    num.push_back(i);
                }
            }
            if (num.size() == 0) {
                cout << "Brak zarezerwowanych samochodów." << endl;
                system("pause");
            }
            else {
                cout << "Twoj wybor: ";
                int choice = GetInput();

                if (choice >= 1 && choice <= num.size()) {
                    Wypozyczenie::Cancel(num[choice - 1]);
                }
                else {
                    goto repeat;
                }
            }
            
        }
        menu();
    }
    case 3:
    {
        system("CLS");
        logo_glowne();
        cout << "Wybierz samochod do wydania: " << endl;
        int j = 0;
        vector<int> num;
        for (int i = 0; i < wypozyczenie.size(); i++) {
            if (wypozyczenie[i].GetStatus() == 1) {
                j++;
                cout << j << ") ";
                wypozyczenie[i].Read();
                num.push_back(i);
            }
        }
        if (num.size() == 0) {
            cout << "Brak zarezerwowanych samochodów." << endl;
            cout << "Należy zarezerwować samochód." << endl;
            system("pause");
        }
        else {
            cout << "Twoj wybor: ";
            int choice = GetInput();

            int przebieg;
            cout << "Podaj aktualny przebieg samochodu: " << endl;
            cin >> przebieg;

            if (choice >= 1 && choice <= num.size()) {
                Wypozyczenie::Release(num[choice - 1], przebieg);
            }
            else {
                goto repeat;
            }
        }

    }
    menu();
    case 4:
    {
        system("CLS");
        logo_glowne();
        cout << "Wybierz zwracany samochód: " << endl;
        int j = 0;
        vector<int> num;
        for (int i = 0; i < wypozyczenie.size(); i++) {
            if (wypozyczenie[i].GetStatus() == 2) {
                j++;
                cout << j << ") ";
                wypozyczenie[i].Read();
                num.push_back(i);
            }
        }
        if (num.size() == 0) {
            cout << "Brak samochodów do zwrócenia." << endl;
            system("pause");
        }
        else {
            cout << "Twoj wybor: ";
            int choice = GetInput();

            int przebieg;
            cout << "Podaj aktualny przebieg samochodu: " << endl;
            cin >> przebieg;

            if (choice >= 1 && choice <= num.size()) {
                Wypozyczenie::Reception(num[choice - 1], przebieg);
            }
            else {
                goto repeat;
            }
        }

    }
    menu();
    case 5:
    {
        system("CLS");
        logo_glowne();
        cout << endl << " Opcja - przegladanie samochodów" << endl << endl;
        Samochod::ReadAll();
        cout << samochod.size() + 1 << ") Powrot do menu" << endl;

        cout << endl << " Twój wybór: ";
        int choice = GetInput();

        if (choice >= 1 && choice <= samochod.size()) {
            goto repeat;
        }
        else if (choice == samochod.size() + 1) {
            system("CLS");
            menu();
        }
        else {
            goto repeat;
        }
        break;
    }
    case 6:
        system("CLS");
        menu_kierownik();
        break;
    case 7:
        system("CLS");
        logo_glowne();
        Samochod::ReadAllOC();
        system("pause");
        menu();
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
        cout << R"(|  5) Zmiana terminów OC              |)" << endl;
        cout << R"(|  6) Powrót do głównego menu         |)" << endl;
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
                string nr_rej, kolor, rok, miesiac, dzien;
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

                cout << "Podaj datę ważności ubezpieczenia OC [rok]: ";
                cin >> rok;

                cout << "Podaj datę ważności ubezpieczenia OC [miesiąc]: ";
                cin >> miesiac;

                cout << "Podaj datę ważności ubezpieczenia OC [dzień]: ";
                cin >> dzien;

                Samochod::Add(m, nr_rej, kolor, przebieg, rocznik, DateOC(rok, miesiac, dzien));

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
            cout << endl << " Wybierz samochod do usuniecia: " << endl << endl;
            Samochod::ReadAll();
            cout << samochod.size() + 1 << ") Powrot do menu" << endl;

            cout << " Twoj wybor: ";
            cin >> choice;

            if (choice >= 1 && choice <= samochod.size()) {
                Samochod::Remove(choice - 1);
                goto repeat;
            }
            else if (choice == samochod.size() + 1) {
                system("CLS");
                menu_kierownik();
            }
            else {
                goto repeat;
            }
            break;
        case 3:
            cout << endl << " Wybierz model do usuniecia: " << endl << endl;
            Model::ReadAll();
            cout << model.size() + 1 << ") Powrot do menu" << endl;

            cout << " Twoj wybor: ";
            choice = GetInput();

            if (choice >= 1 && choice <= model.size()) {
                Model::Remove(choice - 1);
                goto repeat;
            }
            else if (choice == model.size() + 1) {
                system("CLS");
                menu_kierownik();
            }
            else {
                goto repeat;
            }
            break;
        case 4:
        {
            cout << endl << " Dodanie pracownika do bazy:" << endl;

            string imie, nazwisko, pesel, nr_tel, stanowisko;

            cout << " Podaj imie: ";
            cin >> imie;

            cout << " Podaj nazwisko: ";
            cin >> nazwisko;

            cout << " Podaj pesel: ";
            cin >> pesel;

            cout << " Podaj numer telefonu: ";
            cin >> nr_tel;

            cout << " Podaj stanowisko: ";
            cin >> stanowisko;

            Pracownik::Add(imie, nazwisko, pesel, nr_tel, stanowisko); }
        goto repeat;
        break;
        case 5:
            {
                cout << "Aktualizacja OC - wybierz samochód:" << endl;
                Samochod::ReadAll();

                int choice = GetInput();
                string rok, miesiac, dzien;

                if (choice >= 1 && choice <= samochod.size()) {
                    
                    cout << "Podaj rok: ";
                    cin >> rok;

                    cout << "Podaj miesiac: ";
                    cin >> miesiac;

                    cout << "Podaj dzień: ";
                    cin >> dzien;

                    Samochod::ChangeOC(choice - 1, rok, miesiac, dzien);
                    goto repeat;
                }
                else {
                    goto repeat;
                }
            }
            goto repeat;
        case 6:
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

int main()
{
    setlocale(LC_ALL, "pl_PL");

    Model::CreateObj();
    Samochod::CreateObj();
    Klient::CreateObj();
    Pracownik::CreateObj();
    Wypozyczenie::CreateObj();

    menu();
}