#include "BakerUI.h"
#include "PizzaRepository.h"
#include <stdlib.h>
#include "Baker_services.h"
#include "InvalidCharInput.h"

void BakerUI::Baker()
{
    Baker_services service;
    char input = '\0';
    while(input != 'q')
    {
        cout << endl;
        cout << " Hello baker, would you like to:" << endl;
        cout << " v: view orders" << endl;
        cout << " b: orders to be baked" << endl;
        cout << " m: orders in progress" << endl;
        cout << " q: quit " << endl;
        cout << " -> ";
        try{
            cin >> input;
            system("CLS");
            cout << endl;
            if (input == 'v')
            {
                service.viewReadyOrders();
                service.viewOrdersToBake();
            }
            if (input == 'b')
            {
                char inp = '\0';
                while(inp != 'b'){
                    service.mark(0);
                    cout << endl;
                    cout << " b: bake next order in line" << endl;
                    cin >> inp;
                }
            }
            if (input == 'm')
            {
                ///marks order as ready
                char inp = '\0';
                while(inp != 'm'){
                    service.mark(1);
                    cout << endl;
                    cout << " m: mark next order as ready" << endl;
                    cin >> inp;
                }
            }
            if(input != 'v' && input != 'b' && input != 'm' && input != 'q') throw InvalidCharInput();
        }
        catch(InvalidCharInput)
        {
              cout << " Wrong input!, please choose again." << endl;
        }
    }
}
