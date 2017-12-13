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

            int psize;
                Orders order;
                order.add_number();
                char selection = 'y';
                while(selection == 'y')
                {
                    vector<Toppings> toppings = toppingRepo.retrieveAllToppings();

                    cout << "Please enter the size of the pizza, s: small, m: medium, l: large " << endl;
                    char sizeInput;
                    cin >> sizeInput;
                    switch(sizeInput)
                    {
                    case 's': psize = 1;
                        break;
                    case 'm': psize = 2;
                        break;
                    case 'l': psize = 3;
                        break;
                    default:   cout << "invalid input using medium. " << endl;
                            psize = 2;

                    }
                    Pizza p(psize);




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
            orderRepo.retrieveALL();
        }


        if(selection != 'm' && selection != 'r' && selection != 'q')
        {
            cout << endl;
            cout << "Wrong selection!, please choose again." << endl;
            cout << endl;
        }
    }
}
