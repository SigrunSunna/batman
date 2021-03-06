#include "Toppings.h"
#include <string.h>
#include <fstream>

Toppings::Toppings()
{
    //ctor
}
Toppings::~Toppings()
{
    //dtor
}
Toppings::Toppings(string name, double price)
{
    _name = name;
    _price = price;
}


void Toppings::write(ofstream& fout) const
{
    int stringLength = _name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(_name.c_str(), stringLength);

    fout.write((char*)(&_price), sizeof(double));
}

void Toppings::read(ifstream& fin)
{
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    _name = str;

    fin.read((char*)(&_price), sizeof(double));

    delete[] str;
}


double Toppings::getPrice ()
{
    return _price;
}




istream& operator >> (istream& in, Toppings& top)
{
    cout << " Name:  ";
    in >> ws;
    getline(in, top._name);

    cout << " Price: ";
    in >> top._price;

    return in;
}

ostream& operator << (ostream& out, const Toppings& top)
{
    int stringLength = top._name.length() + 1;
    out << " Topping: " << top._name;
    if(stringLength >= 10)
    {
        out << "\tPrice: "<< top._price;
    }
    else out << "\t\tPrice: "<< top._price;
    return out;
}
