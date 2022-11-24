/******************************************************************************
//                    OOP244NAA - WS09 @ 22 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HtmlText.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   HtmlText::HtmlText(char* title)
   {
      delete[] m_title;
      if (title != nullptr)
      {
         m_title = new char[ut.strlen(title) + 1];
         ut.strcpy(m_title, title);
      }
      else {
         m_title = nullptr;
      }
   }
   HtmlText::~HtmlText()
   {
      delete[] m_title;
   }
   HtmlText::HtmlText(const HtmlText& src)
   {
   }
   HtmlText& HtmlText::operator=(const HtmlText& src)
   {
      // TODO: insert return statement here
   }
   std::ostream& HtmlText::write(std::ostream& ostr) const
   {
      // TODO: insert return statement here
   }
}
