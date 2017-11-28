#include "superHero.h"


using namespace std;

char input()
{
    char in;
    cin >> in;
    return in;
}

void createHero()
{
    ofstream fout;
    string name;
    int age;
    char power;
    fout.open("Heroes.txt", ios::app);
    if(fout.is_open())
    {
        cin >> name;
        cin >> age;
        cin >> power;
        fout << name << endl;
        fout << age << endl;
        fout << power;
        fout.close();
    }
}
void readHeroes()
{
    ifstream fin;
    superHero hero;
    //int counter = 1;
    fin.open("Heroes.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            fin >> hero;
            cout << hero << endl;
        }
    }
    fin.close();
}

int main()
{
    cout << "Create or read heroes? create = c, read = r, quit = q: ";
    char inp = input();
    while(inp == 'c' || inp == 'r')
    {
        if(inp == 'c')
        {
            createHero();
        }
        if(inp == 'r')
        {
            readHeroes();
        }
        cout << "Create or read heroes? create = c, read = r, quit = q: ";
        inp = input();
    }

    return 0;
}
