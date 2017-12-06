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


        pizza baka1(sizep, toppings, 0);
        fout << baka1.list_pizza();
        fout.close();








    }

}


void read_pizza()
{
    string str;
    int nr_pizzu;
    int pos1, pos2, pos3;
    string str_size;
    string toppings;
    char sizep;

    ifstream fin;
    //pizza pontun;
    fin.open("pizza.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            getline(fin, str);
            if (str.size() > 0)
            {
                pos1 = str.find(';');
                nr_pizzu = stoi(str.substr(0, pos1));
                str_size = str.substr(pos1 +1, 1);
                pos2 = str.find(';', pos1 +1);
                pos3 = str.find(';', pos2+1);
                toppings = str.substr(pos1 +3, pos3 - pos2-1);
                sizep = str_size[0];
                pizza baka2(sizep, toppings, 0);
               cout << baka2.pprint();


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
