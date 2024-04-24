#include<iostream>
#include<fstream>
#include<string>
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
    float price;
    string pname; // name of the product
    int quantity;


public:
    virtual void menu() = 0; // Make menu a pure virtual function, ensuring subclasses implement it

    // Methods common to all users
    virtual void list() {
        fstream data;
        data.open("database.txt", ios::in);
        cout << "\n\t\t\t\t________________________________________________________________________\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|Product No. \t  Name \t\t Price \t\t quantity               |\n";
        cout << "  \t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|_______________________________________________________________________|\n";
        data >> pcode >> pname >> price >> quantity;

        while (!data.eof()) {
            cout << "\t\t\t\t   " << pcode << "\t\t" << pname << "\t\t " << price << "\t\t" << quantity << "\n";
            data >> pcode >> pname >> price >> quantity; // for iteration purpose
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
        cout << "  \t\t\t\t________________________________________________________________________\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|                        Administrator Menu                             |\n";
        cout<<  "  \t\t\t\t|_______________________________________________________________________|\n";
        cout << "  \t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        1) Add new product                             |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        2) Modify the product                          |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        3) Remove product                              |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        4) List products                               |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        5) Back to Main menu                           |";
        cout << "\n\t\t\t\t|_______________________________________________________________________|";


        cout << endl;

        cout << "\n\t\t\t\t  Please Enter your choice: ";

        while (choice != 5) {
            cin >> choice;

            switch (choice) {
                case 1:
                    add(); // to add a new product
                    cout << "\n\t\t\t\tIf you wish to continue choose again, else press 5" << endl;

                    break;
                case 2:
                    edit(); // to modify or edit the existing product
                    cout << "\n\t\t\t\tIf you wish to continue choose again, else press 5" << endl;
                    break;
                case 3:

                    remove(); // to remove the product
                    cout << "\n\t\t\t\tIf you wish to continue choose again, else press 5" << endl;
                    break;
                case 4:
                    list(); // to list products
                    cout << "\n\t\t\t\tIf you wish to continue choose again, else press 5" << endl;
                    break;
                case 5:


                    return;// exit the menu
                default:
                    cout << "\n\t\t\t\t  Invalid Choice!!" << endl;

            }
        }
    }

    void add() {
        fstream data;
        int c;
        int token = 0;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t\t  Add new product  ";
        cout << "\n\n\t\t\t\t  Enter Product code: ";
        cin >> pcode;
        cout << "\n\n\t\t\t\t  Name of the Product: ";
        cin >> pname;
        cout << "\n\n\t\t\t\t  Price of the Product: ";
        cin >> price;
        cout << "\n\n\t\t\t\t  Quantity of the Product: ";
        cin >> quantity;

        data.open("database.txt", ios::in);

        if (!data) {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << quantity << "\n";
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
                cout << "\n\t\t\t\t  Product already exists!" << endl;
            } else {
                data.open("database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << quantity << "\n";
                data.close();
                cout << "\n\t\t\t\t  Record Inserted Successfully!" << endl;
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

        cout << "\n\t\t\t\t  Modify the Product";
        cout << "\n\t\t\t\t  Enter Product Code: ";
        cin >> pkey;

        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\n\n\t\t\t\t  File doesn't Exist!";
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> quantity;

            while (!data.eof()) {
                if (pkey == pcode) {
                    cout << "\n\t\t\t\t  Enter new Product Code: ";
                    cin >> c;
                    cout << "\n\t\t\t\t  Enter new Name of the Product: ";
                    cin >> n;
                    cout << "\n\t\t\t\t  Enter new Price: ";
                    cin >> p;
                    cout << "\n\t\t\t\t  Enter new Quantity: ";
                    cin >> q;

                    data1 << " " << c << " " << n << " " << p << " " << q << "\n";
                    cout << "\n\n\t\t\t\t  Record Edited!";
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
                cout << "\n\n\t\t\t\t  Record not found!";
            }
        }
    }

    void remove() {
        fstream data, data1;
        int pkey;
        int token = 0;

        cout << "\n\n\t\t\t\t  Delete Product ";
        cout << "\n\n\t\t\t\t  Product code: ";
        cin >> pkey;

        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\t\t\t\t  File doesn't Exist" << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> quantity;

            while (!data.eof()) {
                if (pcode == pkey) {
                    cout << "\n\n\t\t\t\t  Product deleted Successfully ";
                    token++;
                } else {
                    data1 << " " << pcode << " " << pname << " " << price << " " << quantity << "\n";
                }
                data >> pcode >> pname >> price >> quantity;
            }

            data.close();
            data1.close();

            ::remove("database.txt");
            rename("database1.txt", "database.txt");

            if (token == 0) {
                cout << "\n\t\t\t\t  Record Not found" << endl;
            }
        }
    }
};

class Buyer : public Shopping {
public:
    void menu() override {
        int choice;
        cout << "  \t\t\t\t_________________________________________________________________________\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|                              Buyer Menu                               |\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|_______________________________________________________________________|\n";
        cout << "  \t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                         1) Buy Product                                |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                         2) Go back                                    |\n";
        cout<<  "  \t\t\t\t|                                                                       |\n";
        cout<<  "  \t\t\t\t|                         3) Customer Care                              |\n";
        cout << "  \t\t\t\t|_______________________________________________________________________|";
        cout << endl;

        cout << "\t\t\t\tEnter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:

                return; // exit the menu
            case 3:
                 cc_menu();
                break;
            default:
                cout << "\t\t\t\t  Invalid Choice!!" << endl;
        }
    }
    void cc_menu(){
        string prod;
        int quant;
        cout << "  \t\t\t\t________________________________________________________________________\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|                        Customer Care Menu                             |\n";
        cout<<  "  \t\t\t\t|_______________________________________________________________________|\n";
        cout << "  \t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        1) Unsatisfied with the Product                |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        2) Expired Product                             |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        3) Order a Product in Bulk                     |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        4) Other Issues                                |";
        cout << "\n\t\t\t\t|                                                                       |";
        cout << "\n\t\t\t\t|                        5) Go Back                                     |";
        cout << "\n\t\t\t\t|_______________________________________________________________________|\n";
        int choice;
        cout<<"\t\t\t\tEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"\t\t\t\t\t\tThis is the Store number:9875xxxxxx.\n\t\t\t\tOr contact us at this email xxxxxyy@gmail.com\n\t\t\t\tFeel free to submit your query.\n\t\t\t\tYour response is valuable to us."<<endl;
                return;
            case 2:
                cout<<"\t\t\t\tKindly attach a pic of the expiry date with the bill , your address.\n\t\t\t\tSend the email at xxxxxyy@gmail.com . We will send a replacement immediately.\n\t\t\t\tSorry for the inconvenience. ";
                return;
            case 3:
                cout<<"\t\t\t\tKindly enter the name of the product:"<<endl;
                cin>>prod;
                cout<<"\t\t\t\tkindly enter the quantity:";
                cin>>quant;
                cout<<"\t\t\t\tYou will be notified as soon the order will arrive.";
                return;
            case 4:
                cout<<"\t\t\t\tFor other issues kindly meet the cc executive at the nearby store";
                return;
            case 5:
                this->menu();
            default:
                cout<<"Invalid Choice";
        }
    }

    void receipt() {
        fstream data, data2;
        int arrc[100]; // to hold the code of the various products
        int arrq[100]; // to hold the quantity of each product

        string choice;
        int c = 0; // counter
        float amount;

        bool found = false;

        float total = 0;

        cout << "\n\t\t\t\t________________________________________________________________________\n";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|                         List Of Products                              |\n ";
        cout << "  \t\t\t\t|                                                                       |\n";
        cout << "  \t\t\t\t|_______________________________________________________________________|\n";

        data.open("database.txt", ios::in);

        if (!data) {
            cout << "\n\n\t\t\t\t  Empty database" << endl;
            return;
        } else {
            data.close();
            list(); // display the list of products

            cout << "\n\t\t\t\t__________________________________________________";
            cout << "\n\t\t\t\t|                                                 |";
            cout << "\n\t\t\t\t|            Please place your order              |";
            cout << "\n\t\t\t\t|                                                 |";
            cout << "\n\t\t\t\t|_________________________________________________|\n";

            do {
                cout << "\n\n\t\t\t\t  Enter Product Code: ";
                cin >> arrc[c];
                data.open("database.txt", ios::in);


                while (!data.eof()) {
                    data >> pcode >> pname >> price >> quantity;
                    if (pcode == arrc[c]) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\n\n\t\t\t\t  Product not found. Please refer to inventory and try later.";

                    return;
                }

                data.close();


                cout << "\n\n\t\t\t\t  Enter the product Quantity: ";
                cin >> arrq[c];

                if (arrq[c] > quantity) {
                    cout << "\n\n\t\t\t\t  Required quantity not in stock. Please try again later.";
                    return;
                }


                for (int i = 0; i < c; i++) {
                    if (arrc[c] == arrc[i]) {
                        cout << "\n\n\t\t\t\t  Duplicate Product Code. Please try again: ";
                        return;
                    }
                }
                c++;

                cout << "\n\n\t\t\t\t  Do you want to buy another product? (y/n): ";
                cin >> choice;
            } while (choice == "y" || choice == "Y");

            cout << "\t\t\t\t________________________________________________________________________\n";
            cout << "\t\t\t\t|                                                                       |\n";
            cout << "\t\t\t\t|                                 RECEIPT                               |\n";
            cout << "\t\t\t\t|                                                                       |\n";
            cout << "\t\t\t\t|_______________________________________________________________________|\n";

            cout << "\n\t\t\t\t Product No.\t Product Name\t Product quantity\t Price\t Amount\n";

            for (int i = 0; i < c; i++) {
                data.open("database.txt", ios::in );
                data2.open("database2.txt", ios::app);

                while (data >> pcode >> pname >> price >> quantity) {

                    if (pcode == arrc[i]) {
                        quantity -= arrq[i];
                        amount = price * arrq[i];
                        total += amount;

                        cout << "\n\t\t\t\t  " << pcode << "\t\t  " << pname << "\t\t     " << arrq[i] << "\t\t\t " << price
                             << "\t     " << amount;
                    }
                    data2 << pcode << " " << pname << " " << price << " " << quantity << "\n";

                }

                data.close();
                data2.close();

                ::remove("database.txt");
                rename("database2.txt", "database.txt");
            }

            cout << "\n\n\t\t\t\t________________________________________________________________________";
            cout << "\n\t\t\t\t  Total Amount: " << total << endl;
            cout << "\n";
            cout << "\t\t\t\tThank You For Shopping With Us!";
        }
    }
};

class Supermarket {
public:
    void mainMenu() {
        int choice;
        string email;
        string password;

        cout << "\t\t\t\t_________________________________________________________________________________\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|                              Supermarket Main Menu                             |\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|________________________________________________________________________________|\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|                        (1) Administrator                                       |\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|                        (2) Buyer                                               |\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|                        (3) Exit                                                |\n";
        cout << "\t\t\t\t|                                                                                |\n";
        cout << "\t\t\t\t|________________________________________________________________________________|";

        cout << endl;
        cout << "\t\t\t\t  Please Select: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\t\t\t\t  Please Login\n";
            cout << "\t\t\t\t  Enter Your Email: ";
            cin >> email;
            cout << "\t\t\t\t    Enter Password: ";
            cin >> password;

            if (email == "admin@gmail.com" && password == "admin@101") {
                Administrator admin;
                admin.menu();
            } else {
                cout << "\t\t\t\tInvalid Email or Password!\n\t\t\t\tTry again\n";
                this->mainMenu();

            }
        } else if (choice == 2) {
            Buyer buyer;
            buyer.menu();
        } else if (choice == 3) {
            exit(0);
        } else {
            cout << "\t\t\t\t  Please select from the given options\n";
            this->mainMenu();
        }
    }
};

int main() {
    Supermarket supermarket;
    supermarket.mainMenu();

    return 0;
}
