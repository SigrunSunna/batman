#include "SalesUI.h"
#include "Toppings.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"

using namespace std;

void SalesUI::Sales()
{
    char selection = '\0';
    while(selection != 'q')
    {
        cout << "m: make order" << endl;
        cout << "r: read order" << endl;
        cout << "q: quit" << endl;
        cin >> selection;

        if(selection == 'm')
        {
                Orders order;
                order.add_number();
                char selection = 'y';
                while(selection == 'y')
                {
                    vector<Toppings> toppings = toppingRepo.retrieveAllToppings();

                    Pizza p;

                    int toppingSelection = -1;
                    while(toppingSelection != 0)
                    {
                        cout << "Please enter id for toppings to add (0 for no more)" << endl;

                        for(unsigned int i = 0; i < toppings.size(); i++)
                        {
                            cout << "[" << i + 1 << "] " << toppings[i] << endl;
                        }
                        cin >> toppingSelection;
                        if(toppingSelection > 0 && toppingSelection <= (int)toppings.size())
                        {
                            p.addTopping(toppings[toppingSelection - 1]);
                        }
                    }
                    order.addPizza(p);
                    cout << "Would you like to add another pizza?: " << endl;
                    cin >> selection;
                }
                OrderRepository orderRepo;
                orderRepo.storeOrder(order);
                cout << endl;
        }
        if(selection == 'r')
        {
            OrderRepository orderRepo;
            Orders order = orderRepo.retrieveOrder();
            cout << order;

            cout << endl;
        }


        if(selection != 'm' && selection != 'r' && selection != 'q')
        {
            cout << endl;
            cout << "Wrong selection!, please choose again." << endl;
            cout << endl;
        }
    }
}
