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
   Rectangle::Rectangle() : LblShape()
   {
      m_width = 0;
      m_height = 0;
   }
   Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label)
   {
      if (height < 3 || width < strlen(label)+2) {
         m_width = 0;
         m_height = 0;
      }
      else {
         m_width = width;
         m_height = height;
      }
   }
   void Rectangle::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_width;
      istr.ignore(256, ',');
      istr >> m_height;
      istr.ignore(256, '\n');
   }
   void Rectangle::draw(std::ostream& ostr) const
   {
      if (m_width > 0 && m_height > 0 && label() != nullptr) {
         //First line
         ostr << "+";
         for (int i = 0; i < m_width-2; i++) {
            ostr << "-";
         }
         ostr << "+" << endl;
         //Second line
         ostr << "|";
         ostr.width(m_width - 2);
         ostr.fill(' ');
         ostr.setf(ios::left);
         ostr << label();
         ostr.unsetf(ios::left);
         ostr << "|"<< endl;
         //third line and so
         for (int i = 0; i < (m_height - 3);i++) {
            ostr << "|";
            ostr.width(m_width - 1);
            ostr.fill(' ');
            ostr << "|" << endl;
         }
         //Last line
         ostr << "+";
         for (int i = 0; i < m_width - 2; i++) {
            ostr << "-";
         }
         ostr << "+" << endl;
      }
   }
}
