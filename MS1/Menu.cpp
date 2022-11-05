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
   MenuItem::MenuItem()
   {
      setEmpty();
   }
   MenuItem::MenuItem(char* text)
   {
      if (text != nullptr) {
         strncpy(m_text, text, 50);
         m_text[50] = 0;
      }
      else {
         setEmpty();
      }
   }
   ostream& MenuItem::display(ostream& coutRef) const
   {
      // TODO: insert return statement here
   }
   void MenuItem::setEmpty()
   {
      m_text[0] = 0;
   }
   Menu::Menu()
   {
      setEmpty();
   }
   Menu::Menu(char* text, int indentation = 0)
   {
      if (text != nullptr) {
         strncpy(m_title, text, 50);
         m_title[50] = 0;
         m_indentation = indentation;
      }
      else {
         setEmpty();
      }
   }
   void Menu::setEmpty()
   {
      m_title[0] = 0;
      m_indentation = 0;
   }
}