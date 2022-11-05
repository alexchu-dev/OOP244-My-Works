#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#define MAX_NO_OF_ITEMS 10
#include <iostream>
namespace sdds {
   class MenuItem {
      char m_text[51];
   public:
      MenuItem();
      MenuItem(char* text);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      MenuItem(const MenuItem& src) = delete;
      MenuItem& operator=(const MenuItem& src) = delete;
      void setEmpty();
      friend class Menu;
   };
   class Menu {
      char m_title[51];
      MenuItem m_items[MAX_NO_OF_ITEMS];
      int m_noOfItems;
      int m_indentation;
   public:
      Menu();
      Menu(char* text, int indentation = 0);
      Menu(const Menu& src) = delete;
      Menu& operator=(const Menu& src) = delete;  
      void setEmpty();
   };
}
#endif