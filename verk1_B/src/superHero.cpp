#include "superHero.h"

superHero::superHero()
{
    _name[0] = '\0';
    _age = 0;
    _power = 'n';
}
superHero::superHero(char* name, int age, char power)
{
    _name[0] = name[0];
    _age = age;
    _power = power;
}
ostream& operator << (ostream& out, const superHero& hero)
{
    out << hero._name << " (";
    out << hero._age << "): ";
    if(hero._power == 'f') out << "Flying" << endl;
    if(hero._power == 'g') out << "Giant" << endl;
    if(hero._power == 'h') out << "Hacker" << endl;
    if(hero._power == 'n') out << "None" << endl;
    if(hero._power != 'f' && hero._power != 'g' && hero._power != 'h' && hero._power != 'n'){
        out << "Weakling" << endl;
    }

    return out;
}
istream& operator >> (istream& in, superHero& hero)
{
    in >> hero._name;
    in >> hero._age;
    in >> hero._power;
    return in;
}
