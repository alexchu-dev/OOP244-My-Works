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
#include <cctype>
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
      if (plate != nullptr && plate[0] != '\0' && makeModel != nullptr && makeModel[0] != '\0') {
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
   bool Vehicle::operator==(const char* plate) const
   {
      //int i;
      //for (i = 0; m_plate[i] && plate[i] && ((m_plate[i] == plate[i]) || (m_plate[i] > 64 && plate[i] > 64 && (m_plate[i] - plate[i] == 32 || m_plate[i] - plate[i] == -32))); i++);
      //return !(m_plate[i] - plate[i]);

      //new method using toupper with cctype
      char temp_plate[9];
      for (int i = 0; i < 8; i++)
      {
         temp_plate[i] = toupper(plate[i]);
      }
      return !strcmp(m_plate, temp_plate);
   }
   std::istream& Vehicle::read(std::istream& istr)
   {
      // TODO: insert return statement here
   }
   bool operator==(const Vehicle& a, const Vehicle& b)
   {
      //Note: Check if it can use the other operator overloading
      return a.getLicensePlate() == b.getLicensePlate();
   }
}