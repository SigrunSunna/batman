#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>
#include <vector>

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();
        void addTopping(Toppings topping);

        void write(ofstream& fout) const;
        void read(ifstream& fin);
        double getPrice ();

        friend ostream& operator << (ostream& out, const Pizza& p);
        friend istream& operator >> (istream& in, Pizza& p);

    private:
        vector<Toppings> toppings;
        double _price;

};

#endif // PIZZA_H
