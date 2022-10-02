/******************************************************************************
//                    OOP244NAA - WS03 Part 2 @ Sep 30 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include "TagList.h"
#include "NameTag.h"
using namespace std;
namespace sdds {
   void TagList::set() {
      m_NameTag = nullptr;
      m_noOfTags = 0;
   }
   void TagList::set(int num) {
      cleanup();
      m_NameTag = new NameTag[num];
      m_noOfTags = num;
   }
   void TagList::add(const NameTag& nt) {
      
   }
   void TagList::print() {
      
   }
   void TagList::cleanup() {
      delete[] m_NameTag;
      m_NameTag = nullptr;
   }
}