/***********************************************************************
// Car Module
// File  Car.h
// Version 0.10
// Date  21 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <iostream>
#include "Vehicle.h"
namespace sdds {
   class Car : public Vehicle {
      bool m_carWash = 0;
   public:
      Car(const char* plate = "", const char* makeModel = "") : Vehicle(plate, makeModel) {};
      ~Car() {};
      Car(const Car& c);
      Car& operator=(const Car& c);
      std::ostream& writeType(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
}
#endif // !SDDS_CAR_H_
