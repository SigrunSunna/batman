#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include "Prices.h"

using namespace std;

class Pizza
{
    private:
        char _size;
        string _toppings;
        int _price;
        bool _verbose;

    public:
        Pizza();
        void set_price(int price);
        //void set_verbose(bool v);
        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

};

#endif // PIZZA_H
