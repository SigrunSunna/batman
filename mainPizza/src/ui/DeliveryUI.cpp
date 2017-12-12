#include "DeliveryUI.h"
#include "PizzaRepository.h"

void DeliveryUI::Delivery()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello Delivery Person, would you like to:" << endl;
        cout << "v: view orders, q: quit?: ";
        cin >> inp;
             if (inp == 'v')
        {

            PizzaRepository pizzaRepo;
            pizzaRepo.retrieveALL();
        }
    }
}
