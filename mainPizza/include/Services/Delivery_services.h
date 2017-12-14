#ifndef DELIVERY_SERVICES_H
#define DELIVERY_SERVICES_H
#include "PizzaRepository.h"
#include <stdlib.h>

using namespace std;

class Delivery_services
{
    public:
        Delivery_services();
        virtual ~Delivery_services();
        void viewOrders();
        void mark(int status);

        OrderRepository orderRepo;
        Orders order;

    protected:

    private:
};

#endif // DELIVERY_SERVICES_H
