#include <iostream>

using namespace std;

int toppingCount = 0;
double price = 0;

void pickToppings (){

    cout << "You have picked: " << toppingCount <<
    " toppings" << endl;
    cout << "Please pick a topping:" << endl;
    cout << "p - Pepperoni 200 kr" << endl;
    cout << "h - Ham 190 kr" << endl;
    cout << "c - Cheese 50 kr" << endl;
    cout << "t - Tomato 105 kr" << endl;

}

void toppings(char input)
{
    if (input == 'p') {
        price += 200;
        toppingCount++;
    }
    else if (input == 'h') {
        price += 190;
        toppingCount++;
    }
    else if (input == 'c') {
        price += 50;
        toppingCount++;
    }
    else if (input == 't') {
        price += 105;
        toppingCount++;
    }
    else {
           cout << "'" << input << "' is not a valid topping" << endl;
    }
}

int main () {

    cout << "What would you like on your pizza? Pick 3 types of toppings" << endl<<endl;
    do {
            char input = 0;
            pickToppings();
            cin >> input;
            toppings(input);
    }

    while (toppingCount < 3);

    cout << "Your price "<< price << " kr";

    return 0;
}
