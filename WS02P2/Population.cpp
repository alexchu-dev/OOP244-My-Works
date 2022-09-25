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
   Population* pop = nullptr; //Set nullptr for pointer of Population
   int noOfRecs;  //File scope variable to store the integer receive from noOfRecords().
   
   //Open file, loads data, then assign DMA to pop, then read data and store in pop, return true or false then close the file
   bool load(const char filename[])
   {
      bool ret = false;    //Default ret to false
      if (openFile(filename)) {
         //Returns and check the value of noOfRecords() > 0
         if ((noOfRecs = noOfRecords())) {     
            pop = new Population[noOfRecs];     //DMA set
            if (!pop)      //Just in case if DMA fails
            {
               cout << "Memory allocation failed!" << endl;
            }
            else
            {
               //cout << pop << endl;    //This line is to check the memory address is normal
               for (int i = 0; i < noOfRecs; i++)  //use overloaded read() methods to read a char array and an int
               {
                  read(pop[i].m_postalCode);
                  read(pop[i].m_population);
               }
            }
            ret = true;
         }
         else
         {
            //Error message as required from the workshop in case record is abnormal
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            ret = false;
         }
         closeFile();
      }
      else
      {
         //Error message when openFile() fails
         cout << "Could not open data file: " << filename << endl;
         ret = false;
      }
      return ret;
   }

   //Bubble sorting the array
   void bubbleSort(Population pop[], int noOfRecs)
   {
      int i, j;
      Population temp;
      for (i = 0; i < noOfRecs - 1; i++)
      {
         for (j = 0; j < noOfRecs - i - 1; j++)
         {
            if (pop[j].m_population > pop[j + 1].m_population)
            {
               temp = pop[j];
               pop[j] = pop[j + 1];
               pop[j + 1] = temp;
            }
         }
      }
   }
   //Function with no parameters that return nothing and prints the report
   void display() {
      bubbleSort(pop,noOfRecs);
      int total = 0;
      cout << "Postal Code: population" << endl;
      cout << "-------------------------" << endl;
      for (int i=0; i < noOfRecs; i++)
      {
         cout << i+1 << "- " << pop[i].m_postalCode << ":  " << pop[i].m_population << endl;
         total += pop[i].m_population;
      }
      cout << "-------------------------" << endl;
      cout << "Population of Canada: " << total << endl;
   }
   //Function with no parameters that return nothing and deallocate all dynamic memory used by the program.
   void deallocateMemory() {
      delete[] pop;
      pop = nullptr;
      //cout << pop << endl;  //<== check if pop has been deleted.
   }
}