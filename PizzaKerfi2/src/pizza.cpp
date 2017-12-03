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

    out << baka._toppings << endl;

        out << "Prize: " << baka._price << endl;




    return out;
}


istream& operator >> (istream& in, pizza& pontun)
{
    /*if (pontun._sizep == 'l')
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
    }*/
    in /*>> pontun._sizep >> pontun._toppings*/ >> pontun._price;
    return in;
}



