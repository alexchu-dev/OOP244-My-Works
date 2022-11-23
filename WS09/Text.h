/******************************************************************************
//                    OOP244NAA - WS09 @ 22 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>
#include <fstream>
namespace sdds {
   class Text {
      char* m_content = nullptr;
   protected:
      const char& operator[](int index)const;
   public:
      Text() {};
      ~Text() {};
      Text(const Text& src);
      Text& operator=(const Text& src);
      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& write(std::ostream& ostr = std::cout)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text& t);
   std::istream& operator>>(std::istream& istr, Text& t);
}
#endif // !SDDS_TEXT_H_
