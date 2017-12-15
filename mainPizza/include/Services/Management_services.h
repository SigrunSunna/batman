#ifndef MANAGEMENT_SERVICES_H
#define MANAGEMENT_SERVICES_H
#include "ManagementUI.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include "Orders.h"
#include <stdlib.h>


class Management_services
{
    public:
        Management_services();
        virtual ~Management_services();
        void retrieveAllOrders();
        void addToppings();
        void addSides();
        void getOrder(int ordInp);
        void sizePrice();

        ToppingRepository toppingRepo;
        OrderRepository orderRepo;
        PizzaRepository pizzaRepo;
        SidesRepository sidesRepo;

    protected:

    private:
};

#endif // MANAGEMENT_SERVICES_H
