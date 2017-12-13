#ifndef ORDERREPOSITORY_H
#define ORDERREPOSITORY_H
#include "Orders.h"
#include <fstream>

using namespace std;

class OrderRepository
{
    public:
        OrderRepository();
        virtual ~OrderRepository();
        void retrieveALL();

        Orders getstatusNull();


        void storeOrder(const Orders& o);
        Orders retrieveOrder();

    private:
};

#endif // ORDERREPOSITORY_H
