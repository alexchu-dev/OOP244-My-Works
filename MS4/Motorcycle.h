/***********************************************************************
// Motorcycle Module
// File  Motorcycle.h
// Version 0.10
// Date  21 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_
#include <iostream>
#include "Vehicle.h"
namespace sdds {
   class Motorcycle : public Vehicle {
      bool m_sideCar = 0;
   public:
      Motorcycle(const char* plate = "", const char* makeModel = "") : Vehicle(plate, makeModel) {};
      ~Motorcycle() {};
      Motorcycle(const Motorcycle& m);
      Motorcycle& operator=(const Motorcycle& m);
      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}
#endif // !SDDS_MOTORCYCLE_H_
