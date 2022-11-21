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
      bool carWash = 0;
   public:
      Car(const char* plate, const char* makeModel);
   };
}
#endif // !SDDS_CAR_H_
