#include "Pizza.h"
#include <stddef.h>
#include <fstream>


Pizza::Pizza()
{
    _price = 1000;  // Grunnverd a pizzu
}



Pizza::~Pizza()
{
}

void Pizza::addTopping(Toppings topping)
{
    toppings.push_back(topping);
    _price += topping.getPrice();
}

void Pizza::write(ofstream& fout) const
{
    int tCount = toppings.size();
    fout.write((char*)(&tCount), sizeof(int));
    //fout.write((char*)toppings, sizeof(Toppings) * toppingCount);
    /*for(int i = 0; i < tCount; i++)
    {
        fout.write((char*)(&toppings.at(i)), sizeof(Toppings));
    }*/
    for(int i = 0; i < tCount; i++)
    {
        toppings[i].write(fout);
    }


}
void Pizza::read(ifstream& fin)
{
    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Toppings topping;
    for(int i = 0; i < tCount; i++)
    {
        topping.read(fin);
        addTopping(topping);
    }
    //initialize(topCnt);

    //fin.read((char*)toppings, sizeof(Toppings) * toppingCount);

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
    out << "Pizza with toppings: " << endl;
    //out << p.toppingCount << " ";
    for(unsigned int i = 0; i < p.toppings.size(); i++)
    {
        out << p.toppings[i] << endl;
    }
    out << "Total price of the pizza: " << p._price;
    return out;
}


