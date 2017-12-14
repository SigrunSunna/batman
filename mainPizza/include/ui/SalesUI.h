#ifndef SALESUI_H
#define SALESUI_H
#include <iostream>
#include "Pizza.h"
#include "ToppingRepository.h"
#include "SidesRepository.h"
#include "OrderRepository.h"
#include "Orders.h"

using namespace std;

class SalesUI
{
    public:
        void Sales();
        ToppingRepository toppingRepo;
        SidesRepository sideRepo;
        void changeStatus(Orders order);

};

#endif // SALESUI_H
