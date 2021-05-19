#include <iostream>
using namespace std;

void menu_kierownik();
void menu_serwisant();

void menu() {
    
repeat:
    system("CLS");
    cout << R"( _____________________________________ )" << endl;
    cout << R"(|     ____                            |)" << endl;
    cout << R"(|  __/  |_\_          Wypozyczalnia   |)" << endl;
    cout << R"(| |  _     _``-.      Samochodow v0.0 |)" << endl;
    cout << R"(| '-(_)---(_)--'                      |)" << endl;
    cout << R"(|_____________________________________|)" << endl;

    cout << "Menu:" << endl;
    cout << "1) Rezerwacja samochodu" << endl;
    cout << "2) Anulowanie rezerwacji" << endl;
    cout << "3) Wydanie samochodu" << endl;
    cout << "4) Zwrot samochodu" << endl;
    cout << "5) Przeglad samochodow" << endl;
    cout << "6) Operacje kierownika" << endl;
    cout << "7) Operacje serwisanta" << endl;

    int wybor;
    cout << "Twoj wybor: ";
    cin >> wybor;

    switch (wybor) {
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
        goto repeat;
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
    cout << endl << "Podaj kod dostepu: ";
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
        cout << "2) Usuniecie samochodu z bazy" << endl;
        cout << "3) Powrot do glownego menu" << endl;

        int wybor;
        cout << "Twoj wybor: ";
        cin >> wybor;
        
        switch (wybor) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            menu();
            break;
        default:
            goto repeat;
            break;
        }

    }
    else {
        char wybor;
        cout << "Kod nieprawidlowy. Chcesz sprobowac ponownie? [T/ N]: ";
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

        cout << endl << "Menu:" << endl;
        cout << "1) Potwierdzenie gotowosci samochodu" << endl;
        cout << "2) Raport serwisu samochodu" << endl;
        cout << "3) Raport kontroli samochodu" << endl;
        cout << "4) Powrot do glownego menu" << endl;

        int wybor;
        cout << "Twoj wybor: ";
        cin >> wybor;

        switch (wybor) {
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
        cout << "Kod nieprawidlowy. Chcesz sprobowac ponownie? [T/ N]: ";
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
    menu();
}