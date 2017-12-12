#include "PizzaRepository.h"
#include "OrderRepository.h"

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
    cout << "Er ad bua til skra" << endl;
    fout.open("Pizza.dat", ios::binary | ios::app);

    p.write(fout);

    fout.close();
}
Orders PizzaRepository::retrievePizza()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary);

    Orders s;
    s.read(fin);

    fin.close();

    return s;
}

void PizzaRepository::retrieveALL()
{
    ifstream fin;
    fin.open("Pizza.dat", ios::binary);

    while(!fin.eof())
    {
        Orders s;
        s.read(fin);
        cout << s;
        cout << "----------------------" << endl;
    }
    fin.close();
}
