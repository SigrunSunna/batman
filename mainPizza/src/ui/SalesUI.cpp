#include "SalesUI.h"
#include "Toppings.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include "SidesRepository.h"
#include <stdlib.h>
#include "InvalidCharInput.h"
#include "Sales_services.h"

using namespace std;

void SalesUI::Sales()
{
    Sales_services service;
    char input = '\0';
    while(input != 'q')
    {
        cout << endl;
        cout << " Hello salesperson, would you like to: " << endl;
        cout << " m: make order" << endl;
        cout << " r: read order" << endl;
        cout << " p: payment" << endl;
        cout << " q: quit" << endl;
        cout << " -> ";
        try {
            cin >> input;
            system("CLS");

            if(input == 'm')
            {
                int psize;
                Orders order;
                order.add_number();
                char input = 'y';
                while(input == 'y')
                {
                    service.sizeChoice(psize);
                    Pizza p(psize);
                    service.toppingChoice(p);

                    order.addPizza(p);
                    cout << endl;
                    cout << " Would you like to add another pizza?" << endl;
                    cout << " yes: y" << endl;
                    cout << " no: any other key: " << endl;
                    cout << " -> ";
                    cin >> input;
                    system("CLS");
                }
                cout << endl;
                cout << " Would you like to add other products?" << endl;
                cout << " yes: y" << endl;
                cout << " no: any other key: " << endl;
                cout << " -> ";
                cin >> input;
                system("CLS");
                while(input == 'y')
                {
                    service.sidesChoice(order);
                    cout << endl;
                    cout << " Any more products?" << endl;
                    cout << " yes: y" << endl;
                    cout << " no: any other key: " << endl;
                    cout << " -> ";
                    cin >> input;
                    system("CLS");
                }
                service.storeOrder(order);
            }
            if(input == 'r')
            {
                service.retrieveAllOrders();
            }
            if (input == 'p')
            {
                char inp = '\0';
                while(inp != 'p'){
                    service.markPaid();
                    cout << endl;
                    cout << " p: mark next order as paid" << endl;
                    cin >> inp;
                }
            }
            if(input != 'm' && input != 'r' && input != 'q' && input != 'p' && input != 'q') throw InvalidCharInput();
        }
        catch(InvalidCharInput a)
        {
            cout << " Wrong input!, please choose again." << endl;
        }
    }
}

