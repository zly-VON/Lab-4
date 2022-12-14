#include "Customer.h"

void Customer::setCheque(string cheque) { Cheque = cheque; }
string Customer::getCheque() { return Cheque; }
void Customer::setBalance(double balance) { Balance = balance; }
double Customer::getBalance() { return Balance; }
void Customer::setSum(double sum) { Sum = sum; }
double Customer::getSum() { return Sum; }
void Customer::setNrItems(int nrItems) { NrItems = nrItems; }
int Customer::getNrItems() { return NrItems; }

void Customer::readCustomerData(int i)
{
    ifstream fileCustomer;
    fileCustomer.open("customerData.txt", ios::in);

    string ignore;
    int j = i * 7;
    while(j--) getline(fileCustomer, ignore);
    

    readPeopleData(fileCustomer);

    string cheque, balance, sum;
    getline(fileCustomer, cheque);
    setCheque(cheque);
    getline(fileCustomer, balance);
    setBalance(atof(balance.c_str()));
    getline(fileCustomer, sum);
    setSum(atof(sum.c_str()));
    getline(fileCustomer, ignore);

    fileCustomer.close();
}

void Customer::enterStore()
{
    cout << "Customer " << getName() << " has entered the store." << endl;
    sleep(2);
}
void Customer::checkBalance() 
{ 
    cout << getName() << " is checking the balance. Total = ";
    cout << Balance << "$." << endl;
    sleep(2);
}
void Customer::addSum(double price) { Sum = Sum + price; }
void Customer::payHotDrink(double price)
{
    Balance = Balance - price;
    cout << "\nNotification: " << price;
    cout << "$ have been substracted from the balance of the customer." << endl;
    cout << "Remaining balance: " << getBalance() << "$." << endl; 
    sleep(3);
}
void Customer::receiveDiscount()
{
    Sum = Sum * 90 / 100;
}
void Customer::Payment() 
{ 
    Balance = Balance - Sum; 
    cout << "\nNotification: " << Sum;
    cout << "$ have been substracted from the balance of the customer." << endl;
    cout << "Remaining balance: " << getBalance() << "$." << endl; 
    sleep(3);
}
void Customer::showCheque()
{
    cout << endl;
    cout << getName() << " shows the cheque" << endl;
    cout << "+-------------+" << endl;
    if (Cheque == "Paid") cout << "|    " << Cheque << "     |" << endl;
    else cout << "|   " << Cheque << "   |" << endl;
    cout << "+-------------+" << endl;
    sleep(2);
}