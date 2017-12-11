#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}

void PizzaRepository::storePizza(const Pizza& p)
{

    ofstream fout;
    fout.open("Pizza.dat", ios::binary);

    p.write(fout);

    fout.close();
}
Pizza PizzaRepository::retrievePizza()
{
    ifstream fin;
    fin.open("Pizza.dat", ios::binary);

    Pizza p;
    p.read(fin);

    fin.close();

    return p;
}
