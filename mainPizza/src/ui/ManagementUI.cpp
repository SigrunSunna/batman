#include "ManagementUI.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"

void ManagementUI::Management()
{

    ToppingRepository toppingRepo;
    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello Manager, would you like to:" << endl;
        cout << "t: add toppings" << endl;
        cout << "v: view orders" << endl;
        cout << "q: quit " << endl;
        cout << "-> ";
        cin >> inp;
        if (inp == 'v')
        {

            OrderRepository pizzaRepo;
            pizzaRepo.retrieveALL();
        }
        if(inp == 't')
        {
            vector<Toppings> toppings = toppingRepo.retrieveAllToppings();
            cout << "These are the current toppings in the system: " << endl;
            for(unsigned int i = 0; i < toppings.size(); i++)
            {
                cout << "[" << i + 1 << "] " << toppings[i] << endl;
            }
            cout << endl;

            char selection = 'y';
            Toppings t;
            while(selection == 'y')
            {
                cout << "Add another topping (y)?: ";
                cin >> selection;
                if(selection == 'y'){
                    cin >> t;
                    toppings.push_back(t);
                }
            }
            toppingRepo.storeAllToppings(toppings);


        }
    }
}
