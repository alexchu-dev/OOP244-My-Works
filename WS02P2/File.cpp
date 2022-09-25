/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu        2022/09/25      Implement neccessary functions
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file 
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Reads postal code from the stream, skips the comma and return true if successful
   bool read(char postalCode[])
   {
      bool ret = false;
      ret = fscanf(fptr, "%[^,],", postalCode) == 1;
      return ret;
   }
   // Reads population from the stream, skips the newline and return true if successful
   bool read(int& population)
   {
      bool ret = false;
      ret = fscanf(fptr, "%d\n", &population) == 1;
      return ret;
   }
   //bool read(char* postalCode, int* population) {
   //   return(fscanf(fptr, "%[^,],%d\n", postalCode,population));
   //}
   // Closes the open file
   void closeFile() {
      if (fptr) fclose(fptr);
   }

}