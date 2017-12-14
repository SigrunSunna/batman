#include "DeliveryUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>
#include "Delivery_services.h"

void DeliveryUI::Delivery()
{
    Delivery_services service;
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl;
        cout << " Hello Delivery Person, would you like to:" << endl;
        cout << " v: view orders" << endl;
        cout << " m: mark as ready" << endl;
        cout << " p: mark pizza as paid" << endl;
        cout << " q: quit" << endl;
        cout << " -> ";
        cin >> inp;
        system("CLS");
        if (inp == 'v')
        {
            service.viewOrders();
        }

        if (inp == 'm')
        {
            ///marks order as ready
            service.mark(1);
        }

        if (inp == 'p')
        {
            ///marks order as paid
            service.mark(2);
        }

    }
}



