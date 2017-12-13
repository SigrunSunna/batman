#include "OrderRepository.h"
#include <string>
#include <windows.h>
#include <dirent.h>
#include <sstream>







OrderRepository::OrderRepository()
{
    //ctor
}

OrderRepository::~OrderRepository()
{
    //dtor
}

void OrderRepository::storeOrder(const Orders& o)
{
    CreateDirectory("Orders\\",NULL);

    string fileName = "Orders\\" + to_string(o._orderNum);
    ofstream fout;
    fout.open(fileName, ios::binary);

    o.write(fout);

    fout.close();
}
Orders OrderRepository::retrieveOrder()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary);
    cout << "retrieveOrder" << endl;

    Orders s;
    s.read(fin);

    fin.close();

    return s;
}


Orders OrderRepository::getstatusNull()
{

    unsigned char isFile =0;
    ifstream fin;
    stringstream ss;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("Orders\\")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            stringstream ss;
            if ( ent->d_type == isFile)
            {
                ss << "Orders\\" << ent->d_name;
                fin.open(ss.str(), ios::binary);
                Orders s;
                s.read(fin);
                if(s.getStatus() == 0)
                {
                    fin.close();
                    closedir (dir);
                    return s;
                }
                fin.close();
            }
        }
        closedir (dir);
    }
    Orders x;
    cout << "All is done" << endl;
    return x;

}


void OrderRepository::retrieveALL()
{
    unsigned char isFile =0;
    ifstream fin;
    stringstream ss;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("Orders\\")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            stringstream ss;
            if ( ent->d_type == isFile)
            {
                ss << "Orders\\" << ent->d_name;
                fin.open(ss.str(), ios::binary);
                Orders s;
                s.read(fin);
                cout << s;
                cout << "----------------------" << endl;
                fin.close();
            }
        }
        closedir (dir);
    }

    /*ifstream fin;
    fin.open("Orders\\", ios::binary);
    while(!fin.eof())
    {
        Orders s;
        s.read(fin);
        if(fin.eof())
        {
            break;
        }
        cout << s;
        cout << "----------------------" << endl;

    }*/

 }
/*void OrderRepository::retrieveALL()
{
    ifstream fin;
    fin.open("Orders.dat", ios::binary);


    while(!fin.eof())
    {
        Orders s;
        s = retrieveOrder();
        s.read(fin);
        cout << s;
        cout << "----------------------" << endl;
    }
    fin.close();

}*/

