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
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Vehicle::Vehicle()
   {
      setEmpty();
   }
   Vehicle::Vehicle(const char* plate, const char* makeModel)
   {
      setEmpty(); //set to invalid empty state if plate and makeModel are null or invalid
      m_parkingSpot = 0;
      if (plate != nullptr && plate[0] != '\0' && strlen(plate) <9 && makeModel != nullptr && makeModel[0] != '\0' && strlen(makeModel) >= 2) {
         strcpy(m_plate, plate);
         setMakeModel(makeModel);
      }
   }
   Vehicle::~Vehicle()
   {
      delete[] m_makeModel;
   }
   Vehicle::Vehicle(const Vehicle& v)
   {
      m_makeModel = nullptr;
      *this = v; //calls assignment operator
   }
   Vehicle& Vehicle::operator=(const Vehicle& v)
   {
      if (this != &v) {
         //Shallow copy fist
         if (v.m_plate != nullptr) {
            strcpy(m_plate, v.m_plate);
         }
         setParkingSpot(v.m_parkingSpot);
         //DMA starts, call setMakeModel to copy resource data
         setMakeModel(v.m_makeModel);        
      }
      return *this;
   }
   void Vehicle::setEmpty()
   {
      m_plate[0] = '\0';
      delete[] m_makeModel;
      m_makeModel = nullptr;
      m_parkingSpot = 0; //NOTE: or -1?
   }
   bool Vehicle::isEmpty() const
   {
      return (m_makeModel == nullptr || m_plate[0] == '\0');
   }
   const char* Vehicle::getLicensePlate() const
   {
      return m_plate;
   }
   const char* Vehicle::getMakeModel() const
   {
      return m_makeModel;
   }
   char* Vehicle::setMakeModel(const char* makeModel)
   {
      //allocate new dynamic memory if needed
      delete[] m_makeModel;
      if (makeModel!=nullptr) {
         m_makeModel = new char[strlen(makeModel) + 1];
         strcpy(m_makeModel, makeModel);
      }
      else {
         setEmpty();
      }
      return m_makeModel;
   }
   int Vehicle::getParkingSpot() const
   {
      return m_parkingSpot;
   }
   void Vehicle::setParkingSpot(const int parkingSpot)
   {
      if (parkingSpot >= 0)
      {
         m_parkingSpot = parkingSpot;
      }
      else
      {
         setEmpty();
      }
   }
   std::istream& Vehicle::read(std::istream& istr)
   {
      char temp_makeModel[61];
      if (isCsv()) {
         istr >> m_parkingSpot;
         istr.ignore();
         istr.getline(m_plate, 9, ',');
         toUpper(m_plate);
         istr.getline(temp_makeModel, 61, ',');
         setMakeModel(temp_makeModel);
      }
      else {
         cout << "Enter License Plate Number: ";
         do {
            if (istr.fail()) {
               istr.clear();
               istr.ignore(1000, '\n');
            }
            istr.getline(m_plate, 9, '\n');
            if (istr.fail()) cout << "Invalid License Plate, try again: ";
         } while (istr.fail());
         toUpper(m_plate);

         cout << "Enter Make and Model: ";
         bool minLen;
         do {
            if (istr.fail()) {
               istr.clear();
               istr.ignore(1000, '\n');
            }
            istr.getline(temp_makeModel, 61, '\n');
            minLen = strlen(temp_makeModel) < 2;
            if (istr.fail() || minLen) cout << "Invalid Make and model, try again: ";
         } while (istr.fail() || minLen);
         setMakeModel(temp_makeModel);

         //cout << "Enter Licence Plate Number: ";
         //istr.getline(m_plate, 9, '\n');
         //while (istr.fail()) {
         //   cout << "Invalid Licence Plate, try again: ";
         //   istr.clear();
         //   istr.ignore(1000, '\n');
         //   istr.getline(m_plate, 9, '\n');
         //}
         //toUpper(m_plate);
         //cout << "Enter Make and Model: ";
         //istr.getline(temp_makeModel, 61, '\n');
         //while (istr.fail()||strlen(temp_makeModel)<2) {
         //   cout << "Invalid Make and model, try again: ";
         //   istr.clear();
         //   istr.ignore(1000, '\n');
         //   istr.getline(temp_makeModel, 61, '\n');
         //}
         //setMakeModel(temp_makeModel);
      }
      if (istr.fail())
      {
         setEmpty();
      }
      return istr;
   }
   std::ostream& Vehicle::write(std::ostream& ostr) const
   {
      if (isEmpty()) {
         ostr << "Invalid Vehicle Object" << endl;
      }
      else {
         writeType(ostr);
         if (isCsv()) {
            ostr << m_parkingSpot << "," << m_plate << "," << m_makeModel << ",";
         }
         else {
            ostr << "Parking Spot Number: ";
            if (m_parkingSpot == 0) {
               ostr << "N/A" << endl;
            }
            else {
               ostr << m_parkingSpot << endl;
            }
            ostr << "License Plate: " << m_plate << endl;
            ostr << "Make and Model: " << m_makeModel << endl;
         }
      }
      return ostr;
   }

   bool Vehicle::operator==(const char* plate) const
   {
      //Using toUpper. In case if the assigned value of the Vehicle "a" or the input plate sttring is not in upper case, two strings are to be copied to temp values first then compare.
      char temp_plate1[9];
      char temp_plate2[9];
      strcpy(temp_plate1, plate);
      toUpper(temp_plate1);
      strcpy(temp_plate2, m_plate);
      toUpper(temp_plate2);
      return !strcmp(temp_plate1, temp_plate2);
   }

   bool Vehicle::operator==(const Vehicle& b) const
   {
      //Note: Check if it can use the other operator overloading
      char temp_plate1[9];
      char temp_plate2[9];
      strcpy(temp_plate1, m_plate);
      toUpper(temp_plate1);
      strcpy(temp_plate2, b.m_plate);
      toUpper(temp_plate2);
      return !strcmp(temp_plate1, temp_plate2);
   }
}