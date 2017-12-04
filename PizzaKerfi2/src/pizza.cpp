#include "pizza.h"
#include <iostream>
#include <string>
#include <fstream>


pizza::pizza(char sizep, int price, string toppings)
{
    _sizep = sizep;
    _price = price;
    _toppings = toppings;
    add_number();
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

    str = str + "---------------" + "\n";

    return str;



}

string pizza::list_pizza()
{
    string str;
    str = to_string(_nr_Pizzu) + ";" + _sizep + ";" +  _toppings + ";" + "\n";
    return str;
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
    /*>> pontun._sizep >> pontun._toppings*/
    return in;
}



