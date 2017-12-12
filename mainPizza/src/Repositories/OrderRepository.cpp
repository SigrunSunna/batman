#include "OrderRepository.h"

OrderRepository::OrderRepository()
{
    //ctor
}

OrderRepository::~OrderRepository()
{
    //dtor
}

void OrderRepository::storeOrder(const Orders& o)
{
    ofstream fout;
    fout.open("Orders.dat", ios::binary | ios::app);

    o.write(fout);

    fout.close();
}
Orders OrderRepository::retrieveOrder()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary);

    Orders s;
    s.read(fin);

    fin.close();

    return s;
}
