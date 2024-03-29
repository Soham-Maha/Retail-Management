
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

void shop ::receipt() {
  int arrPcode[100];
  int arrPQuantity[100];
  int counter = 0;
  float amount = 0;
  int bProducts;
  cout << "kindly enter the total no of different products";
  cin >> bProducts;

  for (int i = 0; i < bProducts; i++) {
    cout << "enter product code";
    cin >> arrPcode[i];
    cout << "enter product quantity";
    cin >> arrPQuantity[i];
  }
  for (int i = 0; i < bProducts; i++) {
    if (arrPcode[i] == pCode[i]) {
      amount = amount + arrPQuantity[i] * price;
    }
  }
  cout << "\n\n\t\t\t\t  RECEIPT";
  cout << "=================================================";
  cout << "\n\n\t\t\t\t\t\t\t\t";
  cout << "\n\n\n";
  auto currentTime =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << "Time and Date: " << std::ctime(&currentTime);
  cout << "\n\n\n";

  cout << "\t\t  SNO.  \t\t  PRODUCT  \t\t  QUANTITY                \t\t  "
          "PRICE\n\n";

  for (int i = 0; i <= bProducts; i++) {
    cout << " \t\t " << i + 1 << "  \t\t  " << pName << " \t\t "
         << arrPQuantity[i] << " \t\t " << arrPQuantity[i] * price << "\n";
  }
  cout << "\n\n";
  cout << "\t\t"
       << "Your total amount is:  " << amount;
}