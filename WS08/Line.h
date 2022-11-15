/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"
#include <iostream>
namespace sdds 
{
   class Line : public LblShape {
      int m_length = 0;
   public:
      Line();
      Line(char* label, int length);
      void getSpecs(std::istream& istr);
      void draw(std::ostream& ostr) const;
   };
}
#endif