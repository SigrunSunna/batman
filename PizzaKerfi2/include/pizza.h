#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>


using namespace std;

class pizza
{
    public:
    pizza();
    pizza(char sizep, string toppings, int _status);
    //void create_pizza ();
    friend ostream& operator << (ostream& out, const pizza& baka);
    friend istream& operator >> (istream& in, pizza& pontun);
    void add_number();
    string list_pizza();
    string pprint();

    private:
        char _sizep;
        int  _price;
        string _toppings;
        int _nr_Pizzu;
        int _status = 0;
};

#endif // PIZZA_H
