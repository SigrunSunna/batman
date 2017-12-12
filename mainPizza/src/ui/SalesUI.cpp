#include "SalesUI.h"
#include "Toppings.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"

using namespace std;

void SalesUI::Sales()
{
    char selection = '\0';
    ToppingRepository toppingRepo;
    while(selection != 'q')
    {
        cout << "m: make pizza" << endl;
        cout << "r: read pizza" << endl;
        cout << "q: quit" << endl;
        cin >> selection;

        if(selection == 'm')
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


            PizzaRepository pizzaRepo;
            pizzaRepo.storePizza(p);
            cout << endl;
        }
        if(selection == 'r')
        {
            PizzaRepository pizzaRepo;
            Pizza p = pizzaRepo.retrievePizza();
            cout << p;

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
