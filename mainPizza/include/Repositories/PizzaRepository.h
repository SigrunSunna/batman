#ifndef PIZZAREPOSITORY_H
#define PIZZAREPOSITORY_H
#include "Pizza.h"
#include <fstream>
#include "OrderRepository.h"

using namespace std;

class PizzaRepository
{
    public:
        PizzaRepository();
        virtual ~PizzaRepository();

        void storePizza(const Pizza& p);
        Orders retrievePizza();

        void retrieveALL();

    private:
};

#endif // PIZZAREPOSITORY_H
