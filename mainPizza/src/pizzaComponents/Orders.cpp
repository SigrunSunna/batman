#include "Orders.h"
#include <fstream>
#include <string>

using namespace std;

Orders::Orders()
{
    _price = 0;
    _status = 0;
    _orderNum = 0;
}

Orders::~Orders()
{
    //dtor
}

int Orders::getStatus()
{
    return _status;
}

/*Orders Orders::fetchOrder(int orderNO)
{
    string filename = "Orders\\";

    filename = filename + to_string(orderNO);

    ifstream fin;
    fin.open(filename, ios::binary);
    if(!fin.is_open())
    {
        cout << " Order not found!" << endl;
        Orders defaulto;
        return defaulto;
    }
    Orders s;
    s.read(fin);
    fin.close();

    return s;
}*/



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


void Orders::addSides(Sides s)
{
    sides.push_back(s);
    _price += s.getPrice();

}


void Orders::write(ofstream& fout) const
{
    fout.write((char*)(&_orderNum), sizeof(int));
    int pCount = pizzas.size();
    int sCount = sides.size();
    fout.write((char*)(&pCount), sizeof(int));
    fout.write((char*)(&sCount), sizeof(int));
    fout.write((char*)(&_status), sizeof(int));

    for(int i = 0; i < pCount; i++)
    {
        pizzas[i].write(fout);
    }
    for(int i = 0; i < sCount; i++)
    {
        sides[i].write(fout);
    }
}
void Orders::read(ifstream& fin)
{
    fin.read((char*)(&_orderNum), sizeof(int));
    int pCount;
    fin.read((char*)(&pCount), sizeof(int));
    int sCount;
    fin.read((char*)(&sCount), sizeof(int));
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
    for(int i = 0; i < sCount; i++)
    {
        Sides side;
        if(fin.eof())
        {
            break;
        }
        side.read(fin);
        addSides(side);
    }
}

ostream& operator << (ostream& out, const Orders& o)
{
    out << endl << "-----------------------" << endl;
    out << " Order No. " << o._orderNum << endl << endl;
    //out << p.toppingCount << " ";
    for(unsigned int i = 0; i < o.pizzas.size(); i++)
    {
        out << o.pizzas[i] <<  endl << endl;
    }

     for(unsigned int i = 0; i < o.sides.size(); i++)
    {
        out << o.sides[i] <<  endl;
    }


    out << endl << " Total price of order: " << o._price << endl;
    out << " Status: " << endl;

    switch(o._status)
    {
    case 0:
        out << "\tWaiting for baker..." << endl;
        break;
    case 1:
        out << "\tOrder in progress..." << endl;
        break;
    case 2:
        out << "\tOrder ready." << endl;
        break;
    case 3:
        out << "\tOrder paid and recieved." << endl;
        break;
    }




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
    Sides side;
    for(unsigned int i = 0; i < o.sides.size()-1; i++)
    {
        in >> side;
        o.addSides(side);
    }

    return in;
}
