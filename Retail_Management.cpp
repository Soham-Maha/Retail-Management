// Pick up any one of the functions and start editing if you feel necessary

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
    float dis;

public:
    void menu();         // Main Menu
    void admin();        // Menu For the Admin
    void buyer();        // Menu For the Buyer
    void add();          // Add Products in the Store
    void edit();         // Edit Number of Products in the Store
    void remove();       // Remove Products in the Store
    void enterDetails(); // Enter User Details(Name and Phone Number)
    void diplayList();   // Enter the Products available for the Customer to buy
    void buy();          // Function for the Customer to add products to the cart and later buy it
    void receipt();      // Print a receipt for all the products bought

    // Add any function if required
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
m:
    int choice;
    cout << "\t\t\t\t_____________________________________________________\n";
    cout << "\n\n\t\t\t     Admin Menu\n";
    cout << "\t\t\t\t_____________________________________________________\n";
    cout << "\t\t\t    1)Add the Product\n";
    cout << "\t\t\t    2)Modify the Product\n";
    cout << "\t\t\t    3)Delete the Product\n";
    cout << "\t\t\t    4)Back to main menu\n";

    cout << "\t\t\t\t Please select option(1-4): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }

    case 2:
    {
        edit();
        break;
    }

    case 3:
    {
        remove();
        break;
    }
    case 4:
    {
        menu();
    }

    default:
    {
        cout << "\t\t\t\t Please Enter a valid option. ";
    }
    }

    goto m;
}
void shop::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t_____________________________________________________\n";
    cout << "\n\n\t\t\t     Buyer Menu\n";
    cout << "\t\t\t\t_____________________________________________________\n";
    cout << "\t\t\t    1)Buy the Product\n";
    cout << "\t\t\t    2)Back to main menu\n";

    cout << "\t\t\t\t Please select option(1-2): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }

    case 2:
    {
        menu();
        break;
    }

    default:
    {
        cout << "\t\t\t\t Please Enter a valid option. ";
    }
    }
    goto m;
}

void shop ::add()
{
    //fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add New Product";
    cout << "\n\n\t Product code of the product";
    cin >> pCode;
    cout << "\n\n\t  Name of the product ";
    cin >> pName;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on product";
    cin >> dis;
}

int main()
{

    return 0;
}
