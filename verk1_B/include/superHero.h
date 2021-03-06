#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class superHero
{
    private:
        char _name[30];
        int _age;
        char _power;
        bool _verbose;
    public:
        superHero();
        superHero(char* name, int age, char power);
        void setVerbose(bool v);
        friend ostream& operator << (ostream& out, const superHero& hero);
        friend istream& operator >> (istream& in, superHero& hero);
};

#endif // SUPERHERO_H
