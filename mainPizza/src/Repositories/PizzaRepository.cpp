#include "PizzaRepository.h"
#include "OrderRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

PizzaRepository::~PizzaRepository()
{
    //dtor
}

void PizzaRepository::storePizza(const Pizza& p)
{

    ofstream fout;
    fout.open("Pizza.dat", ios::binary | ios::app);

    p.write(fout);

    fout.close();
}

Orders PizzaRepository::retrievePizza()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary);

    Orders s;
    s.read(fin);

    fin.close();

    return s;
}

void PizzaRepository::retrieveALL()
{
    ifstream fin;
    fin.open("Pizza.dat", ios::binary);

    while(!fin.eof())
    {
        Orders s;
        s.read(fin);
        cout << s;
        cout << "----------------------" << endl;
    }
    fin.close();
}

void PizzaRepository::setSize()
{
    int smallPrice = 0;
    int mediumPrice = 0;
    int largePrice = 0;


    ifstream fin;
    fin.open("pizzaPrice.dat", ios::binary);
    fin.read((char*)(&smallPrice), sizeof(int));
    fin.read((char*)(&mediumPrice), sizeof(int));
    fin.read((char*)(&largePrice), sizeof(int));

    cout << endl;
    cout << " Currently the price of a small pizza is: " << smallPrice << endl;
    cout << " Please set a price for a small pizza: " << endl;
    cout << " -> ";
    cin >> smallPrice;
    system("CLS");
    cout << endl;
    cout << " Currently the price of a medium pizza is: " << mediumPrice << endl;
    cout << " Please set a price for a medium pizza: " << endl;
    cout << " -> ";
    cin >> mediumPrice;
    system("CLS");
    cout << endl;
    cout << " Currently the price of a large pizza is: " << largePrice << endl;
    cout << " Please set a price for a large pizza: " << endl;
    cout << " -> ";
    cin >> largePrice;
    system("CLS");
    fin.close();

    ofstream fout;
    fout.open("pizzaPrice.dat", ios::binary);
    fout.write((char*)(&smallPrice), sizeof(int));
    fout.write((char*)(&mediumPrice), sizeof(int));
    fout.write((char*)(&largePrice), sizeof(int));

    fout.close();
}
