#include "DeliveryUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>
#include "Delivery_services.h"
#include "InvalidCharInput.h"

void DeliveryUI::Delivery()
{
    Delivery_services service;
    char input = '\0';
    while(input != 'q')
    {
        cout << endl;
        cout << " Hello Delivery Person, would you like to:" << endl;
        cout << " v: view orders" << endl;
        cout << " p: payment" << endl;
        cout << " q: quit" << endl;
        cout << " -> ";
        try{
            cin >> input;
            system("CLS");
            if (input == 'v')
            {
                service.viewOrders();
            }

            if (input == 'p')
            {
                ///marks order as paid
                char inp = '\0';
                while(inp != 'p'){
                    service.mark(2);
                    cout << endl;
                    cout << " p: mark next order as paid" << endl;
                    cin >> inp;
                }
            }
            if(input != 'v' && input != 'p' && input != 'q') throw InvalidCharInput();
        }
        catch(InvalidCharInput e)
        {
            cout << " Wrong input!, please choose again." << endl;
        }
    }
}



