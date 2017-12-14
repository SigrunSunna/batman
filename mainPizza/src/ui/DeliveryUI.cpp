#include "DeliveryUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>

void DeliveryUI::Delivery()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl << " Hello Delivery Person, would you like to:" << endl;
        cout << " v: view orders" << endl;
        cout << " m: mark as ready" << endl;
        cout << " p: mark pizza as paid" << endl;
        cout << " q: quit";
        cout << " -> ";
        cin >> inp;
        system("CLS");
             if (inp == 'v')
        {

            OrderRepository orderRepo;
            orderRepo.retrieveStatus(1);
            orderRepo.retrieveStatus(2);
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


