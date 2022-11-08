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
      setFilename(filepath);
      if (loadData()) {
            m_parkingMenu = new Menu("Parking Menu, select an action:", 0);
            *m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
            m_vehicleMenu = new Menu("Select type of the vehicle:", 1);
            *m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
      }
      else {
         cout << "Error in data file" << endl;
         setEmpty();
      }
   }

   /* Destructor of Parking, call the deallocate member function */
   Parking::~Parking()
   {
      saveData();
      deallocate();
   }

   void Parking::setFilename(const char* filepath)
   {
      if (filepath != nullptr && filepath[0] != 0)
      {
         m_filename = new char[strlen(filepath) + 1];
         strcpy(m_filename, filepath);
      }
      else {
         setEmpty();
      }
   }

   int Parking::run()
   {
      int selection = 0;
      bool exit = 0;
      if (!isEmpty()) {
         do {
            parkingStatus();
            m_parkingMenu->display();
            selection = selectMenu(m_parkingMenu);
            switch (selection) {
            case 1:
               parkVehicle();
               break;
            case 2:
               returnVehicle();
               break;
            case 3:
               listParkedVehicle();
               break;
            case 4:
               findVehicle();
               break;
            case 5:
               exit = closeParking();
               if (exit) { cout << "Ending application!" << endl; }
               break;
            case 6:
               exit = exitParking();
               if (exit) { cout << "Exiting application!" << endl; }
               break;
            }
         } while (!exit);
      }
      return (isEmpty());
   }

   int Parking::selectMenu(const Menu* menu)
   {
      int selection = 0;
      do {
         do {
            if (cin.fail()) {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Invalid Integer, try again: ";
            }
            cin >> selection;
         } while (cin.fail());
         if (selection < 1 || selection > menu->noOfItems()) {
            cout << "Invalid selection, try again: ";
         }
      } while (selection < 1 || selection > menu->noOfItems());
      return selection;
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
   bool Parking::loadData()
   {
      bool flag = false;
      if (!isEmpty())
      {
         cout << "---------------------------------" << endl;
         cout << "loading data from " << m_filename << endl;
         cout << "---------------------------------" << endl;
         cout << endl;
         flag = true;
      }
      else {
         flag = false;
      }
      return flag;
   }
   void Parking::saveData()
   {
      if (!isEmpty()) {
         cout << "---------------------------------" << endl;
         cout << "Saving data into " << m_filename << endl;
         cout << "---------------------------------" << endl;
      }
   }
   bool Parking::isEmpty()
   {
      return (m_filename==nullptr);
   }
   void Parking::parkingStatus()
   {
      cout << "****** Valet Parking ******" << endl;
   }
   void Parking::parkVehicle()
   {
      int selection = 0;
      m_vehicleMenu->display();
      selection = selectMenu(m_vehicleMenu);
      switch (selection) {
         case 1:
            cout << "---------------------------------" << endl;
            cout << "Parking Car" << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
            break;
         case 2:
            cout << "---------------------------------" << endl;
            cout << "Parking Motorcycle" << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
            break;
         case 3:
            cout << "---------------------------------" << endl;
            cout << "Cancelled parking" << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
            break;
      }

   }
   void Parking::returnVehicle()
   {
      cout << "---------------------------------" << endl;
      cout << "Returning Vehicle" << endl;
      cout << "---------------------------------" << endl;
      cout << endl;
   }
   void Parking::listParkedVehicle()
   {
      cout << "---------------------------------" << endl;
      cout << "Listing Parked Vehicles" << endl;
      cout << "---------------------------------" << endl;
      cout << endl;
   }
   void Parking::findVehicle()
   {
      cout << "---------------------------------" << endl;
      cout << "Finding a Vehicle" << endl;
      cout << "---------------------------------" << endl;
      cout << endl;
   }
   bool Parking::closeParking()
   {
      cout << "This will close the parking; All the vehicles will be removed!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      return yesno();
   }
   bool Parking::exitParking()
   {
      cout << "This will terminate the application and save the data!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      return yesno();
   }
   bool Parking::yesno()
   {
      char selection[256];
      int loop = 0;
      bool res;
      do {
         cin.ignore();
         cin.get(selection, 256);
         if (!strcmp(selection, "y") || !strcmp(selection, "Y")) {
            res = true;
            loop = 0;
         }
         else if (!strcmp(selection, "n") || !strcmp(selection, "N")) {
            res = false;
            loop = 0;
         }
         else {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            loop = 1;
         }
      } while (loop == 1);
      return res;
   }
}