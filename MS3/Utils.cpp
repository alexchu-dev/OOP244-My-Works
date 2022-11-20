/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.12
// Date  3 Nov 2022
// Author   Alex Chu
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu       6 Nov 2022        Added strlen, strcmp, assign default for len in strcpy
// Alex Chu       20 Nov 2022       Added toUpper to avoid including the whole cctype
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Utils.h"

namespace sdds {
   void strcpy(char* des, const char* src, int len) {
      int i;
      for (i = 0; src[i] && (len < 0 || i < len); i++) {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int strlen(const char* str) {
      int len = 0;
      while (str[len]) {
         len++;
      }
      return len;
   }
   int strcmp(const char* s1, const char* s2) {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   char* toUpper(char* ch) {
      for (int i = 0; i < 8; i++)
      {
         if (ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] -= 32;
         }
      }
      return ch;
   }
}