#include "Orders.h"
#include <fstream>

using namespace std;

Orders::Orders()
{
    _price = 0;

    _status = 0;

}

Orders::~Orders()
{
    //dtor
}

int Orders::getStatus()
{
    return _status;
}



int Orders::getOrderNum()
        {
            return _orderNum;
        }


void Orders::add_number()
{
    ofstream fout;
    ifstream fin2;
    int tala;
    string str;
    fin2.open("OrderNo.txt", ios::app);

    if (getline(fin2, str))
    {
        tala = stoi(str);
    }
    else
    {
        tala = 1000;
    }

    _orderNum = tala;
    tala++;
    fin2.close();
    fout.open("OrderNo.txt");
    fout << tala;

    fout.close();

}

void Orders::incrementStatus()
{
    _status = _status +1;
}




void Orders::addPizza(Pizza p)
{
    pizzas.push_back(p);
    _price += p.getPrice();

}

void Orders::write(ofstream& fout) const
{
    fout.write((char*)(&_orderNum), sizeof(int));
    int pCount = pizzas.size();
    fout.write((char*)(&pCount), sizeof(int));
    fout.write((char*)(&_status), sizeof(int));

    for(int i = 0; i < pCount; i++)
    {
        pizzas[i].write(fout);
    }
}
void Orders::read(ifstream& fin)
{
    fin.read((char*)(&_orderNum), sizeof(int));
    int pCount;
    fin.read((char*)(&pCount), sizeof(int));
    fin.read((char*)(&_status), sizeof(int));

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
    out << "Order No. " << o._orderNum <<endl;
    //out << p.toppingCount << " ";
    for(unsigned int i = 0; i < o.pizzas.size(); i++)
    {
        out << o.pizzas[i] <<  endl;
    }



    out << "Status: " << o._status << endl;


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
