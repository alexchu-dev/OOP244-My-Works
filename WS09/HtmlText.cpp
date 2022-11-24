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
   HtmlText::HtmlText(const char* title)
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
      m_title = nullptr;
      *this = src;
   }
   HtmlText& HtmlText::operator=(const HtmlText& src)
   {
      if (this != &src) {
         delete[] m_title;
         if (src.m_title != nullptr) {
            m_title = new char[ut.strlen(src.m_title) + 1];
            ut.strcpy(m_title, src.m_title);
         }
         else {
            m_title = nullptr;
         }
         (Text&)*this = src;
      }
      return *this;
   }
   std::ostream& HtmlText::write(std::ostream& ostr) const
   {
      bool ms = false;
      int index = 0;
      ostr << "<html><head><title>";
      m_title != nullptr ? ostr << m_title : ostr << "No Title";
      ostr << "</title></head>\n<body>\n";
      if (m_title != nullptr) ostr << "<h1>" << m_title << "</h1>\n";
      while ((*this)[index] != 0) {
         char ch = (*this)[index];
         if (ch == ' ') {
            if (ms) ostr << "&nbsp;";
            else {
               ms = true;
               ostr << " ";
            }
         }
         else {
            if (ch == '<') ostr << "&lt;";
            else if (ch == '>') ostr << "&gt;";
            else if (ch == '\n') ostr << "<br />\n";
            else ostr << (*this)[index];
            ms = false;
         }
         index++;
      }
      ostr << "</body>\n</html>";
      return ostr;
   }
}
