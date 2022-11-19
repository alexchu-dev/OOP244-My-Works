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
using namespace std;
namespace sdds {
   Vehicle::Vehicle()
   {
      setEmpty();
   }
   Vehicle::Vehicle(const char* plate, const char* makeModel)
   {
      setEmpty();
      m_parkingSpot = 0;
      strcpy(m_plate, plate);
      m_makeModel = makeModel;
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
         strcpy(m_plate, v.m_plate);
         m_parkingSpot = v.m_parkingSpot;
         //DMA starts, copy resource data
         delete[] m_makeModel;
         if (v.m_makeModel != nullptr) {
            m_makeModel = new char[strlen(v.m_makeModel) + 1];
            strcpy(m_makeModel, v.m_makeModel);
         }
         else {
            m_makeModel = nullptr;
         }
        
      }
      return *this;
   }
   char* Vehicle::operator=(const char* plate)
   {
      delete[] m_makeModel;
      if (plate != nullptr) {
         m_makeModel = new char[strlen(plate) + 1];
         strcpy(m_makeModel, plate);
      }
      else {
         m_makeModel = nullptr;
      }
      return m_makeModel;
   }
   void Vehicle::setEmpty()
   {
      m_plate[0] = '\0';
      m_makeModel = nullptr;
      m_parkingSpot = 0;
   }
}