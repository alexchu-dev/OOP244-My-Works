/************************************************************************
//                    OOP244NAA - WS06 Part 1 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
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
         if (src.m_numbers != nullptr) {
            m_numCount = src.m_numCount;
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

   Numbers& Numbers::sort(bool ascending) {
      double temp;
      for (int i = m_numCount - 1; i > 0; i--)
      {
         for (int j = 0; j < i; j++)
         {
            if (ascending) {
               if (m_numbers[j] > m_numbers[j + 1])
               {
                  temp = m_numbers[j];
                  m_numbers[j] = m_numbers[j + 1];
                  m_numbers[j + 1] = temp;
               }
            }
            else {
               if (m_numbers[j] < m_numbers[j + 1])
               {
                  temp = m_numbers[j];
                  m_numbers[j] = m_numbers[j + 1];
                  m_numbers[j + 1] = temp;
               }

            }
         }
      }
      return *this;
   }

   Numbers Numbers::operator-()const {
      Numbers temp;
      temp = *this;
      temp.sort(false);
      return temp;
   }

   Numbers Numbers::operator+()const {
      Numbers temp;
      temp = *this;
      temp.sort(true);
      return temp;
   }

   Numbers& Numbers::operator+=(double dbl)
   {
      if (!isEmpty()) {
         double* temp = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
         }
         temp[m_numCount] = dbl;
         m_numCount++;
         delete[] m_numbers;
         m_numbers = temp;
      }
      return *this;
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
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   int Numbers::numberCount()const {
      int count = 0;
      ifstream f(this->m_filename);
      if (f) {
         while (f) {
            double num;
            f >> num;
            if (f) {
               count++;
            }
         }
      }
      return count;
   }
   bool Numbers::load() {
      bool flag = false;
      if (m_numCount > 0)
      {
         m_numbers = new double[m_numCount];
         ifstream f(m_filename);
         if (f) {
            for (int i = 0; i < m_numCount; i++) {
               f >> m_numbers[i];
               if (i + 1 == m_numCount)
               {
                  flag = true;
               }
            }
         }
         else {
            deallocate();
            setEmpty();
         }
      }
      return flag;
   }
   void Numbers::save() {
      if (this->m_isOriginal && !isEmpty()) {
         {
            ofstream f(m_filename);
            if (f) {
               for (int i = 0; i < m_numCount; i++) {
                  f.setf(ios::fixed);
                  f.precision(2);
                  f << m_numbers[i] << endl;
                  f.unsetf(ios::fixed);
               }
            }
         }
      }
   }

   ostream& Numbers::display(ostream& ostr = std::cout) const
   {
      if (isEmpty())
         ostr << "Empty list";
      else {
         ostr << "=========================" << endl;
         if (m_isOriginal)
            ostr << m_filename << endl;
         else
            ostr << "*** COPY ***" << endl;
         for (int i = 0; i < m_numCount; i++) {
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << m_numbers[i];
            if (i + 1 < m_numCount)
               ostr << ", ";
            else
               ostr << endl;
         }
         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl;
         ostr << "=========================";
         ostr.unsetf(ios::fixed);
      }
      return ostr;
   }
   std::ostream& operator<<(ostream& os, const Numbers& N)
   {
      return N.display(os);
   }
   std::istream& operator>>(istream& istr, Numbers& N)
   {
      double dbl;
      istr >> dbl;
      if (istr)
         N += dbl;
      return istr;
   }
}
