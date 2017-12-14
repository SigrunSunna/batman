#ifndef SALES_SERVICES_H
#define SALES_SERVICES_H
#include "SalesUI.h"
#include "Toppings.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include <stdlib.h>
#include "InvalidCharInput.h"

using namespace std;

class Sales_services
{
    public:
        Sales_services();
        virtual ~Sales_services();
        void sizeChoice(int& psize);
        void toppingChoice(Pizza& p);
        void storeOrder(Orders& order);
        void retrieveAllOrders();

        ToppingRepository toppingRepo;
        OrderRepository orderRepo;


    protected:

    private:
};

#endif // SALES_SERVICES_H
