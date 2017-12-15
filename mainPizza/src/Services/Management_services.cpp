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

void Management_services::addSides()
{
    vector<Sides> sides = sidesRepo.retrieveAllSides();
    for(unsigned int i = 0; i < sides.size(); i++)
    {
        cout << " [" << i + 1 << "] " << sides[i] << endl;
    }
    cout << endl;

    char selection = 'y';
    Sides s;
    while(selection == 'y')
    {
        cout << " Add another side (y)?: ";
        cin >> selection;
        system("CLS");
        if(selection == 'y')
        {
            cin >> s;
            system("CLS");
            sides.push_back(s);
        }
    }
    sidesRepo.storeAllSides(sides);
}

void Management_services::getOrder(int ordInp)
{
    cout << orderRepo.fetchOrder(ordInp);
}

void Management_services::sizePrice()
{
    pizzaRepo.setSize();
}

