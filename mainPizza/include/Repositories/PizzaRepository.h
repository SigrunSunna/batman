#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "Pizza.h"
#include <fstream>

using namespace std;

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(const Pizza& p);
        Pizza retrievePizza();

    private:
};

#endif // PIZZAREPOSITORY_H
