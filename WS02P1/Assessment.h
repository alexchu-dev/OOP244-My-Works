/*
*****************************************************************************
                    OOP244NAA - WS02 Part 1 @ Sep 23 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assdignments.
*****************************************************************************
*/
#ifndef SDDS_ASSESSMENT_H
#define SDDS_ASSESSMENT_H
namespace sdds {
   struct Assessment {
      double* m_mark;
      char* m_title;
   };
   bool read(int& value, FILE* fptr);
   bool read(double& value, FILE* fptr);
   bool read(char* cstr, FILE* fptr);
   bool read(Assessment& asmnt, FILE* fptr);
   void freeMem(Assessment*& aptr, int size);
   int read(Assessment*& aptr, FILE* fptr);
}
#endif