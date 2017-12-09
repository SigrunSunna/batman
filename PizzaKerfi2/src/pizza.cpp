#include "pizza.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


pizza::pizza(void)
{
    _sizep = 'l';
    _toppings = "";
    _status = 0;
    _price = 0;
    _nr_Pizzu = -1;


}

pizza::pizza(char sizep, string toppings, int status)
{
    _sizep = sizep;
    _toppings = "";
    _status = status;
    add_number();

    toppingsMenu[0] = 'p';
    toppingsMenu[1] = 'h';
    toppingsMenu[2] = 'c';
    toppingsMenu[3] = 'a';
    toppingsMenu[4] = 'b';
    toppingsMenu[5] = 'j';
    toppingsMenu[6] = 'm';


    toppingsName[0] = "Pepperoni";
    toppingsName[1] = "Ham";
    toppingsName[2] = "Chicken";
    toppingsName[3] = "Pinapple";
    toppingsName[4] = "Bellpepper";
    toppingsName[5] = "Jalapeno";
    toppingsName[6] = "Mushroom";



    for(int i = 0; i < (int)toppings.size(); i++)
    {
        for(int j = 0; j < toppings_fjoldi; j++)
        {
            if(toppings[i] == toppingsMenu[j])
            {

                _toppings = _toppings + toppings[i];

            }

        }


    }
    price();




}


void pizza::price ()
{
    if (_sizep == 's')
    {
        _price = 900;
    }
    else if (_sizep == 'm')
    {
        _price = 1200;
    }
    else if (_sizep == 'l')
    {
        _price = 1500;
    }
    //int a = toppings.size();
    if (_toppings == "T")
    {
        return;
    }
    for(int i = 0; i < (int)_toppings.size(); i++)
    {

        switch (_sizep)
        {
        case 'l':
            _price = _price +150;
            break;
        case 'm':
            _price = _price +120;
            break;
        case 's':
            _price = _price +90;
            break;
        }

    }

}



void pizza::add_number()
{
    ofstream fout;
    ifstream fin2;
    int tala;
    string str;
    fin2.open("nr_pizzu.txt", ios::app);

    if (getline(fin2, str))
    {
        tala = stoi(str);
    }
    else
    {
        tala = 0;
    }

    _nr_Pizzu = tala;
    tala = tala +1;
    fin2.close();
    fout.open("nr_pizzu.txt");
    fout << tala;

    fin2.close();
    fout.close();

}
string pizza::pprint()
{
    string str = "";

    str = str + "Order no: " + to_string(_nr_Pizzu) + "\n";
    switch(_sizep)
    {
    case 'l':
        str = str + "Size: large" + "\n";
        break;
    case 's':
        str = str + "Size: small"  + "\n";
        break;
    case 'm':
        str = str + "Size: medium" + "\n";
        break;
    }
    for (int i = 0; i < (int)_toppings.size(); i++)
    {
        switch(_toppings[i])
        {
        case 'p':
            str = str + "Pepperoni" + "\n";
            break;
        case 'h':
            str = str + "Ham" + "\n";
            break;
        case 'm':
            str = str + "Mushroom" + "\n";
            break;
        case 'c':
            str = str + "Chicken" + "\n";
            break;
        case 'a':
            str = str + "Pinapple" + "\n";
            break;
        case 'b':
            str = str + "Bellpepper" + "\n";
            break;
        case 'j':
            str = str + "Jalapeno" + "\n";
            break;
        }

    }
    str = str + "Price: " + to_string(_price) + "\n";

    string status;

    switch(_status)
    {
    case 0: status = "Not started \n";
        break;
    case 1: status = "Started \n";
        break;
    case 2: status = "Ready \n";
    break;
    case 3: status = "Delivered \n";
    break;
    }

    str = str + status;


    str = str + "---------------" + "\n";

    return str;



}


ostream& operator << (ostream& os, pizza& p)
{

    if(p._toppings.size() == 0)
    {
        os << p._nr_Pizzu <<" " << p._sizep << " " << "T"  << " " << p._status  << endl;
    }
    else
    {
        os << p._nr_Pizzu <<" " << p._sizep << " " << p._toppings  << " " << p._status << endl;
    }


    return os;

}

istream& operator >> (istream& is, pizza& p)
{
    // write out individual members of s with an end of line between each one
    is >> p._nr_Pizzu >> p._sizep >> p._toppings >> p._status;
    p.price();
    return is;
}











