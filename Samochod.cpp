#include "Samochod.hpp"
#include <iostream>
#include <fstream>

#include "vectors.hpp"

bool Samochod::IsModel(int index) {
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