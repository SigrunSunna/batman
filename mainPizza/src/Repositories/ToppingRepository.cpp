#include "ToppingRepository.h"
#include <fstream>

using namespace std;

ToppingRepository::ToppingRepository()
{
    //ctor
}

ToppingRepository::~ToppingRepository()
{
    //dtor
}


void ToppingRepository::storeAllToppings(const vector<Toppings> &toppings)
{
    ofstream fout;
    fout.open("toppings.dat", ios::binary);

    int toppingCount = toppings.size();

    fout.write((char*)(&toppingCount), sizeof(int));

    for(int i = 0; i < toppingCount; i++)
    {
        toppings[i].write(fout);
    }

    fout.close();
}


vector<Toppings> ToppingRepository::retrieveAllToppings()
{
    vector<Toppings> toppings;
    Toppings topping;

    ifstream fin;
    fin.open("toppings.dat", ios::binary);

    if(fin.is_open())
    {
        int toppingCount;
        fin.read((char*)(&toppingCount), sizeof(int));

        for(int i = 0; i < toppingCount; i++)
        {
            topping.read(fin);
            toppings.push_back(topping);
        }

        fin.close();
    }

    return toppings;
}
