/***********************************************************************
// Utils Module
// File  utils.h
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

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
   void strcpy(char* des, const char* src, int len = -1);
   int strlen(const char* str);
   int strcmp(const char* s1, const char* s2);
   void toUpper(char* ch);
}
#endif // !
