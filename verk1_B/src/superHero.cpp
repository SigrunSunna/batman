#include "superHero.h"

superHero::superHero()
{
    _name[0] = '\0';
    _age = 0;
    _power = 'n';
    _verbose = true;

}
superHero::superHero(char* name, int age, char power)
{
    _name[0] = name[0];
    _age = age;
    _power = power;
}
void superHero::setVerbose(bool v)
{
    _verbose = v;
}
ostream& operator << (ostream& out, const superHero& hero)
{

    if(!hero._verbose)
    {
        out << hero._name << " (";
    }
    else
    {
        out << hero._name << endl;
    }
    if(!hero._verbose)
    {
        out << hero._age << "): ";
    }
    else
    {
        out << hero._age << endl;
    }
    if(!hero._verbose)
    {
        if(hero._power == 'f') out << "Flying" << endl;
        if(hero._power == 'g') out << "Giant" << endl;
        if(hero._power == 'h') out << "Hacker" << endl;
        if(hero._power == 'n') out << "None" << endl;
        if(hero._power != 'f' && hero._power != 'g' && hero._power != 'h' && hero._power != 'n'){
            out << "Weakling" << endl;
        }
    }
    else
    {
        out << hero._power << endl;
    }
    return out;
}
istream& operator >> (istream& in, superHero& hero)
{
    if(hero._verbose)
    {
        cout << "Please enter hero's name:  " ;
    }
    in >> hero._name;
    if(hero._verbose)
    {
        cout << "Please enter hero's age:   " ;
    }
    in >> hero._age;
    if(hero._verbose)
    {
        cout << "Please enter hero's power: " ;
    }
    in >> hero._power;
    return in;
}
