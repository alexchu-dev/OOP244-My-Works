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
   ///<summary>this is a self written toUpper method</summary>
   ///<param name="ch">char*</param>
   ///<returns>char* ch</returns>
   char* toUpper(char* ch) {
      int len = strlen(ch);
      if (ch!=nullptr){
         for (int i = 0; i < len; i++)
         {
            if (ch[i] >= 'a' && ch[i] <= 'z') {
               ch[i] -= 32;
            }
            else
               ch[i] = ch[i];
         }
      }
      else {
         ch = nullptr;
      }
      return ch;
   }
   bool yesno()
   {
      char selection[8];
      int loop = 0;
      bool res;
      do {
         if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
         }
         std::cin.getline(selection, 8, '\n');
         if (!strcmp(toUpper(selection), "Y")) {
            res = true;
            loop = 0;
         }
         else if (!strcmp(toUpper(selection), "N")) {
            res = false;
            loop = 0;
         }
         else {
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            loop = 1;
         }
      } while (std::cin.fail() || loop);
      return res;
   }
}