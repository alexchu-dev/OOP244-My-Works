/***********************************************************************
// ReadWritable Module
// File  ReadWritable.cpp
// Version 0.12
// Date  16 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu        22 Nov 2022     Change ReadWritable attribute naming to bool m_csv
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "ReadWritable.h"
using namespace std;
namespace sdds {
   ReadWritable::ReadWritable()
   {
      m_csv = false;
   }
   bool ReadWritable::isCsv() const
   {
      return m_csv;
   }
   void ReadWritable::setCsv(bool value)
   {
      m_csv = value;
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
