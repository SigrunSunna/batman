#include "Management_services.h"

Management_services::Management_services()
{
    //ctor
}

Management_services::~Management_services()
{
    //dtor
}
void Management_services::retrieveAllOrders()
{
    orderRepo.retrieveALL();
}


void Management_services::addToppings()
{
    vector<Toppings> toppings = toppingRepo.retrieveAllToppings();
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

void Management_services::getOrder(int ordInp)
{
    cout << orderRepo.fetchOrder(ordInp);
}

void Management_services::sizePrice()
{
    pizzaRepo.setSize();
}

