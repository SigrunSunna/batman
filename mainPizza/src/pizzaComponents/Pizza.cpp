#include "Pizza.h"

Pizza::Pizza()
{
    //_verbose = true;
}

//void Pizza::set_verbose(bool v)
//{
//    _verbose = v;
//}

void Pizza::set_price(int price)
{
    _price = price;
}

ostream& operator << (ostream& out, const Pizza& pizza)
{
    out << pizza._size << endl;
    out << pizza._toppings << endl;
    out << pizza._price << endl;
    return out;
}
istream& operator >> (istream& in, Pizza& pizza)
{
    in >> pizza._size;
    in >> pizza._toppings;

    return in;
}

