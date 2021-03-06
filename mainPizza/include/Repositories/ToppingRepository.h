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

        void storeAllToppings(const vector<Toppings> &toppings);
        vector<Toppings> retrieveAllToppings();

    private:
};

#endif // TOPPINGREPOSITORY_H
