#ifndef TOPPINGREPOSITORY_H
#define TOPPINGREPOSITORY_H

#include "Toppings.h"
#include <vector>

using namespace std;

class ToppingRepository
{
    public:
        ToppingRepository();
        virtual ~ToppingRepository();

        //void storeTopping(const Toppings& t);
        //Toppings retrieveTopping();

        void storeAllToppings(const vector<Toppings> &toppings);
        vector<Toppings> retrieveAllToppings();

    private:
};

#endif // TOPPINGREPOSITORY_H
