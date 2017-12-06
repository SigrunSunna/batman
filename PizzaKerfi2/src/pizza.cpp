#include "pizza.h"
#include <iostream>
#include <string>
#include <fstream>


pizza::pizza(char sizep, string toppings, int status)
{
    _sizep = sizep;
    _toppings = "";
    _status = status;
    add_number();
    int toppings_fjoldi = 7;

    char toppingsMenu[100];
    string toppingsName[100];


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





    if (sizep == 's')
    {
        _price = 900;
    }
    else if (sizep == 'm')
    {
        _price = 1200;
    }
    else if (sizep == 'l')
    {
        _price = 1500;
    }
    //int a = toppings.size();
    for(int i = 0; i < (int)toppings.size(); i++)
    {
        for(int j = 0; j < toppings_fjoldi; j++)
        {
            if(toppings[i] == toppingsMenu[j])
            {

                _toppings = _toppings + toppings[i];
                switch (sizep)
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



