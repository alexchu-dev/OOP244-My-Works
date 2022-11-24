/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.13
// Date  3 Nov 2022
// Author   Alex Chu
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu       6 Nov 2022        Added strlen, strcmp, assign default for len in strcpy
// Alex Chu       20 Nov 2022       Added toUpper to avoid including the whole cctype
// Alex Chu       22 Nov 2022       Added yesno to Utils because it is being used in both MS2 and MS4, also used toUpper
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
namespace sdds {
   Utils ut;
   void Utils::strcpy(char* des, const char* src, int len) {
      int i;
      for (i = 0; src[i] && (len < 0 || i < len); i++) {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int Utils::strlen(const char* str) {
      int len = 0;
      while (str[len]) {
         len++;
      }
      return len;
   }
   
   int Utils::strcmp(const char* s1, const char* s2) {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   unsigned Utils::getFileLength(std::istream& is) {
      unsigned len{};
      if (is) {
         // save the current read position
         std::streampos cur = is.tellg();
         // go to the end
         is.seekg(0, std::ios::end);
         // tell what is the positions (end position = size)
         len = unsigned(is.tellg());
         // now go back to where you were.
         is.seekg(cur);
      }
      return len;
   }
}