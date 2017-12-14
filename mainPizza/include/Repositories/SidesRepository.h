#ifndef SIDESREPOSITORY_H
#define SIDESREPOSITORY_H
#include "Sides.h"
#include <vector>

using namespace std;

class SidesRepository
{
    public:
        SidesRepository();
        virtual ~SidesRepository();


        void storeAllSides (const vector<Sides> &sides);
        vector<Sides> retrieveAllSides();

    private:
};

#endif // SIDESREPOSITORY_H



