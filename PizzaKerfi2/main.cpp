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
        for(int i = 0; i < toppings.size(); i++)
        {
            if(toppings[i] == 'p' ||toppings[i] == 'h' ||toppings[i] == 'm' ||toppings[i] == 'j' ||toppings[i] == 'a')
            {
                price = price +150;
            }

        }
        // price = price + (toppings.size() * 150);
        switch(sizep)
        {
        case 'l':
            fout << "Large" << endl;
            break;
        case 's':
            fout << "Small" << endl;
            break;
        case 'm':
            fout << "Medium" << endl;
            break;
        }
        //       fout << sizep << endl;
        // fout << toppings << endl;

        for (int i = 0; i < toppings.size(); i++)
        {
            switch(toppings[i])
            {
            case 'p':
                fout << "Pepperoni" << endl;
                break;
            case 'h':
                fout << "Ham" << endl;
                break;
            case 'm':
                fout << "Mushroom" << endl;
                break;
            case 'c':
                fout << "Chicken" << endl;
                break;
            case 'a':
                fout << "Pinapple" << endl;
                break;
            case 'b':
                fout << "Bellpepper" << endl;
                break;
            case 'j':
                fout << "Jalapeno" << endl;
                break;
            }
        }


        fout << price << endl;
        fout.close();
    }

}


void read_pizza()
{
    string str;
    ifstream fin;
    pizza pontun;
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
