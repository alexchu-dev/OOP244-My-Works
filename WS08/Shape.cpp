/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Shape.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& ostr, const Shape& S)
   {
      S.draw(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, Shape& S)
   {
      S.getSpecs(istr);
      return istr;
   }
}
