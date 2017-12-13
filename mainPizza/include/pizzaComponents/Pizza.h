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
        Pizza(int size);
        virtual ~Pizza();
        void addTopping(Toppings topping);
        void basePrice(int sizeofPizza);

        void write(ofstream& fout) const;
        void read(ifstream& fin);
        double getPrice ();

        friend ostream& operator << (ostream& out, const Pizza& p);
        friend istream& operator >> (istream& in, Pizza& p);

    private:
        vector<Toppings> toppings;
        double _price;
        int _pizza_Size;   // Can be 1, 2 or 3 for small medium and large.

};

#endif // PIZZA_H
