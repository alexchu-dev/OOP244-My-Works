
/******************************************************************************
//                    OOP244NAA - WS05 Part 1 @ Oct 14 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      bool isValid(int);
      bool isValid(double);
      std::ostream& display()const;
      bool operator~()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      Apartment& operator=(int);
      Apartment& operator=(Apartment&);
      Apartment& operator+=(double);
      Apartment& operator-=(double);
      Apartment& operator<<(Apartment&);
      Apartment& operator>>(Apartment&);
      int getNumber()const { return m_number; }
      double getBalance()const { return m_balance; }
   };
   double operator+(const Apartment&, const Apartment&);
   double operator+=(double&, const Apartment&);
}

#endif // SDDS_APARTMENT_H_