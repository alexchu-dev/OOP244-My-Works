/***********************************************************************
// Parking Module
// File  parking.cpp
// Version 0.10
// Date  6 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Parking.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   /* Default constructor of Parking, set empty */
   Parking::Parking() {
      setEmpty();
   }

   /* Constructor - the argument is the filepath of data */
   Parking::Parking(const char* filepath) {
      if (filepath != nullptr)
      {
         m_filename = new char[strlen(filepath)+1];
         strcpy(m_filename, filepath);
         m_parkingMenu = new Menu("Parking Menu, select an action:", 0);
         *m_parkingMenu << "Park Vehice" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
         m_vehicleMenu = new Menu("Select type of the vehicle:", 1);
         *m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
      }
      else {
         setEmpty();
      }
   }

   /* Destructor of Parking, call the deallocate member function */
   Parking::~Parking()
   {
      deallocate();
   }

   /* Member fuction to set empty state of Parking */
   void Parking::setEmpty()
   {
      m_filename = nullptr;
      m_parkingMenu = nullptr;
   }

   /* Deallocate the DMA objects */
   void Parking::deallocate()
   {
      delete[] m_filename;
      m_filename = nullptr;
      delete[] m_parkingMenu;
      m_parkingMenu = nullptr;
      delete[] m_vehicleMenu;
      m_vehicleMenu = nullptr;
   }
}