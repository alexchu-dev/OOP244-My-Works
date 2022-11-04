/***********************************************************************
// Menu Module
// File  menu.cpp
// Version 0.0
// Date  3 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Menu.h"
using namespace std;
namespace sdds {
   MenuItem::MenuItem(char* text)
   {
      if (text != nullptr) {
         strncpy(m_text, text, 50);
         m_text[50] = 0;
      }
      else {
         m_text[0] = 0;
      }
   }
   ostream& MenuItem::display(ostream& coutRef) const
   {
      // TODO: insert return statement here
   }
}