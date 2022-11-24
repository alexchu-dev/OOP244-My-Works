/******************************************************************************
//                    OOP244NAA - WS09 @ 22 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText : public Text {
      char* m_title = nullptr;
   public:
      HtmlText() {};
      HtmlText(char* title);
      ~HtmlText();
      HtmlText(const HtmlText& src);
      HtmlText& operator=(const HtmlText& src);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}
#endif // !SDDS_HTMLTEXT_H_
