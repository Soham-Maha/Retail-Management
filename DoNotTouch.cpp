#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int phoneNo;
    string name;
};

class Product
{
protected:
    int pId;
    float price;
    string pName;
    float discount;
};

class Admin : public Person, public Product
{
public:
    void menu();
    void add();
    void edit();
    void remove();
    void displayAll();
};

class Buyer : public Person{
    void menu();
    void search();
    void buy();
    void receipt();
    void displayAllProds();
    void del();
};