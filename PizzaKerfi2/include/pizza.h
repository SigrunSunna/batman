#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

class pizza
{
public:
    pizza();
    pizza(char sizep, string toppings, int _status);
    void add_number();
    string pprint();

    friend ostream& operator << (ostream& os, pizza& p);

    friend istream& operator >> (istream& is, pizza& p);


    void price ();




private:
    char _sizep;
    int  _price;
    string _toppings;
    int _nr_Pizzu;
    int _status = 0;
    char toppingsMenu[100];
    string toppingsName[100];
    int toppings_fjoldi = 7;
};

#endif // PIZZA_H
