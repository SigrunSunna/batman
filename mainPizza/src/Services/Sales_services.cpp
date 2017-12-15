#include "Sales_services.h"

Sales_services::Sales_services()
{
    //ctor
}

Sales_services::~Sales_services()
{
    //dtor
}

void Sales_services::storeOrder(Orders& order)
{
    orderRepo.storeOrder(order);
}
void Sales_services::retrieveAllOrders()
{
    orderRepo.retrieveALL();
}
void Sales_services::sizeChoice(int& psize)
{
    char sizeInput;
    while(true) {
    cout << endl;
    cout << " Please enter the size of the pizza, s: small, m: medium, l: large " << endl;
    cout << " -> ";
        try{
            cin >> sizeInput;
            system("CLS");
            if(sizeInput == 's'){
                psize = 1;
                break;
            }
            if(sizeInput == 'm'){
                psize = 2;
                break;
            }
            if(sizeInput == 'l'){
                psize = 3;
                break;
            }
            else throw InvalidCharInput();
        }
        catch(InvalidCharInput){
            cout << " Wrong input!, please choose again." << endl;
        }
    }
}

void Sales_services::toppingChoice(Pizza& p)
{
    vector<Toppings> toppings = toppingRepo.retrieveAllToppings();
    int toppingSelection = -1;
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
}

void Sales_services::sidesChoice(Orders& order)
{
    vector<Sides> sides = sideRepo.retrieveAllSides();
    int sideSelection = -1;
    while(sideSelection != 0)
    {
        Sides s;
        cout << endl;
        cout << " Please enter id for sides to add (0 for no more)" << endl;

        for(unsigned int i = 0; i < sides.size(); i++)
        {
            cout << " [" << i + 1 << "] " << sides[i] << endl;
        }
        cout << " -> ";
        cin >> sideSelection;
        system("CLS");
        if(sideSelection > 0 && sideSelection <= (int)sides.size())
        {
            order.addSides(sides[sideSelection - 1]);
        }
    }
}

void Sales_services::markPaid()
{
    Orders order;
    order = orderRepo.getstatus(2);
    if (order.getOrderNum() != 0)
    {
        cout << order;
        order.incrementStatus();
        orderRepo.storeOrder(order);
    }
}
