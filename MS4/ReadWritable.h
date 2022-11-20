/***********************************************************************
// ReadWritable Module
// File  ReadWritable.h
// Version 0.11
// Date  16 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_READWRITABLE_H_
#define SDDS_READWRITABLE_H_
#include <iostream>
namespace sdds {
   class ReadWritable {
      bool m_flag;
   public:
      ReadWritable();
      virtual ~ReadWritable() {};
      bool isCsv()const;
      void setCsv(bool value);
      virtual std::istream& read(std::istream& istr = std::cin) = 0;
      virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
   };
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW);
   std::istream& operator>>(std::istream& istr, ReadWritable& RW);
}
#endif