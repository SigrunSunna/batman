#include "Delivery_services.h"

Delivery_services::Delivery_services()
{
    //ctor
}

Delivery_services::~Delivery_services()
{
    //dtor
}

void Delivery_services::viewOrders()
{
    orderRepo.retrieveStatus(1);
    orderRepo.retrieveStatus(2);
}

void Delivery_services::mark(int status)
{
    order = orderRepo.getstatus(status);
    if (order.getOrderNum() != 0)
    {
        cout << order;
        order.incrementStatus();
        orderRepo.storeOrder(order);
    }
}
