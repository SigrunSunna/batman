#include "BakerUI.h"
#include "PizzaRepository.h"




void BakerUI::Baker()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << endl << "Hello baker, would you like to:" << endl;
        cout << "v: view orders" << endl;
        cout << "q: quit " << endl;
        cout << "b: to bake next order in line" << endl;
        cout << "-> ";
        cin >> inp;
        cout << endl;
        if (inp == 'v')
        {

            OrderRepository orderRepo;
            orderRepo.retrieveALL();
        }
        if (inp == 'b')
        {
            BakerUI baker;

            OrderRepository orderRepo;
            Orders order;
            order = orderRepo.getstatus(0);
            if (order.getOrderNum() != 0)
            {
                baker.changeStatus(order);
            }

        }

    }
}


void BakerUI::changeStatus(Orders order)
{
    cout << order;

    order.incrementStatus();
    OrderRepository orderbake;
    orderbake.storeOrder(order);
}
