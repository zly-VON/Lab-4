#include "Store.h"

void Store::Welcome()
{
    cout << "Hello. Welcome at " << getName() << endl;
    sleep(2);
}
void Store::goMainStore(string name)
{
    cout << name << " is in the Main Section.\n" << endl;
    sleep(2);
}
void Store::goFishmonger(string name)
{
    cout << name << " is going to the fishmonger.\n" << endl;
    sleep(2);
}
void Store::goButcher(string name)
{
    cout << name << " is going to the butcher.\n" << endl;
    sleep(2);
}
void Store::goDrinkSection(string name)
{
    cout << name << " is going to the Beverage Section.\n" << endl;
    sleep(2);
}
void Store::goVendingMachine(string name)
{
    cout << name << " is going to the Vending Machine.\n" << endl;
    sleep(2);
}
void Store::goCashier(string name)
{
    cout << name << " is going to the cashier.\n" << endl;
    sleep(2);
}
void Store::leaveStore(string name)
{
    cout << endl;
    cout << name << " goes out of the store.\n" << endl;
    sleep(2);
}