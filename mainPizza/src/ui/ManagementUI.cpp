#include "ManagementUI.h"
#include "PizzaRepository.h"

void ManagementUI::Management()
{

    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello Manager, would you like to:" << endl;
        cout << "v: view orders, q: quit?: ";
        cin >> inp;
        if (inp == 'v')
        {

            PizzaRepository pizzaRepo;
            pizzaRepo.retrieveALL();
        }
    }
}
