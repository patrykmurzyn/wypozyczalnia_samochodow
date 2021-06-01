#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "vectors.hpp"
#include "Model.hpp"
#include "Samochod.hpp"

using namespace std;

int main()
{
    Model::CreateObjs();
    Model::ReadAll();
}
