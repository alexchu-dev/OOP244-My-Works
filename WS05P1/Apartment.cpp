#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (isValid(number)
         && isValid(balance))
      {
         m_number = number;
         m_balance = balance;
      }
   }
   bool Apartment::isValid(int number)
   {
      return number >= 1000 && number <= 9999;
   }
   bool Apartment::isValid(double balance)
   {
      return balance >= 0;
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }
   Apartment::operator bool() const
   {
      return m_number >= 1000 && m_number <= 9999 && m_balance >= 0;
   }
   Apartment::operator int() const {
      return m_number;
   }
   Apartment::operator double() const {
      return m_balance;
   }
   bool Apartment::operator~() const {
      return m_balance == 0;
   }
   Apartment& Apartment::operator=(int number) {
      if (isValid(number)) {
         m_number = number;
      }
      return *this;
   }
   Apartment& Apartment::operator=(Apartment& swap) {
      if (isValid(swap.m_number) && isValid(swap.m_balance)) {
         Apartment temp = *this;
         m_number = swap.m_number;
         m_balance = swap.m_balance;
         swap.m_number = temp.m_number;
         swap.m_balance = temp.m_balance;
      }
      return *this;
   }
   Apartment& Apartment::operator+=(double addDouble) {
      if (isValid(m_number) && isValid(addDouble))
      {
         m_balance += addDouble;  
      }
      return *this;
   }
   Apartment& Apartment::operator-=(double subDouble) {
      if (isValid(m_number) && isValid(subDouble) && m_balance >= subDouble)
      {
         m_balance -= subDouble;
      }
      return *this;
   }
   Apartment& Apartment::operator<<(Apartment& move) {
      if (isValid(m_number) && isValid(move.m_number) && isValid(move.m_balance) && !(m_number==move.m_number))
      {
         m_balance += move.m_balance;
         move.m_balance = 0;
      }
      return *this;
   }
   Apartment& Apartment::operator>>(Apartment& move) {
      if (isValid(m_number) && isValid(move.m_number) && isValid(m_balance) && !(m_number == move.m_number))
      {
         move.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }
   
}