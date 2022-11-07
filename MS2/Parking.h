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
   public:
      Parking();
      Parking(const char* filepath);
      ~Parking();
      void setEmpty();
      void deallocate();
   };
   

}


#endif