#include "SidesRepository.h"
#include <fstream>

using namespace std;

SidesRepository::SidesRepository()
{
    //ctor
}

SidesRepository::~SidesRepository()
{
    //dtor
}


void SidesRepository::storeAllSides(const vector<Sides> &sides)
{
    ofstream fout;
    fout.open("sides.dat", ios::binary);

    int sideCount = sides.size();

    fout.write((char*)(&sideCount), sizeof(int));

    for(int i = 0; i < sideCount; i++)
    {
        sides[i].write(fout);
    }

    fout.close();
}


vector<Sides> SidesRepository::retrieveAllSides()
{
    vector<Sides> sides;
    Sides side;

    ifstream fin;
    fin.open("sides.dat", ios::binary);

    if(fin.is_open())
    {
        int sideCount;
        fin.read((char*)(&sideCount), sizeof(int));

        for(int i = 0; i < sideCount; i++)
        {
            side.read(fin);
            sides.push_back(side);
        }

        fin.close();
    }

    return sides;
}
