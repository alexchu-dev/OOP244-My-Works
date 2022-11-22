/***********************************************************************
// Motorcycle Module
// File  Motorcycle.cpp
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
#include "Motorcycle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Motorcycle::Motorcycle(const Motorcycle& m)
   {
      *this = m;
   }

   Motorcycle& Motorcycle::operator=(const Motorcycle& m)
   {
      Vehicle::operator=(m);
      m_sideCar = m.m_sideCar;
      return *this;
   }

   std::ostream& Motorcycle::writeType(std::ostream& ostr) const
   {
      if (isCsv()) {
         ostr << "M,";
      }
      else {
         ostr << "Vehicle type: Motorcycle" << endl;
      }
      return ostr;
   }

   std::istream& Motorcycle::read(std::istream& istr)
   {
      if (isCsv()) {
         Vehicle::read(istr);
         istr >> m_sideCar;
         istr.ignore(1000, '\n');
      }
      else {
         cout << endl;
         cout << "Motorcycle information entry" << endl;
         Vehicle::read(istr);
         cout << "Does the Motorcycle have a sidecar? (Y)es/(N)o: ";
         m_sideCar = yesno();
      }
      return istr;
   }

   std::ostream& Motorcycle::write(std::ostream& ostr) const
   {
      if (isEmpty()) {
         ostr << "Invalid Motorcycle Object" << endl;
      }
      else {
         writeType(ostr);
         if (isCsv()) {
            ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << "," << m_sideCar << endl;
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
            if (m_sideCar == 1) {
               cout << "With Sidecar" << endl;
            }
         }
      }
      return ostr;
   }

}