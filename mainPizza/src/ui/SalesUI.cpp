#include "SalesUI.h"
#include "Toppings.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include "SidesRepository.h"
#include <stdlib.h>

using namespace std;

void SalesUI::Sales()
{
    char selection = '\0';
    while(selection != 'q')
    {
        cout << endl;
        cout << " Hello salesperson, would you like to: " << endl;
        cout << " m: make order" << endl;
        cout << " r: read order" << endl;
        cout << " p: mark order as paid" << endl;
        cout << " q: quit" << endl;
        cout << " -> ";
        cin >> selection;
        system("CLS");

        if(selection == 'm')
        {

            int psize;
            Orders order;
            order.add_number();
            char selection = 'y';
            while(selection == 'y')
            {
                vector<Toppings> toppings = toppingRepo.retrieveAllToppings();
                vector<Sides> sides = sideRepo.retrieveAllSides();

                cout << endl;
                cout << " Please enter the size of the pizza, s: small, m: medium, l: large " << endl;
                cout << " -> ";
                char sizeInput;
                cin >> sizeInput;
                system("CLS");
                switch(sizeInput)
                {
                case 's':
                    psize = 1;
                    break;
                case 'm':
                    psize = 2;
                    break;
                case 'l':
                    psize = 3;
                    break;
                default:
                    cout << " Invalid input, using medium. " << endl;
                    psize = 2;

                }
                Pizza p(psize);
                Sides s;




                int toppingSelection = -1;
                int sideSelection = -1;
                while(toppingSelection != 0)
                {
                    cout << endl;
                    cout << " Please enter id for toppings to add (0 for no more)" << endl;

                    for(unsigned int i = 0; i < toppings.size(); i++)
                    {
                        cout << " [" << i + 1 << "] " << toppings[i] << endl;
                    }
                    cout << " -> ";
                    cin >> toppingSelection;
                    system("CLS");
                    if(toppingSelection > 0 && toppingSelection <= (int)toppings.size())
                    {
                        p.addTopping(toppings[toppingSelection - 1]);
                    }
                }
                order.addPizza(p);
                cout << endl;
                cout << " Would you like to add another pizza? (y/n): " << endl;
                cout << " -> ";
                cin >> selection;
                system("CLS");

                cout << endl;
                cout << " Would you like to add other products? (y/n): " << endl;
                cout << " -> ";
                cin >> selection;
                system("CLS");
                if (selection == 'y')
                {
                    while(sideSelection != 0)
                    {
                        cout << endl;
                        cout << " Please enter id for sides to add (0 for no more)" << endl;

                        for(unsigned int i = 0; i < sides.size(); i++)
                        {
                            cout << " [" << i + 1 << "] " << sides[i] << endl;
                        }
                        cout << " -> ";
                        cin >> sideSelection;
                        if(sideSelection > 0 && sideSelection <= (int)sides.size())
                        {
                            order.addSides(sides[sideSelection - 1]);

                            selection = 'n';
                        }
                    }

                }
            }
            OrderRepository orderRepo;
            orderRepo.storeOrder(order);
        }
        if(selection == 'r')
        {
            OrderRepository orderRepo;
            orderRepo.retrieveALL();
        }

        if (selection == 'p')
        {
            SalesUI cashier;

            OrderRepository orderRepo;
            Orders order;
            order = orderRepo.getstatus(2);
            if (order.getOrderNum() != 0)
            {
                cashier.changeStatus(order);
            }

        }





        if(selection != 'm' && selection != 'r' && selection != 'q' && selection != 'p')
        {
            cout << endl;
            cout << " Wrong selection!, please choose again." << endl;
            cout << endl;
        }
    }
}

void SalesUI::changeStatus(Orders order)
{
    cout << order;

    order.incrementStatus();
    OrderRepository orderReady;
    orderReady.storeOrder(order);
}
