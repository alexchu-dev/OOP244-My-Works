/***********************************************************************
// Utils Module
// File  utils.h
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

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
   void strcpy(char* des, const char* src, int len = -1);
   int strlen(const char* str);
   int strcmp(const char* s1, const char* s2);
}
#endif // !
