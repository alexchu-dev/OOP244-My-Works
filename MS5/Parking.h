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
#define MAX_PARKING_SPOTS 100
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Car.h"
#include "Motorcycle.h"
namespace sdds {
   class Parking {
      char* m_filename;
      /*New Members Added Below*/
      int m_noOfSpots;
      int m_noOfParked;
      Vehicle* m_parkingSpots[MAX_PARKING_SPOTS];
      
      Menu m_parkingMenu{"Parking Menu, select an action:", 0};
      Menu m_vehicleMenu{"Select type of the vehicle:", 1};
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
      Parking(const Parking& src) = delete;
      Parking& operator=(const Parking& src) = delete;


   public:
      Parking(const char* filepath = "", int noOfSpots = 0);
      ~Parking();
      void setFilename(const char* filepath);
      int run();
      int selectMenu(Menu& menu);
      void pause();
   };
   

}


#endif