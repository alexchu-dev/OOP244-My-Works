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
      //The cardholder's name: that is held dynamically in a C string. (char *)
      char* m_name; 
      //CVV, expiry month, and expiry year: that are all held in short integers. (short)
      short m_cvv;  
      short m_expMon;
      short m_expYear;
      //Credit card number: that is held in an unsigned long long integer (unsigned long long)
      unsigned long long m_ccNum;
      
      bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
      void prnNumber() const;
   public:
      void set();
      void cleanUp();
      bool isEmpty() const;
      void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);
      bool read();
      void display(int row = 0) const;
   };
}
#endif //SDDS_CC_H_