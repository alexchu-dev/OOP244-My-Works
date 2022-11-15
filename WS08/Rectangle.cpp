/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Rectangle.h"
using namespace std;
namespace sdds {
   Retangle::Retangle() : LblShape()
   {
      m_width = 0;
      m_height = 0;
   }
   Retangle::Retangle(char* label, int width, int height) :LblShape(label)
   {
      if (m_height < 3 || m_width < strlen(label)+2) {
         m_width = 0;
         m_height = 0;
      }
      else {
         m_width = width;
         m_height = height;
      }
   }
   void Retangle::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_width;
      istr.ignore(256, ',');
      istr >> m_height;
      istr.ignore(256, '\n');
   }
   void Retangle::draw(std::ostream& ostr) const
   {
      LblShape::draw(ostr);
      if (m_width > 0 && m_height > 0 && label() != nullptr) {
         ostr << label() << "+";
         for (int i = 0; i < m_width-2; i++) {
            ostr << label() << "-";
         }
         ostr << "+" << endl;
      }
   }
}
