/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "TagList.h"
#include "NameTag.h"
using namespace sdds;
int noOfNames(FILE* fptr) {
   char ch;
   int recs = 0;
   rewind(fptr);
   while(fscanf(fptr, "%c", &ch) == 1) {
      recs += (ch == '\n');
   }
   rewind(fptr);
   return recs;
}
int main() {
   char name[51]{};
   FILE* fptr = fopen("simpsons.txt","r");
   NameTag nt;
   TagList tl;
   tl.set();   //empty state
   tl.set(noOfNames(fptr));   //clean up, then use DMA to set by the record num
   while(fscanf(fptr, "%[^\n]\n", name) == 1) {
      nt.set(name);  //set name to NameTag
      tl.add(nt); //add NameTag to TagList
   }
   tl.print(); //tagName print out all the tags
   tl.cleanup();  //delete[] and set to nullptr
   fclose(fptr);
   return 0;
}