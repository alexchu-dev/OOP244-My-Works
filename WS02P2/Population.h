/*
*****************************************************************************
                    OOP244NAA - WS02 Part 2 @ Sep 24 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assdignments.
*****************************************************************************
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
   //Type def for the Population
   struct Population {
      char m_postalCode[4]; //did not set dynamic array for postal code because the postal code is fixed at 3+null char
      int m_population;
   };
   //Loads data from a file, and returns true if data was successfully loaded, false otherwise. This function receives as a parameter the name of the file
   bool load(const char filename[]);
   //Bubble sorting the array
   void bubbleSort(Population pop[], int noOfRecs);
   //Function with no parameters that return nothing and prints the report
   void display();
   //Function with no parameters that return nothing and deallocate all dynamic memory used by the program.
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_