#include "pizza.h"

using namespace std;


void menu()
{
    cout << "Enter one or more characters for toppings: " << endl;
    cout << "Possible values are: "<< endl;
    cout << "'p': Pepperoni" << endl;
    cout << "'h': Ham" << endl;
    cout << "'c': Chicken" << endl;
    cout << "'a': Pineapple" << endl;
    cout << "'m': Mushroom" << endl;
    cout << "'b': Bellpepper" << endl;
    cout << "'j': Jalapeno" << endl;
    cout << "Anything else: No toppings" << endl;
}






void create_pizza ()
{
    ofstream fout;
    fout.open("Pizza.txt", ios::app);
    char sizep;
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
        menu();
        cout << "What toppings would you like?"<< endl;
        cin >> toppings;

        //cout << "struct 1" <<endl;
        pizza baka1(sizep, toppings, 0);

        fout << baka1;
        fout.close();








    }

}


void read_pizza()
{

    //cout << "struct 2" <<endl;
    pizza baka2('s', "", 0);

    std::ifstream fin("pizza.txt");
    if(fin.is_open())
    {

        while(fin >> baka2)
        {
        cout << baka2.pprint();
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
