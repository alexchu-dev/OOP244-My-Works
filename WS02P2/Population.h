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
   struct Population {
      char* m_postalCode;
      int m_population[];
   };
   bool load(const char filename[]);
   void display();
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_