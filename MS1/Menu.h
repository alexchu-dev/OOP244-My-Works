#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   class MenuItem {
      char m_text[51];
   public:
      MenuItem(char* text);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      MenuItem(const MenuItem& src) = delete;
      MenuItem& operator=(const MenuItem& src) = delete;
      friend class Menu;
   };
}
#endif