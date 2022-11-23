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
using namespace std;
#include "Text.h"
#include "Utils.h"
namespace sdds {
   Text::Text(const Text& src)
   {
      m_content = nullptr;
      *this = src;
   }
   Text& Text::operator=(const Text& src)
   {
      if (this != &src) {
         delete[] m_content;
         if (src.m_content != nullptr) {
            m_content = new char[strlen(src.m_content) + 1];
            strcpy(m_content, src.m_content);
         }
      }
      else
      {
         m_content = nullptr;
      }
      return *this;
   } 
   const char& Text::operator[](int index) const
   {
      return m_content[index];
   }
   std::istream& Text::read(std::istream& istr)
   {
      char ch;
      int i = 0;
      delete[] m_content;
      if (istr) {
         m_content = new char[ut.getFileLength(istr) + 1];
         while (istr.get(ch))
         {
            m_content[i] = ch;
            i++;
         }
         if (m_content != nullptr) {
            istr.clear();
         }
      }
      return istr;
   }
   std::ostream& Text::write(std::ostream& ostr) const
   {
      if (m_content != nullptr) {
         ostr << m_content;
      }
      return ostr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Text& t)
   {
      return t.write(ostr);
   }
   std::istream& operator>>(std::istream& istr, Text& t)
   {
      return t.read(istr);
   }

}
