#include "BakerUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>
#include "Baker_services.h"

void BakerUI::Baker()
{
    Baker_services service;
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl;
        cout << " Hello baker, would you like to:" << endl;
        cout << " v: view orders" << endl;
        cout << " b: bake next order in line" << endl;
        cout << " q: quit " << endl;
        cout << " -> ";
        cin >> inp;
        system("CLS");
        cout << endl;
        if (inp == 'v')
        {
            service.viewOrders();
        }
        if (inp == 'b')
        {
            service.bake();
        }
    }
}
