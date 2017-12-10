#include "BakerUI.h"

void BakerUI::Baker()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello baker, would you like to:" << endl;
        cout << "v: view orders, q: quit?: ";
        cin >> inp;
    }
}
