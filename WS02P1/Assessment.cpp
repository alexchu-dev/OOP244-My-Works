/*
*****************************************************************************
                    OOP244NAA - WS02 Part 1 @ Sep 23 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Assessment asmnt;
   bool read(int& value, FILE* fptr) {
      return fscanf(fptr, "%d", &value) == 1;
   }
   bool read(double& value, FILE* fptr) {
      return fscanf(fptr, "%lf", &value) == 1;
   }
   bool read(char* cstr, FILE* fptr) {
      return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
   }
   bool read(Assessment& asmnt, FILE* fptr) {
      double d;
      char str[61];     
      if (read(d, fptr) && read(str, fptr)) {
         asmnt.m_mark = new double;
         asmnt.m_title = new char[strlen(str)+1];
         *asmnt.m_mark = d;
         strcpy(asmnt.m_title, str);
         return true;
      }
      else {
         return false;
      }
   }
   void freeMem(Assessment*& aptr, int size) {
      for (int i = 0; i < size; i++) {
         delete aptr[i].m_mark;
         delete[] aptr[i].m_title;
      }
      delete[] aptr;
      aptr = nullptr;
   }
   int read(Assessment*& aptr, FILE* fptr) {
      int numRec;
      int cnt=0;
      read(numRec, fptr);
      aptr = nullptr;
      aptr = new Assessment[numRec];
      for (int j = 0; j < numRec; j++) {
         if (read(aptr[j], fptr)) {
            cnt++;
         }
      }
      if (cnt == numRec) {
         return cnt;
      }
      else {
         freeMem(*&aptr, cnt);
         return 0;
      }
   }
}