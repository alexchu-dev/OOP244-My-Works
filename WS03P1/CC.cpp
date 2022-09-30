/*
*****************************************************************************
                    OOP244NAA - WS03 Part 1 @ Sep 28 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assdignments.
*****************************************************************************
*/
#include <iostream>
#include <cmath>
#include "CC.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   /********************Below are private methods********************/
   /*This Private function validates the credit card information as follows:
      name: should not be null and should be more than 2 characters long
      cardNo : values between 4000000000000000 and 4099999999999999
      cvv : a three - digit number
      expMon : values between 1 and 12
      expYear : values between 22 and 32
      return true if all the conditions are met, otherwise it will return false */
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      return name != nullptr && strlen(name) > 2 && cardNo >= 4000000000000000 && cardNo <= 4099999999999999 && int(log10(cvv) + 1) == 3 && expMon >= 1 && expMon <= 12 && expYear >= 22 && expYear <= 32;
   }
   //This function prints a 16-digit number in a set of 4-digit numbers separated by spaces, eg 4098 6453 7564 6543. Use division and modulus operations. Divide by 1000000000000 to get the left four digits and print it. Then extract the right 12 digits by using modulus and repeat.
   void CC::prnNumber() const {
      long long cardNo = m_ccNum;
      const int setNum = 4;
      long long ccard[setNum] = {};
      for (int i = 0; i < setNum; i++) {
         long long base = (pow(10000, setNum - 1 - i));
         ccard[i] = cardNo / base;
         cardNo = cardNo % base;
         cout.width(4);
         cout.fill('0');
         cout << ccard[i];
         if (i < setNum-1){
            cout << " ";
         }
      }
      /*Alternative way to avoid using int array and fewer line:
      for (int i = 0; i < 16; i++) {
         cout << (cardNo / (1000000000000000/long(pow(10,i))) % 10);
         if ((i+1) % 4 == 0)
         cout << " ";
      }
      */
   }

   /********************Below are public methods********************/
   //Sets the object to a safe empty state by setting all the values to zero and nullptr.
   void CC::set() {
      m_name = nullptr;
      m_cvv = m_expMon = m_expYear = m_ccNum = 0;
   }
   //Deallocate the cardholder's name and then calls the set() to set the object to a safe empty state.
   void  CC::cleanUp() {
      delete[] m_name;
      m_name = nullptr;
   }
   //Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is nullptr, otherwise, it will return false.
   bool  CC::isEmpty() const {
      return m_name == nullptr;
   }
   //First, it will cleanUp() the object. Then if all the arguments are valid using validate(), it will dynamically keep a copy of the name in the name attribute and set the rest of the attributes to their corresponding values. If any of the arguments are invalid, nothing will be set.
   void  CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      cleanUp();
      if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
         m_name = new char[strlen(cc_name) + 1];
         strcpy(m_name, cc_name);
         m_cvv = cvv;
         m_expMon = expMon;
         m_expYear = expYear;
         m_ccNum = cc_no;
      }
   }
   //Assuming that the names are not longer than 70 characters, this function will attempt to read all the values from the console in local (function scope) variables first and if successful, they will be validated and then stored in the object. The function will return true if the values are stored in the object and false otherwise.
   bool  CC::read() {
      bool ret;
      /*bool done = false;*/
      char* cc_name = nullptr;
      cc_name = new char[71] ;
      unsigned long long cc_no;
      short cvv, expMon, expYear;
      cleanUp();
      cout << "Card holder name: ";
      cin.getline(cc_name, 71, '\n');
      if (cin) cout << "Credit card number: ";
      cin >> cc_no;
      if (cin) cout << "Card Verification Value (CVV): ";
      cin >> cvv;
      if (cin) cout << "Expiry month and year (MM/YY): ";
      /*while (!done) {*/
      cin >> expMon;
      if (cin) cin.ignore(1);
      cin >> expYear;
      if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      /*cout << "Invalid input, try again!" << endl;*/
      }
      else {
      set(cc_name, cc_no, cvv, expMon, expYear);
      /*done = true;*/
      cin.clear();
      }
      /*}*/
      delete[] cc_name;
      ret = !isEmpty();
      return ret;
   }

   //Display the object, if isEmpty() output invalid text. If it is not in safe empty state, print out depending if the row is 0 or greater. Print the row in specific format.
   void  CC::display(int row) const {
      if (isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      }
      else if (row > 0) {
         char* tempName = nullptr;
         tempName = new char[71];
         if (strlen(m_name) > 30) {
            strcpy(tempName, m_name, 30);
         }
         else {
            strcpy(tempName, m_name);
         }
         cout << "| ";
         cout.width(3);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << row;
         cout.unsetf(ios::right);
         cout << " | ";
         cout.width(30);
         cout.fill(' ');
         cout.setf(ios::left);
         cout << tempName;
         cout.unsetf(ios::left);
         cout << " | ";
         prnNumber();
         cout << " | ";
         cout.width(3);
         cout.fill(' ');
         cout << m_cvv;
         cout << " | ";
         cout.width(2);
         cout.fill(' ');
         cout.setf(ios::right);
         cout << m_expMon;
         cout.unsetf(ios::right);
         cout << "/";
         cout << m_expYear;
         cout << " |" << endl;
         delete[] tempName;
         tempName = nullptr;
      }
      else {
         cout << "Name: " << m_name << endl;
         cout << "Creditcard No: ";
         prnNumber();
         cout << endl;
         cout << "Card Verification Value: " << m_cvv << endl;
         cout << "Expiry Date: " << m_expMon << "/" << m_expYear << endl;
      }
   }
}