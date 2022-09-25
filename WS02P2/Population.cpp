/*
*****************************************************************************
                    OOP244NAA - WS02 Part 2 @ Sep 24 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assdignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "Utils.h"

using namespace std;
namespace sdds {
   Population* pop = nullptr;
   bool load(const char filename[])
   {
      bool ret = false;
      if (openFile(filename)) {
         if (noOfRecords() > 0) {
            cout << "There are " << noOfRecords() << " records in the file." << endl;
            cout << pop << endl;
            pop = new Population[noOfRecords()];
            if (!pop)
            {
               cout << "Memory allocation failed!" << endl;
            }
            else
               cout << pop << endl;
            /*char* postalCode[8];
            int* population = nullptr;
            readLine(postalCode, population);
            cout << postalCode;
            ret  = true;*/
         }
         else {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            ret = false;
         }
      }
      else {
         cout << "Could not open data file: " << filename << endl;
         ret = false;
      }
      return ret;
   }
   void display() {
      

      
   }
   void deallocateMemory() {
      delete[] pop;
      pop = nullptr;
      cout << pop << endl;
   }
}