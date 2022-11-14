/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 14 Nov 2022
Section: NAA
*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
#include <iostream>
namespace sdds
{
   class LblShape : public Shape {
      char* m_label = nullptr;
   protected:
      const char* label()const;
   public:
      LblShape();
      LblShape(const char* label);
      ~LblShape();
      LblShape(const LblShape& src) = delete;
      LblShape& operator=(const LblShape& src) = delete;
      void getSpecs(std::istream& istr) const;
   };
}
#endif