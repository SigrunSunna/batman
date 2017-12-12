#include "Orders.h"
#include <fstream>

using namespace std;

Orders::Orders()
{
    _price = 0;
}

Orders::~Orders()
{
    //dtor
}

void Orders::addPizza(Pizza p)
{
    pizzas.push_back(p);
    _price += p.getPrice();

}

void Orders::write(ofstream& fout) const
{
    int pCount = pizzas.size();
    fout.write((char*)(&pCount), sizeof(int));

    for(int i = 0; i < pCount; i++)
    {
        pizzas[i].write(fout);
    }
}
void Orders::read(ifstream& fin)
{
    int pCount;
    fin.read((char*)(&pCount), sizeof(int));

    for(int i = 0; i < pCount; i++)
    {
        Pizza pizza;
        if(fin.eof())
        {
            break;
        }
        pizza.read(fin);
        addPizza(pizza);
    }
}

ostream& operator << (ostream& out, const Orders& o)
{
    out << "Order consists of: " << endl;
    //out << p.toppingCount << " ";
    for(unsigned int i = 0; i < o.pizzas.size(); i++)
    {
        out << o.pizzas[i] <<  endl;
    }

    out << endl << "Total price of order: " << o._price << endl;

    return out;
}
istream& operator >> (istream& in, Orders& o)
{
    int pizzaCount;
    in >> pizzaCount;

    Pizza pizza;
    for(unsigned int i = 0; i < o.pizzas.size(); i++)
    {
        in >> pizza;
        o.addPizza(pizza);
    }
    return in;
}
