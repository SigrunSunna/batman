#ifndef BAKER_SERVICES_H
#define BAKER_SERVICES_H
#include "BakerUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>
#include "Baker_services.h"

using namespace std;

class Baker_services
{
    public:
        Baker_services();
        virtual ~Baker_services();
        void viewOrdersToBake();
        void viewReadyOrders();
        void mark(int status);

        OrderRepository orderRepo;
        Orders order;

    protected:

    private:
};

#endif // BAKER_SERVICES_H
