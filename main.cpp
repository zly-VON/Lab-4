#include "Object.h"
#include "Store.h"
#include "People.h"
#include "Customer.h"
#include "Employee.h"
#include "Item.h"
#include "Food.h"
#include "Drink.h"
#include <ctime>
#include <iostream>
using namespace std;

int randNumber(int min, int max)
{
    int randomNumber;
    randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int main(void)
{
    srand(time(NULL));
    system("clear");

    int customerNr = 10;
    int employeeNr = 5;
    int foodNr = 12;
    int drinkNr = 8;
    int restock = 1;

    Store store;
    store.setName("Random Store");
    store.setDate("12.03.1998");
    store.Welcome();

    Customer customer, customers[customerNr];
    for (int i = 0; i < customerNr; i++)
    {
        customer.readCustomerData(i);
        customers[i].setName(customer.getName());
        customers[i].setDate(customer.getDate());
        customers[i].setLastName(customer.getLastName());
        customers[i].setCheque(customer.getCheque());
        customers[i].setBalance(customer.getBalance());
        customers[i].setSum(customer.getSum());
        customers[i].setAge(customer.getAge());
        customers[i].setNrItems(0);
    }

    Employee employee, employees[employeeNr];
    for (int i = 0; i < employeeNr; i++)
    {
        employee.readEmployeeData(i);
        employees[i].setName(employee.getName());
        employees[i].setDate(employee.getDate());
        employees[i].setLastName(employee.getLastName());
        employees[i].setAge(employee.getAge());
        employees[i].setWorkAges(employee.getWorkAges());
        employees[i].setRole(employee.getRole());
    }

    Food food, foods[foodNr];
    for (int i = 0; i < foodNr; i++)
    {
        food.readFoodData(i);
        foods[i].setName(food.getName());
        foods[i].setDate(food.getDate());
        foods[i].setPrice(food.getPrice());
        foods[i].setMass(food.getMass());
        foods[i].setQuantity(food.getQuantity());
    }
    
    Drink drink, drinks[drinkNr];
    for (int i = 0; i < drinkNr; i++)
    {
        drink.readDrinkData(i);
        drinks[i].setName(drink.getName());
        drinks[i].setDate(drink.getDate());
        drinks[i].setPrice(drink.getPrice());
        drinks[i].setVolume(drink.getVolume());
        drinks[i].setQuantity(drink.getQuantity());
    }

    for (int i = 0; i < customerNr; i++)
    {
        system("clear");
        customers[i].enterStore();
        customers[i].checkBalance();
        int times = randNumber(1, 4);

        while (times--)
        {
            system("clear");
            int option = randNumber(1, 5);
            int nr = 0;

            switch (option)
            {
                case 1:
                    store.goMainStore(customers[i].getName());
                    nr = randNumber(0, 4);
                    foods[nr].wantedItem();
                    foods[nr].Description();
                    if (foods[nr].checkQuantity())
                    {
                        foods[nr].takeItem();
                        customers[i].addSum(foods[nr].getPrice());
                        customers[i].setNrItems(customers[i].getNrItems() + 1);
                    }
                    else foods[nr].noItem();
                break;

                case 2:
                    store.goFishmonger(customers[i].getName());
                    if (employees[2].workerBreak(randNumber(1, 100)))
                    {
                        nr = randNumber(5, 7);
                        foods[nr].wantedItem();
                        foods[nr].Description();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            customers[i].addSum(foods[nr].getPrice());
                            customers[i].setNrItems(customers[i].getNrItems() + 1);
                        }
                        else foods[nr].noItem();
                    }
                break;

                case 3:
                    store.goButcher(customers[i].getName());
                    if (employees[1].workerBreak(randNumber(1, 100)))
                    {
                        nr = randNumber(8, 11);
                        foods[nr].wantedItem();
                        foods[nr].Description();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            customers[i].addSum(foods[nr].getPrice());
                            customers[i].setNrItems(customers[i].getNrItems() + 1);
                        }
                        else foods[nr].noItem();
                    }
                break;

                case 4:
                    store.goDrinkSection(customers[i].getName());
                    nr = randNumber(0, 4);
                    drinks[nr].wantedItem();
                    drinks[nr].Description();
                    if (drinks[nr].checkQuantity())
                    {
                        drinks[nr].takeItem();
                        customers[i].addSum(drinks[nr].getPrice());
                        customers[i].setNrItems(customers[i].getNrItems() + 1);
                    }
                    else drinks[nr].noItem();
                break;

                case 5:
                    store.goVendingMachine(customers[i].getName());
                    nr = randNumber(5, 7);
                    drinks[nr].wantedItem();
                    if (drinks[nr].checkQuantity())
                    {
                        drinks[nr].takeItem();
                        customers[i].payHotDrink(drinks[nr].getPrice());
                        customers[i].setNrItems(customers[i].getNrItems() + 1);
                    }
                    else drinks[nr].noItem();
                break;

                default:
                    cout << "ERROR! Closing Simulation" << endl;
                    sleep(2);
                    return 0;
                break;
            }
        }

        system("clear");
        if (customers[i].getBalance() >= customers[i].getSum())
        {
            if (randNumber(1, 100) < 90 && customers[i].getSum() != 0)
            {
                store.goCashier(customers[i].getName());
                employees[0].Intro();
                employees[0].sayTotalSum(customers[i].getSum());
                if (employee.checkDiscount(customers[i].getNrItems()))
                {
                    customers[i].receiveDiscount();
                    employees[0].sayTotalSum(customers[i].getSum());
                }
                customers[i].Payment();
                customers[i].setCheque(employees[0].changeCheque(customers[i].getCheque()));
                customers[i].setSum(0);
            }

            system("clear");
            if (randNumber(1, 100) < 30)
            {
                employees[3].Intro();
                employees[3].chequeRequest();
                customers[i].showCheque();
                if (!employees[3].checkCheque(customers[i].getSum(), customers[i].getCheque()))
                {
                    system("clear");
                    store.goCashier(customers[i].getName());
                    employees[0].Intro();
                    employees[0].sayTotalSum(customers[i].getSum());
                    if (employee.checkDiscount(customers[i].getNrItems()))
                    {
                        customers[i].receiveDiscount();
                        employees[0].sayTotalSum(customers[i].getSum());
                    }
                    customers[i].Payment();
                    customers[i].setCheque(employees[0].changeCheque(customers[i].getCheque()));
                    customers[i].setSum(0);
                }
            }
        }
        else 
        {
            store.goCashier(customers[i].getName());
            employees[0].Intro();
            employees[0].sayTotalSum(customers[i].getSum());
            employees[0].cannotPay();
        }

        store.leaveStore(customers[i].getName());

        system("clear");
        if (restock != 0 && randNumber(1, 100) < 20)
        { 
            employees[4].Intro();
            employees[4].announceRestock();
            for (int i = 0; i < foodNr; i++)
                foods[i].Restock(10);
            for (int i = 0; i < drinkNr; i++)
                drinks[i].Restock(10);
            employees[4].SuccessfulRestock();
            restock--;
        }
    }

    return 0;
}
