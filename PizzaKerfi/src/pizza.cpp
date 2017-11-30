#include "pizza.h"
#include <iostream>
#include <string>
#include <fstream>

pizza::pizza()
{
        _sizep = 'L';
        _price = 200;
        _toppings = "";

}

pizza::pizza(char sizep, int price, string toppings)
{
    _sizep = sizep;
    _price = price;
    _toppings = toppings;
}




ostream& operator << (ostream& out, const pizza& baka)
{

    if(baka._sizep == 's')
    {
    out << "Small pizza " << endl;
    }
    if(baka._sizep == 'm')
    {
         out << "Medium pizza " << endl;
    }
    if(baka._sizep == 'l')
    {
         out << "Large pizza " << endl;
    }
    for (int i = 0; i < baka._toppings.size(); i++)
    {
        switch(baka._toppings[i])
        {
        case 'p': cout << "Pepperoni" << endl;
        break;
        case 'h': cout << "Ham" << endl;
        break;
        case 'm': cout << "Mushroom" << endl;
        break;
        case 'c': cout << "Chicken" << endl;
        break;
        case 'a': cout << "Pinapple" << endl;
        break;
        case 'b': cout << "Bellpepper" << endl;
        break;
        case 'j': cout << "Jalapeno" << endl;
        break;
       // case 1: baka._price = baka._price +150;
        }
    }

        out << "Prize: " << baka._price << endl;




    return out;
}


istream& operator >> (istream& in, pizza& pontun)
{
    if (pontun._sizep == 'l')
    {
        pontun._price = 1500;
    }

    if (pontun._sizep == 'm')
    {
        pontun._price = 1200;
    }

    if (pontun._sizep == 's')
    {
        pontun._price = 900;
    }
    in >> pontun._sizep >> pontun._toppings >> pontun._price;
    return in;
}
