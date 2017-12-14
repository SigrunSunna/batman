#include "ManagementUI.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include "Orders.h"
#include <stdlib.h>
#include "Management_services.h"

void ManagementUI::Management()
{
    Management_services service;
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl;
        cout << " Hello Manager, would you like to:" << endl;
        cout << " t: add toppings" << endl;
        cout << " v: view orders" << endl;
        cout << " c: change pizza prices" << endl;
        cout << " r: retrieve a specific order." << endl;
        cout << " q: quit " << endl;
        cout << " -> ";
        cin >> inp;
        system("CLS");
        if (inp == 'v')
        {
            service.retrieveAllOrders();
        }
        if(inp == 't')
        {
            cout << endl;
            cout << " These are the current toppings in the system: " << endl;
            service.addToppings();

        }
        if(inp == 'c')
        {
            service.sizePrice();
        }
        if(inp == 'r')
        {
            int ordInp;

            cout << " What order would you like to pull?" << endl;
            cout << " ->";
            cin >> ordInp;
            system("CLS");

            service.getOrder(ordInp);


        }
    }
}
