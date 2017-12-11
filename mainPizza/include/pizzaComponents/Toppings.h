#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <iostream>
#include <string.h>

using namespace std;


class Toppings
{
    public:
        Toppings();
        Toppings(string name, double price);
        virtual ~Toppings();

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Toppings& top);
        friend istream& operator >> (istream& in, Toppings& top);

    protected:

    private:
        string _name;
        double _price;

};

#endif // TOPPINGS_H
