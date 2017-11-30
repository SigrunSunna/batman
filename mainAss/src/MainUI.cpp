#include "MainUI.h"

void MainUI::startUI()
{
    char input;
    cout << "What is your position?" << endl;
    cout << "Manager = m, Sales = s, Baker = b, Delivery = d, quit = q: ";
    cin >> input;
    while(input == 'm' || input == 's' || input == 'b' || input == 'd')
    {
        if(input == 'm')
        {
            Manager manager;
        }
        if(input == 's')
        {
            Sales sales;
        }
        if(input == 'b')
        {
            Baker baker;
        }
        if(input == 'd')
        {
            Delivery delivery;
        }
    cout << "What is your position?" << endl;
    cout << "Manager = m, Sales = s, Baker = b, Delivery = d, quit = Any other button: ";
    cin >> input;
    }
}
