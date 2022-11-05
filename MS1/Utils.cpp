/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.11
// Date  3 Nov 2022
// Author   Alex Chu
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
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
}