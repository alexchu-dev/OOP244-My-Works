/*
*****************************************************************************
                    OOP244NAA - WS03 Part 1 @ Sep 28 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assdignments.
*****************************************************************************
*/
#ifndef SDDS_CC_H_
#define SDDS_CC_H_
namespace sdds {
   class CC {
      char* m_name;
      short m_cvv;
      short m_expMon;
      short m_expYear;
      unsigned long long m_ccNum;
      bool validate();


   };
}
#endif //SDDS_CC_H_