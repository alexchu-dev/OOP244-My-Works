/***********************************************************************
// Parking Module
// File  parking.h
// Version 0.10
// Date  6 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <iostream>
#include "Menu.h"
namespace sdds {
   class Parking {
      char* m_filename;
      Menu* m_parkingMenu;
      Menu* m_vehicleMenu;
      void setEmpty();
      void deallocate();
      bool loadData();
      void saveData();
      bool isEmpty();
      
      void parkingStatus();
      void parkVehicle();
      void returnVehicle();
      void listParkedVehicle();
      void findVehicle();
      bool closeParking();
      bool exitParking();
      bool yesno();
      Parking(const Parking& src) = delete;
      Parking& operator=(const Parking& src) = delete;
   public:
      Parking();
      Parking(const char* filepath);
      ~Parking();
      void setFilename(const char* filepath);
      int run();
      int& selectMenu(const Menu* menu);
   };
   

}


#endif