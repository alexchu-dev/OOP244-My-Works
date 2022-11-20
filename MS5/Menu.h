/***********************************************************************
// Menu Module
// File  menu.h
// Version 0.11
// Date  3 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu       7 Nov 2022        Put Menu member functions private and only a few accessible and created a noOfItems() to check menu numbers
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#define MAX_NO_OF_ITEMS 10
#include <iostream>
namespace sdds {
   class MenuItem {
      char m_text[51];
      MenuItem();
      MenuItem(const char* text);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      void setEmpty();
      /* Prevent copy and assignment */
      MenuItem(const MenuItem& src) = delete;
      MenuItem& operator=(const MenuItem& src) = delete;
   public:
      friend class Menu;
   };
   class Menu {
      char m_title[51];
      MenuItem m_items[MAX_NO_OF_ITEMS];
      int m_noOfItems;
      int m_indentation;
      /* Prevent copy and assignment */
      Menu(const Menu& src) = delete;
      Menu& operator=(const Menu& src) = delete;
   public:
      Menu();
      Menu(const char* text, int indentation=0);
      Menu& operator=(const char* title);
      Menu& operator<<(const char* item);
      void add(const char* item);
      operator bool()const;
      bool isEmpty()const;
      void setEmpty();
      operator int()const;
      void clear();
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      std::ostream& indent(std::ostream& coutRef = std::cout)const;
      int run()const;
      int noOfItems()const;
   };
}
#endif