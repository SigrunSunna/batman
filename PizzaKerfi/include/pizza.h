#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class pizza
{
    public:
    pizza();
    pizza(char sizep, int price, string toppings);
    friend ostream& operator << (ostream& out, const pizza& baka);
    friend istream& operator >> (istream& in, pizza& pontun);

    private:
        char _sizep;
        int  _price;
        string _toppings;
};

#endif // PIZZA_H
