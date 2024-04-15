#include <iostream>
#include <string>
using namespace std;

int takeInp(string prompt, int myVar) {
  cout << prompt;
  cin >> myVar;
  return myVar;
}

class Person {
protected:
  string name;
  int phoneNum;
};

class Shop : public Person {
protected:
  int pCode;
  float price;
  string pName;
  float disc;

public:
  void menu();
  void admin();
  void buyer();
};

void Shop ::menu() {
  int choice;

  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|             Retail Management Menu                 |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|____________________________________________________|\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     (1) Admin                                      |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     (2) Buyer                                      |\n";
  cout << "\t\t\t\t|                                                    |\n";
  cout << "\t\t\t\t|     (3) Exit                                       |\n";
  cout << "\t\t\t\t|____________________________________________________|\n\n";

  choice = takeInp("Please enter choice (1-3): ", choice);

  if (choice == 1) {
    admin();
  } else if (choice == 2) {
    buyer();
  } else if (choice == 3) {
  } else {
    cout << choice;
    cout << "Invalid option entered..." << endl << "Try again!" << endl;
    choice = takeInp("Please enter choice (1-3): ", choice);
  }
};

void Shop ::admin() {
  int choice;
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t\t|                     Admin Menu                    | \n";
  cout << "\t\t\t\t----------------------------------------------------- \n";
  cout << "\t\t\t\t(1) Add the Product                                   \n";
  cout << "\t\t\t\t(2) Modify the Product                                \n";
  cout << "\t\t\t\t(3) Delete the Product                                \n";
  cout << "\t\t\t\t(4) Back to main menu                                 \n";

  choice = takeInp("Please enter choice (1-4): ", choice);

  if (choice == 1) {
  } else if (choice == 2) {
  } else if (choice == 3) {
  } else if (choice == 4) {
  } else {
    cout << choice;
    cout << "Invalid option entered..." << endl << "Try again!" << endl;
    choice = takeInp("Please enter choice (1-4): ", choice);
  }
}

void Shop ::buyer() {
  int choice;
  cout << "\t\t\t\t_____________________________________________________\n";
  cout << "\t\t\t\t                     Buyer Menu                      \n";
  cout << "\t\t\t\t-----------------------------------------------------\n";
  cout << "\t\t\t\t(1) Buy the Product                                  \n";
  cout << "\t\t\t\t(2) Back to main menu                                \n";

  choice = takeInp("Please enter choice (1-2): ", choice);

  if (choice == 1) {
  } else if (choice == 2) {
  } else {
    cout << choice;
    cout << "Invalid option entered..." << endl << "Try again!" << endl;
    choice = takeInp("Please enter choice (1-2): ", choice);
  }
}

int main() {
  Shop s;
  s.menu();
  return 0;
}
