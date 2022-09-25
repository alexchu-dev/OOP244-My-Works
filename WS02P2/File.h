/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]);
   // Closes the open file
   void closeFile();
   // Finds the records kept in the file to be used for the dynamic memory allocation 
   // of the records in the file
   int noOfRecords();
   // Reads postal code from the stream, skips the comma and return true if successful
   bool read(char postalCode[]);
   // Reads population from the stream, skips the newline and return true if successful
   bool read(int& population);
   //char* readLine(char* postalCode, int* population);
}
#endif // !SDDS_FILE_H_
