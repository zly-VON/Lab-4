#ifndef STORE_H
#define STORE_H

#include "Object.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;


class Store : public Object
{
    public:
        void Welcome();
        void goMainStore(string name);
        void goFishmonger(string name);
        void goButcher(string name);
        void goDrinkSection(string name);
        void goVendingMachine(string name);
        void goCashier(string name);
        void leaveStore(string name);
};

#endif