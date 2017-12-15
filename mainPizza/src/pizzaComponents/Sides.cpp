#include "Sides.h"
#include <string.h>
#include <fstream>

Sides::Sides()
{
    //ctor
}

Sides::~Sides()
{
    //dtor
}
Sides::Sides(string name, double price)
{
    _name = name;
    _price = price;
}


void Sides::write(ofstream& fout) const
{
    int stringLength = _name.length() + 1;

    fout.write((char*)(&stringLength), sizeof(int));
    fout.write(_name.c_str(), stringLength);

    fout.write((char*)(&_price), sizeof(double));
}

void Sides::read(ifstream& fin)
{
    int stringLength;

    fin.read((char*)(&stringLength), sizeof(int));
    char *str = new char[stringLength];

    fin.read(str, stringLength);

    _name = str;

    fin.read((char*)(&_price), sizeof(double));

    delete[] str;
}


double Sides::getPrice ()
{
    return _price;
}




istream& operator >> (istream& in, Sides& sid)
{
    cout << " Name:  ";
    in >> ws;
    getline(in, sid._name);

    cout << " Price: ";
    in >> sid._price;

    return in;
}

ostream& operator << (ostream& out, const Sides& sid)
{
    int stringLength = sid._name.length() + 1;
    out << " Sides " << sid._name;
    if(stringLength >= 10)
    {
        out << "\tPrice: "<< sid._price;
    }
    else
    {
        out << "\t\tPrice: "<< sid._price;
    }

    return out;
}


