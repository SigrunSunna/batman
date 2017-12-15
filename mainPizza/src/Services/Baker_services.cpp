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

void Baker_services::viewOrdersToBake()
{
    cout << "Orders to do: " << endl;
    orderRepo.retrieveStatus(0);
}
void Baker_services::viewReadyOrders()
{
    cout << "Orders in progress: " << endl;
    orderRepo.retrieveStatus(1);
}

void Baker_services::mark(int status)
{
    order = orderRepo.getstatus(status);
    if (order.getOrderNum() != 0)
    {
        cout << order;
        order.incrementStatus();
        orderRepo.storeOrder(order);
    }
}
