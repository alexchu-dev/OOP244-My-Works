/***********************************************************************
// Menu Module
// File  menu.cpp
// Version 0.11
// Date  3 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   /*~~~~~~~~MenuItem stuff starts below~~~~~~~~*/
   /* Default constructor of MenuItem, set empty */
   MenuItem::MenuItem()
   {
      setEmpty();
   }
   
   /* Constructor - the argument to be the content of MenuItem*/
   MenuItem::MenuItem(const char* text)
   {
      if (text != nullptr) {
         strcpy(m_text, text, 50);
         m_text[50] = 0;
      }
      else {
         setEmpty();
      }
   }
   
   /* Display its contents and a new line if it is not in empty state */
   ostream& MenuItem::display(ostream& coutRef) const
   {
      if (m_text[0] != 0) {
         coutRef << m_text << endl;
      }
      return coutRef;
   }
   
   /* Member fuction to set empty state of MenuItem */
   void MenuItem::setEmpty()
   {
      m_text[0] = 0;
   }
   
   
   /*~~~~~~~~Menu stuff starts below~~~~~~~~*/
   /* Default constructor of Menu, set empty */
   Menu::Menu()
   {
      setEmpty();
   }
   
   /* Constructor - the arguments to be the title and indentation format of Menu */
   Menu::Menu(const char* text, int indentation)
   {
      if (text != nullptr) {
         strcpy(m_title, text, 50);
         m_title[50] = 0;
         m_noOfItems = 0;
         m_indentation = indentation;
      }
      else {
         setEmpty();
      }
   }

   /* Return true of Menu is valid and usable */
   Menu::operator bool() const
   {
      return (m_title[0] != 0);
   }

   /* Return true if Menu is in invalid empty state*/
   bool Menu::isEmpty() const
   {
      return (m_title[0] == 0);
   }

   /* Member fuction to set empty state of Menu */
   void Menu::setEmpty()
   {
      m_title[0] = 0;
      for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
         m_items[i].m_text[0] = '\0';
      }
      m_noOfItems = 0;
      m_indentation = 0;
   }

   /* Display its title, a new line, and all of its items if it is not in empty state */
   std::ostream& Menu::display(std::ostream& coutRef) const
   {
      if (m_title[0] == 0)
      {
         coutRef << "Invalid Menu!" << endl;
      }
      else if (m_noOfItems == 0)
      {
         indent(coutRef) << m_title << endl;
         coutRef << "No Items to display!" << endl;
      }
      else {
         indent(coutRef) << m_title << endl;
         for (int i = 0; i < m_noOfItems; i++)
         {
            indent(coutRef) << i + 1 << "-";
            coutRef << " " << m_items[i].m_text << endl;
         }
         indent(coutRef) << "> ";
      }
      return coutRef;
   }

   std::ostream& Menu::indent(std::ostream& coutRef) const
   {
      if (m_indentation != 0) {
         for (int i = 0; i < m_indentation; i++)
         {
            coutRef << "    ";
         }
      }
      return coutRef;
   }

   Menu& Menu::operator=(const char* title)
   {
      if (title != nullptr) {
         strcpy(m_title, title, 50);
         m_title[50] = 0;
      }
      return *this;
   }
   Menu& Menu::operator<<(const char* item)
   {
      if (item != nullptr) {
         add(item);
      }
      else {
         setEmpty();
      }
      return *this;

   }
   void Menu::add(const char* item)
   {
      if (m_items[9].m_text[0] != '\0' || isEmpty()) {
         //do nothing and exit
      }
      else {
         if (item == nullptr) {
            setEmpty();
         }
         else {
            if (m_items[m_noOfItems].m_text[0] == '\0') {
               strcpy(m_items[m_noOfItems].m_text, item, 50);
               m_noOfItems++;
            }
         }
      }
   }
   int Menu::run() const
   {
      int selection;
      display();
      if (m_noOfItems == 0 || isEmpty())
      {
         selection = 0;
      }
      else
      {
         do {
            do {
               if (cin.fail()) {
                  cin.clear();
                  cin.ignore(256, '\n');
                  cout << "Invalid Integer, try again: ";
               }
               cin >> selection;
            } while (cin.fail());
            if (selection < 1 || selection > m_noOfItems) {
               cout << "Invalid selection, try again: ";
            }
         } while (selection < 1 || selection > m_noOfItems);
         
      }
      return selection;
   }
   Menu::operator int() const
   {
      return run();
   }
   void Menu::clear()
   {
      for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
         m_items[i].m_text[0] = '\0';
      }
      m_noOfItems = 0;
      m_indentation = 0;
   }
}