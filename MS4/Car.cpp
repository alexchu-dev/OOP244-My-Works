/***********************************************************************
// Car Module
// File  Car.cpp
// Version 0.10
// Date  21 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Car.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Car::Car(const Car& c)
   {
      *this = c;
   }
   Car& Car::operator=(const Car& c)
   {
      Vehicle::operator=(c);
      m_carWash = c.m_carWash;
      return *this;
   }
   std::ostream& Car::writeType(std::ostream& ostr) const
   {
      if (isCsv()) {
         ostr << "C,";
      }
      else {
         ostr << "Vehicle type: Car" << endl;;
      }
      return ostr;
   }
   std::istream& Car::read(std::istream& istr)
   {
      if(isCsv()) {
         Vehicle::read(istr);
         istr >> m_carWash;
         istr.ignore(1000, '\n');
      }
      else {
         cout << endl;
         cout << "Car information entry" << endl;
         Vehicle::read(istr);
         cout << "Carwash while parked? (Y)es/(N)o: ";
         m_carWash = yesno();
      } 
      return istr;
   }
   std::ostream& Car::write(std::ostream& ostr) const
   {
      if (isEmpty()) {
         ostr << "Invalid Car Object" << endl;
      }
      else {
         writeType(ostr);
         if (isCsv()) {
            ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << "," << m_carWash << endl;
         }
         else {
            ostr << "Parking Spot Number: ";
            if (getParkingSpot() == 0) {
               ostr << "N/A" << endl;
            }
            else {
               ostr << getParkingSpot() << endl;
            }
            ostr << "License Plate: " << getLicensePlate() << endl;
            ostr << "Make and Model: " << getMakeModel() << endl;
            if (m_carWash == 1) {
               cout << "With Carwash" << endl;
            }
            else {
               cout << "Without Carwash" << endl;
            }
         }
      }
      return ostr;
   }
}