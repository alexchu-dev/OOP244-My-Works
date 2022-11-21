/***********************************************************************
// ReadWritable Module (Function descriptions in cpp file)
// File  Vehicle.h
// Version 0.12
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
   class Vehicle : public ReadWritable {
      char m_plate[9] = { '\0' };
      char* m_makeModel = nullptr;
      int m_parkingSpot = 0;
   protected:
      void setEmpty();
      bool isEmpty()const;
      char* setMakeModel(const char* makeModel);
      const char* getLicensePlate()const;
      const char* getMakeModel()const;
   public:
      Vehicle(const char* plate="", const char* makeModel="");
      ~Vehicle();
      Vehicle(const Vehicle& v);
      Vehicle& operator=(const Vehicle& v);
      bool operator==(const char* plate)const;
      bool operator==(const Vehicle& b)const;
      int getParkingSpot()const;
      void setParkingSpot(const int parkingSpot);
      std::istream& read(std::istream& istr = std::cin);
      virtual std::ostream& writeType(std::ostream& ostr = std::cout)const=0;
      std::ostream& write(std::ostream& ostr = std::cout)const;
   };
   
}
#endif