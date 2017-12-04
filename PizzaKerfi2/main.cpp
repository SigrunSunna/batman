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
        cout << "Hello dear customer, please pick the size of your pizza." << endl << "s for small, m for medium, l for large: ";
        cin >> sizep;
        while (sizep != 's' && sizep != 'm' && sizep != 'l')
        {
            cout << "Please enter a valid size! " << endl;
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
        //int a = toppings.size();
        string _toppings = "";
        for(int i = 0; i < (int)toppings.size(); i++)
        {
            if(toppings[i] == 'p' ||toppings[i] == 'h' ||toppings[i] == 'm' ||toppings[i] == 'j' ||toppings[i] == 'a')
            {
                _toppings = _toppings + toppings[i];
                price = price +150;
            }

        }
        pizza baka1(sizep, price, _toppings);
        fout << baka1.list_pizza();
        fout.close();
        cout << baka1.pprint();








    }

}


void read_pizza()
{
    string str;


    ifstream fin;
    //pizza pontun;
    fin.open("pizza.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, str);
            cout << str << endl;
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
