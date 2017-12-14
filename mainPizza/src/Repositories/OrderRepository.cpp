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




Orders OrderRepository::getstatus(int status)
{


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


            if(ent->d_name[0] !=  '.')
            {

                ss << "Orders\\" << ent->d_name;
                fin.open(ss.str(), ios::binary);
                Orders s;
                s.read(fin);
                if(s.getStatus() == status)
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
    cout << " All is done" << endl;
    return x;

}


void OrderRepository::retrieveALL()
{
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
            if (ent->d_name[0] != '.')
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

}

void OrderRepository::retrieveStatus(int status)
{
    ifstream fin;
    stringstream ss;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("Orders/")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            stringstream ss;
            if (ent->d_name[0] != '.')
            {
                Orders s;

                ss << "Orders/" << ent->d_name;
                fin.open(ss.str(), ios::binary);

                s.read(fin);
                 if (s.getStatus() == status)
                {
                cout << s;
                cout << "----------------------" << endl;
                }

                fin.close();


            }
        }
        closedir (dir);
    }

}

Orders OrderRepository::fetchOrder(int orderNO)
{
    string filename = "Orders\\";

    filename = filename + to_string(orderNO);

    ifstream fin;
    fin.open(filename, ios::binary);
    if(!fin.is_open())
    {
        cout << " Order not found!" << endl;
        Orders defaulto;
        return defaulto;
    }
    Orders s;
    s.read(fin);
    fin.close();

    return s;
}


