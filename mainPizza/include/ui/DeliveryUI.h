#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include <iostream>
#include "Orders.h"

using namespace std;


class DeliveryUI
{
    public:
        void changeStatus(Orders order);
        void Delivery();
};

#endif // DELIVERYUI_H
