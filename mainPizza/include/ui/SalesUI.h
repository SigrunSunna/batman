#ifndef SALESUI_H
#define SALESUI_H
#include <iostream>
#include "Pizza.h"
#include "ToppingRepository.h"
#include "OrderRepository.h"
#include "Orders.h"

using namespace std;

class SalesUI
{
    public:
        void Sales();
        ToppingRepository toppingRepo;

};

#endif // SALESUI_H
