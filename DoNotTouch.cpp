#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
    int phoneNo;
    string name;
};

class product
{
protected:
    int pId;
    float price;
    string pName;
    float discount;
};

class admin : public person, public product
{
public:
    void menu();
    void add();
    void edit();
    void remove();
    void displayAll();
};

class buyer : public person{
    void menu();
    void search();
    void buy();
    void receipt();
    void displayAllProds();
    void del();
};