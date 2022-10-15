#pragma once
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
   };
   double operator+(const Apartment&, const Apartment&);
}

#endif // SDDS_APARTMENT_H_