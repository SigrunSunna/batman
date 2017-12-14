#include "Pizza.h"
#include <stddef.h>
#include <fstream>
#include <cstdlib>



Pizza::Pizza()
{
    // Base price of pizza
    _pizza_Size = 0;
    _price = 0;
}

Pizza::Pizza(int size)
{
    basePrice(size);
}

void Pizza::basePrice(int sizeofPizza)
{

    _pizza_Size = sizeofPizza;

    int smallPrice = 0;
    int mediumPrice = 0;
    int largePrice = 0;

    ifstream fin;
    fin.open("pizzaPrice.dat", ios::binary);
    if(!fin.is_open())
    {
        cout << " Error no prices found please set prices in management" << endl;
        exit(EXIT_FAILURE);
    }
    fin.read((char*)(&smallPrice), sizeof(int));
    fin.read((char*)(&mediumPrice), sizeof(int));
    fin.read((char*)(&largePrice), sizeof(int));
    fin.close();

    switch(sizeofPizza)
    {
    case 1:
        _price = smallPrice;
        break;
    case 2:
        _price = mediumPrice;
        break;
    case 3:
        _price = largePrice;
        break;
    }

}


Pizza::~Pizza() {}

void Pizza::addTopping(Toppings topping)
{
    toppings.push_back(topping);
    _price += topping.getPrice();
}

void Pizza::write(ofstream& fout) const
{
    int tCount = toppings.size();
    fout.write((char*)(&tCount), sizeof(int));
    fout.write((char*)(&_pizza_Size), sizeof(int));

    for(int i = 0; i < tCount; i++)
    {
        toppings[i].write(fout);
    }


}
void Pizza::read(ifstream& fin)
{
    int tCount;
    fin.read((char*)(&tCount), sizeof(int));
    fin.read((char*)(&_pizza_Size), sizeof(int));
    basePrice(_pizza_Size);


    Toppings topping;
    for(int i = 0; i < tCount; i++)
    {
        topping.read(fin);
        addTopping(topping);
    }

}

double Pizza::getPrice ()
{
    return _price;
}







istream& operator >> (istream& in, Pizza& p)
{
    int toppingCount;
    in >> toppingCount;

    Toppings topping;
    for(unsigned int i = 0; i < p.toppings.size(); i++)
    {
        in >> topping;
        p.addTopping(topping);
    }
    return in;
}

ostream& operator << (ostream& out, const Pizza& p)
{
    out << " Size of pizza: ";
    switch(p._pizza_Size)
    {
    case 1:
        out << " small" << endl;
        break;
    case 2:
        out << " medium" << endl;
        break;
    case 3:
        out << " large" << endl;
        break;
    }
    out << " Pizza with toppings: " << endl;
    for(unsigned int i = 0; i < p.toppings.size(); i++)
    {
        out << p.toppings[i] << endl;
    }
    out << " Total price of the pizza: " << p._price;
    return out;
}


