#include "pizza.h"

using namespace std;

void create_pizza ()
{
    ofstream fout;
    fout.open("Pizza.txt", ios::app);
    char sizep;
    int price = 1500;
    string toppings;
    if(fout.is_open())
    {
        cout << "Hello dear customer, please pick the sizep of your pizza." << endl << "s for small, m for medium, l for large: ";
            cin >> sizep;
        while (sizep != 's' && sizep != 'm' && sizep != 'l')
        {
            cout << "Please enter a valid sizep! " << endl;
            cin >> sizep;
        }
        cout << "What toppings would you like?"<< endl;
        cin >> toppings;


        if (sizep == 's')
        {
            price = 900;
        }
        else if (sizep == 'm')
        {
            price = 1200;
        }
        else if (sizep == 'l')
        {
            price = 1500;
        }
        price = price + (toppings.size() * 150);
                fout << sizep << endl;
        fout << toppings << endl;
        fout << price << endl;
        fout.close();
    }
}

void read_pizza()
{

    ifstream fin;
    pizza pontun;
    fin.open("pizza.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            fin >> pontun;
            if ( !fin.eof() )
            {
            cout << pontun << endl;
            }
        }
    }
    fin.close();
}

int main()
{
create_pizza ();
read_pizza();


    return 0;
}
