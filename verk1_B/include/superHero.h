#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class superHero
{
    private:
        string _name;
        int _age;
        char _power;
    public:
        superHero();
        superHero(string name, int age, char power);
        friend ostream& operator << (ostream& out, const superHero hero);
        friend istream& operator >> (istream& in, superHero hero);
};

#endif // SUPERHERO_H
