#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include "SalesUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include "ManagementUI.h"

using namespace std;


class MainUI
{
    private:
        ManagementUI manager;
        SalesUI sales;
        BakerUI baker;
        DeliveryUI delivery;
    public:
        void startUI();
};

#endif // MAINUI_H
