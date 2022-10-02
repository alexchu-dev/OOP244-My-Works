/******************************************************************************
//                    OOP244NAA - WS03 Part 2 @ Sep 30 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "NameTag.h"
using namespace std;
namespace sdds {
   NameTag::NameTag() {
      m_name[0] = 0;
      m_nameLen = 0;
   }
   NameTag::~NameTag() {
      m_name[0] = 0;
      m_nameLen = 0;
   }
   void NameTag::set(const char* name) {
      m_nameLen = strlen(name);
      strcpy(m_name, name, m_nameLen);
   }
   char* NameTag::getName() {
      return m_name;
   }
   int NameTag::getLen() {
      return m_nameLen;
   }
}