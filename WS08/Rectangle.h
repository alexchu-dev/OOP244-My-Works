/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
#include <iostream>
namespace sdds {
   class Retangle : public LblShape {
      int m_width = 0;
      int m_height = 0;
   public:
      Retangle();
      Retangle(char* label, int width, int height);
      void getSpecs(std::istream& istr);
      void draw(std::ostream& ostr) const;
   };

}
#endif