#include "ManagementUI.h"
#include "PizzaRepository.h"
#include "ToppingRepository.h"
#include "Orders.h"
#include <stdlib.h>

void ManagementUI::Management()
{
    ToppingRepository toppingRepo;
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl << " Hello Manager, would you like to:" << endl;
        cout << " t: add toppings" << endl;
        cout << " v: view orders" << endl;
        cout << " c: change pizza prices" << endl;
        cout << " r: retrieve a specific order." << endl;
        cout << " q: quit " << endl;
        cout << " -> ";
        cin >> inp;
        system("CLS");
        if (inp == 'v')
        {
            OrderRepository orderRepo;
            orderRepo.retrieveALL();
        }
        if(inp == 't')
        {
            vector<Toppings> toppings = toppingRepo.retrieveAllToppings();
            cout << endl;
            cout << " These are the current toppings in the system: " << endl;
            for(unsigned int i = 0; i < toppings.size(); i++)
            {
                cout << " [" << i + 1 << "] " << toppings[i] << endl;
            }
            cout << endl;

            char selection = 'y';
            Toppings t;
            while(selection == 'y')
            {
                cout << " Add another topping (y)?: ";
                cin >> selection;
                system("CLS");
                if(selection == 'y')
                {
                    cin >> t;
                    system("CLS");
                    toppings.push_back(t);
                }
            }
            toppingRepo.storeAllToppings(toppings);
        }
        if(inp == 'c')
        {
            {
                int smallPrice = 0;
                int mediumPrice = 0;
                int largePrice = 0;


                ifstream fin;
                fin.open("pizzaPrice.dat", ios::binary);
                fin.read((char*)(&smallPrice), sizeof(int));
                fin.read((char*)(&mediumPrice), sizeof(int));
                fin.read((char*)(&largePrice), sizeof(int));

                cout << " Currently the price of a small pizza is: " << smallPrice << endl;
                cout << " Please set a price for a small pizza: " << endl;
                cout << " -> ";
                cin >> smallPrice;
                system("CLS");
                cout << endl;
                cout << " Currently the price of a medium pizza is: " << mediumPrice << endl;
                cout << " Please set a price for a medium pizza: " << endl;
                cout << " -> ";
                cin >> mediumPrice;
                system("CLS");
                cout << endl;
                cout << "currently the price of a large pizza is: " << largePrice << endl;
                cout << "Please set a price for a large pizza: " << endl;
                cout << " -> ";
                cin >> largePrice;
                system("CLS");
                fin.close();

                ofstream fout;
                fout.open("pizzaPrice.dat", ios::binary);
                fout.write((char*)(&smallPrice), sizeof(int));
                fout.write((char*)(&mediumPrice), sizeof(int));
                fout.write((char*)(&largePrice), sizeof(int));

                fout.close();
            }

        }
        if(inp == 'r')
        {
            int ordInp;

            cout << " What order would you like to pull?" << endl;
            cout << " ->";
            cin >> ordInp;
            system("CLS");

            Orders b;

           cout << b.fetchOrder(ordInp);


        }
    }
}
