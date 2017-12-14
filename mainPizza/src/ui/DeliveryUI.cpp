#include "DeliveryUI.h"
#include "PizzaRepository.h"

void DeliveryUI::Delivery()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello Delivery Person, would you like to:" << endl;
        cout << "v: view orders, m: mark as ready, p: mark pizza as paid q: quit?: ";
        cin >> inp;
             if (inp == 'v')
        {

            PizzaRepository pizzaRepo;
            pizzaRepo.retrieveALL();
        }

         if (inp == 'm')
        {
            DeliveryUI cashier;

            OrderRepository orderRepo;
            Orders order;
            order = orderRepo.getstatus(1);
            if (order.getOrderNum() != 0)
            {
                cashier.changeStatus(order);
            }

        }

          if (inp == 'p')
        {
            DeliveryUI cashier;

            OrderRepository orderRepo;
            Orders order;
            order = orderRepo.getstatus(2);
            if (order.getOrderNum() != 0)
            {
                cashier.changeStatus(order);
            }

        }

    }
}



void DeliveryUI::changeStatus(Orders order)
{
    cout << order;

    order.incrementStatus();
    OrderRepository orderReady;
    orderReady.storeOrder(order);
}


