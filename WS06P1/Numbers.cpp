************************************************************************
//                    OOP244NAA - WS06 Part 1 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
****************************************************************************** /
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::Numbers(const Numbers& src) {
      setEmpty();
      m_isOriginal = false;
      *this = src; // calls assignment operator
   }
   
   Numbers& Numbers::operator=(const Numbers& src) {
      // check for self-assignment
      if (this != &src) {
         // deallocate previous allocated dynamic memory
         delete[] m_numbers;
         setEmpty();
         m_isOriginal = false;
         // allocate new dynamic memory if needed
         if(src.m_numbers != nullptr) {
            m_numbers = new double[m_numCount];
            // copy the resource data
            for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = src.m_numbers[i];
            }
         }
      }
      return *this;
   }
   
   Numbers::~Numbers() {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

  

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
  

}
