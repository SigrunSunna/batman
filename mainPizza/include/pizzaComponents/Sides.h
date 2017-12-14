#ifndef SIDES_H
#define SIDES_H
#include <iostream>
#include <string.h>

using namespace std;


class Sides
{
    public:
        Sides();
        Sides(string name, double price);
        virtual ~Sides();

        void write(ofstream& fout) const;
        void read(ifstream& fin);


        double getPrice ();


        friend ostream& operator << (ostream& out, const Sides& top);
        friend istream& operator >> (istream& in, Sides& top);


    protected:

    private:
        string _name;
        double _price;

};

#endif // Sides_H
