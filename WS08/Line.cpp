/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Line.h"
using namespace std;
namespace sdds {
   Line::Line() : LblShape()
   {
      m_length = 0;
   }
   Line::Line(char* label, int length) :LblShape(label) {
      m_length = length;
   }
   void Line::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_length;
      istr.ignore(256, '\n');
   }
   void Line::draw(std::ostream& ostr)
   {
      //TO-DO
   }
}
