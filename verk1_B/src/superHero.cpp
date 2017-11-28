#include "superHero.h"

superHero::superHero()
{
    _name = "";
    _age = 0;
    _power = 'n';
}
superHero::superHero(string name, int age, char power)
{
    _name = name;
    _age = age;
    _power = power;
}
ostream& operator << (ostream& out, superHero hero)
{
    out << hero._name << " (";
    out << hero._age << "): ";
    if(hero._power == 'f ') out << "Flying" << endl;
    if(hero._power == 'g ') out << "Giant" << endl;
    if(hero._power == 'h ') out << "Hacker" << endl;
    if(hero._power == 'n ') out << "None" << endl;
    else out << "Weakling" << endl;

    return out;
}
istream& operator >> (istream& in, superHero hero)
{
    in >> hero._name >> hero._age >> hero._power;
    return in;
}
