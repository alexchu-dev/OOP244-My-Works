/******************************************************************************
//                    OOP244NAA - WS05 Part 2 @ Oct 16 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
   class Mark
   {
      int m_value = 0;
      bool m_invalid = 0;
   public:
      Mark();
      Mark(int);
      bool isValid(const int);
      operator bool()const;
      operator int()const;
      operator double()const;
      operator char()const;
      bool operator>(int)const;
      bool operator<(int)const;
      bool operator>=(int)const;
      bool operator<=(int)const;
      bool operator==(int)const;
      bool operator!=(int)const;
      Mark& operator++();
      Mark operator++(int);
      Mark& operator--();
      Mark operator--(int);
      bool operator~()const;
      Mark& operator=(int);
      Mark& operator+=(int);
      Mark& operator-=(int);
      Mark& operator<<(Mark&);
      Mark& operator>>(Mark&);
      int getMark()const { return m_value; }
   };
   Mark operator+(const Mark&, int);
   int operator+(int, const Mark&);
   Mark operator+(const Mark&, const Mark&);
   int operator+=(int&, const Mark&);
   int operator+=(const Mark&, int);
   int operator-=(int&, const Mark&);
   int operator-=(const Mark&, int&);
}
 

#endif // SDDS_MARK_H_