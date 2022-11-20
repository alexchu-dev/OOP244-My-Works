/***********************************************************************
// ReadWritable Module
// File  ReadWritable.cpp
// Version 0.11
// Date  16 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "ReadWritable.h"
using namespace std;
namespace sdds {
   ReadWritable::ReadWritable()
   {
      m_flag = false;
   }
   bool ReadWritable::isCsv() const
   {
      return m_flag;
   }
   void ReadWritable::setCsv(bool value)
   {
      m_flag = value;
   }
   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& RW)
   {
      return RW.write(ostr);
   }
   std::istream& operator>>(std::istream& istr, ReadWritable& RW)
   {
      return RW.read(istr);
   }
}
