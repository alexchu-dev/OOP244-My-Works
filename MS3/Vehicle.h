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
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include <iostream>
#include "ReadWritable.h"
namespace sdds {
   class Vehicle : ReadWritable {
      char m_plate[9];
      char* m_makeModel;
      int m_parkingSpot = 0;
   public:
      Vehicle();
      Vehicle(const char* plate, const char* makeModel);
      ~Vehicle();
      Vehicle(const Vehicle& v);
      Vehicle& operator=(const Vehicle& v);
      void setEmpty();
      bool isEmpty()const;
      const char* getLicensePlate()const;
      const char* getMakeModel()const;
      void setMakeModel(const char* makeModel);
      int getParkingSpot()const;
      void setParkingSpot(const int parkingSpot);
   };
}
#endif