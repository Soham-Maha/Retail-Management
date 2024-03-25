#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
    string name;
    int phoneNo;
};

class shop : public person
{
protected:
    int pCode;
    float price;
    string pName;

public:
    void menu();
    void admin();
    void buyer();
    void add();
    void edit();
    void remove();
    void enterDetails();
    void diplayList();
    void buy();
    void receipt();
};

void shop ::menu()
{
m:
    int choice;

    cout << "\t\t\t\t_____________________________________________________\n";
    cout << "\t\t\t\t|                                                    |\n";
    cout << "\t\t\t\t|             Retail Management Menu                 |\n";
    cout << "\t\t\t\t|                                                    |\n";
    cout << "\t\t\t\t|____________________________________________________|\n";
    cout << "\t\t\t\t|                                                    |\n";
    cout << "\t\t\t\t|     1)Admin                                        |\n";
    cout << "\t\t\t\t|                                                    |\n";
    cout << "\t\t\t\t|     2)Buyer                                        |\n";
    cout << "\t\t\t\t|                                                    |\n";
    cout << "\t\t\t\t|     3)Exit                                         |\n";
    cout << "\t\t\t\t|____________________________________________________|\n";

    cout << "\t\t\t\t Please select option(1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        admin();
        break;
    }

    case 2:
    {
        buyer();
        break;
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "\t\t\t\t Please Enter a valid option. ";
    }
    }

    goto m;
}

void shop ::admin()
{
    int choice;

}

int main()
{

    return 0;
}