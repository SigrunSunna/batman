#include "Baker_services.h"

using namespace std;

Baker_services::Baker_services()
{
    //ctor
}

Baker_services::~Baker_services()
{
    //dtor
}

void Baker_services::viewOrders()
{
    OrderRepository orderRepo;
    orderRepo.retrieveStatus(0);
}

void Baker_services::bake()
{
    order = orderRepo.getstatus(0);
    if (order.getOrderNum() != 0)
    {
        cout << order;

        order.incrementStatus();
        orderRepo.storeOrder(order);
    }
}
