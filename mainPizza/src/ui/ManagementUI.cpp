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
        cout << "c: change pizza prices" << endl;
        cout << "q: quit " << endl;
        cout << "-> ";
        cin >> inp;
        if (inp == 'v')
        {
            OrderRepository orderRepo;
            orderRepo.retrieveALL();
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
                if(selection == 'y')
                {
                    cin >> t;
                    toppings.push_back(t);
                }
            }
            toppingRepo.storeAllToppings(toppings);


        }
        if(inp == 'c')
        {

            {

                int smallPrice, mediumPrice, largePrice;


                ifstream fin;
                fin.open("pizzaPrice.dat", ios::binary);
                fin.read((char*)(&smallPrice), sizeof(int));
                fin.read((char*)(&mediumPrice), sizeof(int));
                fin.read((char*)(&largePrice), sizeof(int));



                cout << "currently the price of a small pizza is: " << smallPrice << endl;
                cout << "Please set a price for a small pizza: " << endl;
                cin >> smallPrice;
                cout << "currently the price of a medium pizza is: " << mediumPrice << endl;
                cout << "Please set a price for a mediun pizza: " << endl;
                cin >> mediumPrice;
                cout << "currently the price of a large pizza is: " << largePrice << endl;
                cout << "Please set a price for a large pizza: " << endl;
                cin >> largePrice;
                fin.close();

                ofstream fout;
                fout.open("pizzaPrice.dat", ios::binary);
                fout.write((char*)(&smallPrice), sizeof(int));
                fout.write((char*)(&mediumPrice), sizeof(int));
                fout.write((char*)(&largePrice), sizeof(int));



                fout.close();
            }

        }
    }
}
