#ifndef ORDERS_H
#define ORDERS_H
#include "Pizza.h"
#include <vector>
#include <iostream>

using namespace std;

class Orders
{
    public:
        Orders();
        virtual ~Orders();
        void addPizza(Pizza p);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Orders& o);
        friend istream& operator >> (istream& in, Orders& o);

    private:
        int _orderNum;
        vector<Pizza> pizzas;
};

#endif // ORDERS_H
