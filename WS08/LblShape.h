/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
#include <iostream>
namespace sdds
{
   class LblShape : public Shape {
      char* m_label;
   protected:
      const char* label()const;
   public:
      LblShape();
      LblShape(const char* label);
      ~LblShape();
      LblShape(const LblShape& src) = delete;
      LblShape& operator=(const LblShape& src) = delete;
      void getSpecs(std::istream& istr);
   };
}
#endif