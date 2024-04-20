#include<iostream>
#include<fstream>
/*In the updated code:

The Shopping class is now an abstract base class with a pure virtual method menu() that is overridden by
Administrator and Buyer classes.
Administrator and Buyer classes are derived from the Shopping class.
The Administrator and Buyer classes provide their own implementations of the menu() method, as well as
specialized methods for adding, editing, removing products, and generating receipts.
A new class Supermarket handles the main menu, instantiating and managing the appropriate objects for
administrators and buyers based on the user's choice.
This separation of responsibilities and use of inheritance and polymorphism improves code organization
and maintainability.
*/

using namespace std;

class Shopping {
protected:
    int pcode; // product code
    float price ;
    float dis ; // discount
    string pname; // name of the product
    int quantity;


public:
    virtual void menu() = 0; // Make menu a pure virtual function, ensuring subclasses implement it

    // Methods common to all users
    virtual void list() {
        fstream data;
        data.open("database.txt", ios::in);

        cout << "\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
        cout << "\t\t\t\t\t\t  Product No. \t  Name \t\t Price \t\t quantity \n";
        cout << "\n\n\t\t\t\t\t\t|____________________________________________________________________|\n";
        data >> pcode >> pname >> price >> quantity;

        while (!data.eof()) {
            cout << "\t\t\t\t\t\t   " << pcode << "\t\t" << pname << "\t\t " << price << "\t\t"<<quantity<<"\n";
            data >> pcode >> pname >> price >>  quantity; // for iteration purpose
        }

        data.close();
    }
};

class Administrator : public Shopping {
public:
    // For administrators
    void menu() override {
        int choice;
        cout << endl;
        cout << "\t\t\t\t\t\t Administrator Menu \n";
        cout << "\n\t\t\t\t\t\t|__________1) Add new product_________________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________2) Modify the product______________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________3) Remove product__________________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________4) List products___________________|";
        cout << "\n\t\t\t\t\t\t|                                             |";
        cout << "\n\t\t\t\t\t\t|__________5) Back to Main menu_______________|";
        cout << endl;

        cout << "\n\t\t\t\t\t\t  Please Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(); // to add a new product
                break;
            case 2:
                edit(); // to modify or edit the existing product
                break;
            case 3:
                remove(); // to remove the product
                break;
            case 4:
                list(); // to list products
                break;
            case 5:
                return; // exit the menu
            default:
                cout << "\t\t\t\t\t\t  Invalid Choice!!" << endl;
        }
    }

    void add() {
        fstream data;
        int c;
        int token = 0;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t\t\t\t  Add new product  ";
        cout << "\n\n\t\t\t\t\t\t  Enter Product code: ";
        cin >> pcode;
        cout << "\n\n\t\t\t\t\t\t  Name of the Product: ";
        cin >> pname;
        cout << "\n\n\t\t\t\t\t\t  Price of the Product: ";
        cin >> price;
        cout << "\n\n\t\t\t\t\t\t  Discount on Product: ";
        cin >> dis;

        data.open("database.txt", ios::in);

        if (!data) {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        } else {
            data >> c >> n >> p >> d;

            while (!data.eof()) {
                if (c == pcode) {
                    token++;
                }
                data >> c >> n >> p >> d;
            }
            data.close();

            if (token == 1) {
                cout << "\n\t\t\t\t\t\t  Product already exists!" << endl;
            } else {
                data.open("database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                data.close();
                cout << "\n\t\t\t\t\t\t  Record Inserted Successfully!" << endl;
            }
        }
    }

    void edit() {
        fstream data, data1;
        int pkey;
        int token = 0;
        int c;
        float p;
        float q;
        string n;

        cout << "\n\t\t\t\t\t\t  Modify the Product";
        cout << "\n\t\t\t\t\t\t  Enter Product Code: ";
        cin >> pkey;

        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\n\n\t\t\t\t\t\t  File doesn't Exist!";
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof()) {
                if (pkey == pcode) {
                    cout << "\n\t\t\t\t\t\t  Enter new Product Code: ";
                    cin >> c;
                    cout << "\n\t\t\t\t\t\t  Enter new Name of the Product: ";
                    cin >> n;
                    cout << "\n\t\t\t\t\t\t  Enter new Price: ";
                    cin >> p;
                    cout << "\n\t\t\t\t\t\t  Enter new Quantity: ";
                    cin >> q;

                    data1 << " " << c << " " << n << " " << p << " " << q << "\n";
                    cout << "\n\n\t\t\t\t\t\t  Record Edited!";
                    token++;
                } else {
                    data1 << " " << pcode << " " << pname << " " << price << " " << q << "\n";
                }
                data >> pcode >> pname >> price >> q;
            }

            data.close();
            data1.close();

            ::remove("database.txt");
            rename("database1.txt", "database.txt");

            if (token == 0) {
                cout << "\n\n\t\t\t\t\t\t  Record not found!";
            }
        }
    }

    void remove() {
        fstream data, data1;
        int pkey;
        int token = 0;

        cout << "\n\n\t\t\t\t\t\t  Delete Product ";
        cout << "\n\n\t\t\t\t\t\t  Product code: ";
        cin >> pkey;

        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\t\t\t\t\t\t  File doesn't Exist" << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof()) {
                if (pcode == pkey) {
                    cout << "\n\n\t\t\t\t\t\t  Product deleted Successfully ";
                    token++;
                } else {
                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }

            data.close();
            data1.close();

            ::remove("database.txt");
            rename("database1.txt", "database.txt");

            if (token == 0) {
                cout << "\n\t\t\t\t\t\t  Record Not found" << endl;
            }
        }
    }
};

class Buyer : public Shopping {
public:
    void menu() override {
        int choice;
        cout << "\t\t\t\t\t\t  Buyer Menu \n";
        cout << "\n\t\t\t\t\t\t|______1) Buy Product_______|";
        cout << "\n\t\t\t\t\t\t|                           |";
        cout << "\n\t\t\t\t\t\t|______2) Go back___________|";
        cout << endl;

        cout << "\t\t\t\t\t\t  Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                return; // exit the menu
            default:
                cout << "\t\t\t\t\t\t  Invalid Choice!!" << endl;
        }
    }

    void receipt() {
        fstream data;
        int arrc[100]; // to hold the code of the various products
        int arrq[100]; // to hold the quantity of each product

        string choice;
        int c = 0; // counter
        float amount;
        float dis = 0;
        float total = 0;

        cout << "\n\n\t\t\t\t\t\t                          RECEIPT                      ";
        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\n\n\t\t\t\t\t\t  Empty database" << endl;
            return;
        } else {
            data.close();
            list(); // display the list of products

            cout << "\n\t\t\t\t\t\t__________________________________________________\n";
            cout << "\n\t\t\t\t\t\t|                                                 |\n";
            cout << "\n\t\t\t\t\t\t|            Please place your order              |\n";
            cout << "\n\t\t\t\t\t\t|                                                 |\n";
            cout << "\n\t\t\t\t\t\t__________________________________________________\n";

            do {
                cout << "\n\n\t\t\t\t\t\t  Enter Product Code: ";
                cin >> arrc[c];
                cout << "\n\n\t\t\t\t\t\t  Enter the product Quantity: ";
                cin >> arrq[c];


                for (int i = 0; i < c; i++) {
                    if (arrc[c] == arrc[i]) {
                        cout << "\n\n\t\t\t\t\t\t  Duplicate Product Code. Please try again: ";
                        return;
                    }
                }
                c++;

                cout << "\n\n\t\t\t\t\t\t  Do you want to buy another product? (y/n): ";
                cin >> choice;
            } while (choice == "y" || choice == "Y");

            cout << "\n\n\t\t\t\t\t\t_____________________________RECEIPT________________________\n";
            cout
                    << "\n\t\t\t\t\t\t Product No.\t Product Name\t Product quantity\t Price\t Amount\n";

            for (int i = 0; i < c; i++) {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> dis;

                while (!data.eof()) {
                    if (pcode == arrc[i]) {
                        amount = price * arrq[i];

                        total += amount;
                        cout << "\n\t\t\t\t\t\t  " << pcode << "\t\t  " << pname << "\t\t" << arrq[i] << "\t\t" << price
                             << "\t" << amount;
                    }
                    data >> pcode >> pname >> price >> dis;
                }

                data.close();
            }

            cout << "\n\n\t\t\t\t\t\t___________________________________________________________";
            cout << "\n\t\t\t\t\t\t  Total Amount: " << total << endl;
        }
    }
};

class Supermarket {
public:
    void mainMenu() {
        int choice;
        string email;
        string password;

        cout << "\t\t\t\t\t\t_________________________________________________________________________________\n";
        cout << "\t\t\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t\t\t|                              Supermarket Main Menu                             |\n";
        cout << "\t\t\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t\t\t|________________________________________________________________________________|\n";
        cout << endl;

        cout << "\t\t\t\t\t\t|                        (1) Administrator                     |\n";
        cout << "\t\t\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t\t\t|                        (2) Buyer                             |\n";
        cout << "\t\t\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t\t\t|                        (3) Exit                              |\n";
        cout << "\t\t\t\t\t\t|                                                              |\n";

        cout << endl;
        cout << "\t\t\t\t\t\t  Please Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\t\t\t\t\t\t  Please Login\n";
            cout << "\t\t\t\t\t\t  Enter Your Email: ";
            cin >> email;
            cout << "\t\t\t\t\t\t  Enter Password: ";
            cin >> password;

            if (email == "admin@gmail.com" && password == "admin@101") {
                Administrator admin;
                admin.menu();
            } else {
                cout << "\t\t\t\t\t\t  Invalid Email or Password!\n";
            }
        } else if (choice == 2) {
            Buyer buyer;
            buyer.menu();
        } else if (choice == 3) {
            exit(0);
        } else {
            cout << "\t\t\t\t\t\t  Please select from the given options\n";
        }
    }
};

int main() {
    Supermarket supermarket;
    supermarket.mainMenu();

    return 0;
}
