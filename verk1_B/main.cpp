#include "superHero.h"

using namespace std;

char input()
{
    char in;
    cin >> in;
    return in;
}

void binaryCreate()
{
    ofstream fout;
    superHero hero;
    cin >> hero;

    fout.open("binaryHeroes.txt", ios::binary|ios::app);

    fout.write((char*)(&hero), sizeof(superHero));

    fout.close();


    //cout << "dfdf";
}
void binaryRead()
{
    ifstream fin;

    fin.open("binaryHeroes.txt", ios::binary);

    fin.seekg(0, fin.end);
    int numHeroes = fin.tellg() / sizeof(superHero);
    fin.seekg(0, fin.beg);

    superHero *hero = new superHero[numHeroes];
    fin.read((char*)hero, sizeof(superHero) * numHeroes);

    fin.close();

    for(int i = 0; i < numHeroes; i++)
    {
        hero[i].setVerbose(false);
        cout << hero[i] << endl;
    }

    delete[] hero;
}

void createHero()
{
    ofstream fout;
    superHero hero;
    fout.open("Heroes.txt", ios::app);
    if(fout.is_open())
    {
        cin >> hero;
        fout << hero << endl;
        fout.close();
    }
}
void readHeroes()
{
    ifstream fin;
    superHero hero;
    fin.open("Heroes.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
                hero.setVerbose(false);
                fin >> hero;
                if (!fin.eof())
                {
                    cout << hero << endl;
                }
        }
    }
    fin.close();
}

int main()
{
    cout << "Create or read heroes normally or using binary files?" << endl;
    cout << "create = c, read = r, binary create = b, binary read = d, quit = q: ";
    char inp = input();
    cout << endl;
    while(inp == 'c' || inp == 'r' || inp == 'b' || inp == 'd')
    {
        if(inp == 'c')
        {
            createHero();
        }
        if(inp == 'r')
        {
            readHeroes();
        }
        if(inp == 'b')
        {
            binaryCreate();
        }
        if(inp == 'd')
        {
            binaryRead();
        }
        cout << "Create or read heroes normally or using binary files?" << endl;
        cout << "create = c, read = r, binary create = b, binary read = d, quit = q: ";
        inp = input();
        cout << endl;
    }

    return 0;
}
