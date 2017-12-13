#ifndef ORDERS_H
#define ORDERS_H
#include "Pizza.h"
#include <vector>
#include <iostream>


using namespace std;

class Orders
{
    public:
        int _orderNum;
        Orders();
        virtual ~Orders();
        void addPizza(Pizza p);
        void incrementStatus();

        int getOrderNum();



        void add_number();
        int getStatus();

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Orders& o);
        friend istream& operator >> (istream& in, Orders& o);

    private:

        vector<Pizza> pizzas;
        double _price;

        int _status;

};

#endif // ORDERS_H
