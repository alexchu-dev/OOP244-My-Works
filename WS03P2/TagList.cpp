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
#include "Utils.h"
#include "TagList.h"
#include "NameTag.h"
using namespace std;
namespace sdds {
   int maxLen = 0;
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
      bool added = false;
      for (int i = 0; i < m_noOfTags && !added; i++) {
         if (m_NameTag[i].getLen() == 0) {
            m_NameTag[i] = nt;
            added = true;
            if (maxLen <= m_NameTag[i].getLen()) {
               maxLen = m_NameTag[i].getLen();
            }
         }
      }
   }
   void TagList::print() {
      for (int i = 0; i < m_noOfTags; i++) {
         for (int j = 0; j < maxLen + 4; j++) {
            cout << "*";
         }
         cout << endl;
         cout << "* ";
         cout.width(maxLen);
         cout.fill(' ');
         cout.setf(ios::left);
         cout << m_NameTag[i].getName();
         cout.unsetf(ios::left);
         cout << " *" << endl;
         for (int j = 0; j < maxLen + 4; j++) {
            cout << "*";
         }
         cout << endl;
      }
   }
   void TagList::cleanup() {
      delete[] m_NameTag;
      m_NameTag = nullptr;
   }
}