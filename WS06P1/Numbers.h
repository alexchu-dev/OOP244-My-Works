/******************************************************************************
//                    OOP244NAA - WS06 Part 1 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <fstream>
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
      Numbers& sort(bool);
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers&);
      Numbers& operator=(const Numbers&);
      Numbers operator-()const;
      Numbers operator+()const;
      Numbers& operator+=(double);
      double average()const;
      double max()const;
      double min()const;
      int numberCount()const;
      bool load();
      void save();
      std::ostream& display(std::ostream& ostr) const;
      ~Numbers();
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

