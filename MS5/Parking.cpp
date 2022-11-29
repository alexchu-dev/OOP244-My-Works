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
#include <stdlib.h>
using namespace std;
namespace sdds {
   /* Constructor with 2 args */
   Parking::Parking(const char* filepath, int totalSpots) {
      setEmpty();
      if (filepath!=nullptr && filepath[0]!='\0' && totalSpots >= 10 && totalSpots <= MAX_PARKING_SPOTS)
      {
         m_totalSpots = totalSpots;
         setFilename(filepath);
         if(!loadData()) {
            system("Color 4F");
            cout << "<<Error in data file!!>>" << endl;
            cout << "Please select 6 in the menu to exit the program and try to restore the data." << endl << endl;
         }
         m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
         m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
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
            m_parkingMenu.display();
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

   int Parking::selectMenu(Menu& menu)
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
         if (selection < 1 || selection > menu.noOfItems()) {
            cout << "Invalid selection, try again: ";
         }
      } while (selection < 1 || selection > menu.noOfItems());
      cin.ignore(1000, '\n');
      return selection;
   }

   void Parking::pause()
   {
      cout << endl << "Press <ENTER> to continue....";
      cin.ignore(1000, '\n');
   }

   /* Member fuction to set empty state of Parking */
   void Parking::setEmpty()
   {
      m_filename = nullptr;
      m_totalSpots = 0;
      m_totalOccupied = 0;
      for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
         m_parkingSpots[i] = nullptr;
      }
   }

   /* Deallocate the DMA objects */
   void Parking::deallocate()
   {
      delete[] m_filename;
      m_filename = nullptr;
   }

   /* Check if the data can be loaded */
   bool Parking::loadData()
   {
      bool flag = false;
      char type;
      int index = -1;
      Vehicle* temp;
      if (!isEmpty()) {
         ifstream fin(m_filename);
         if (fin.is_open()) {
            while (fin.get(type)) {
               fin.ignore();
               if (type == 'M' || type == 'm') {
                  temp = new Motorcycle;
                  temp->setCsv(true);
                  temp->read(fin);
                  index = temp->getParkingSpot()-1;
                  delete[] m_parkingSpots[index];
                  m_parkingSpots[index] = new Motorcycle;
                  m_parkingSpots[index] = temp;
                  if (m_parkingSpots[index] != nullptr) {
                     m_totalOccupied++;
                     flag = true;
                  }
                  else {
                     delete[] m_parkingSpots[m_totalOccupied];
                     flag = false;
                  }
               }
               else if (type == 'C' || type == 'c') {
                  temp = new Car;
                  temp->setCsv(true);
                  temp->read(fin);
                  index = temp->getParkingSpot()-1;
                  delete[] m_parkingSpots[index];
                  m_parkingSpots[index] = new Car;
                  m_parkingSpots[index] = temp;
                  if (m_parkingSpots[index] != nullptr) {
                     m_totalOccupied++;
                     flag = true;
                  }
                  else {
                     delete[] m_parkingSpots[m_totalOccupied];
                     flag = false;
                  }
               }
               else { flag = false; }
            }
            //end of while
         }
         else {
            flag = true;
         }
         fin.close();
      }
      else { flag = true; }
      return flag;
   }
   void Parking::saveData()
   {
      if (!isEmpty()) {
         ofstream fout(m_filename);
         if (fout.is_open()) {
            for (int i = 0; i < m_totalSpots; i++) {
               if (m_parkingSpots[i] != nullptr) m_parkingSpots[i]->write(fout);
            }
         }
      }
   }
   bool Parking::isEmpty()
   {
      return (m_filename==nullptr);
   }
   void Parking::parkingStatus()
   {
      cout << "****** Valet Parking ******" << endl;
      cout << "***** Available spots: ";
      cout.width(4);
      cout.setf(ios::left);
      cout.fill(' ');
      cout << m_totalSpots - m_totalOccupied << " *****" << endl;
      cout.unsetf(ios::left);
   }
   void Parking::parkVehicle()
   {
      if (m_totalOccupied == m_totalSpots) {
         cout << endl << "Parking is full" << endl;
         pause();
      }
      else {
         int selection = 0;
         int index = findEmptySpot();
         Vehicle* tmpV;
         m_vehicleMenu.display();
         selection = selectMenu(m_vehicleMenu);
         switch (selection) {
         case 1:
            tmpV = new Car;
            tmpV->setCsv(false);
            tmpV->read(cin);
            m_parkingSpots[index] = tmpV;
            m_parkingSpots[index]->setParkingSpot(index+1);
            m_totalOccupied++;
            cout << endl << "Parking Ticket" << endl;
            m_parkingSpots[index]->write(cout);
            m_parkingSpots[index]->setCsv(true);
            pause();
            break;
         case 2:
            tmpV = new Motorcycle;
            tmpV->setCsv(false);
            tmpV->read(cin);
            m_parkingSpots[index] = tmpV;
            m_parkingSpots[index]->setParkingSpot(index + 1);
            m_totalOccupied++;
            cout << endl << "Parking Ticket" << endl;
            m_parkingSpots[index]->write(cout);
            m_parkingSpots[index]->setCsv(true);
            pause();
            break;
         case 3:
            cout << "Parking Cancelled";
            pause();
            break;
         }
      }
   }
   void Parking::returnVehicle()
   {
      cout << "Returning Vehicle" << endl;
      int index = findVehicleLogic();
      if (index >= 0) {
         m_parkingSpots[index]->setCsv(false);
         cout << "Returning:" << endl << *m_parkingSpots[index];
         delete[] m_parkingSpots[index];
         m_parkingSpots[index] = nullptr;
      }
      m_totalOccupied--;
      pause();
   }
   void Parking::listParkedVehicle()
   {
      cout << "*** List of parked vehicles ***" << endl;
      for (int i = 0; i < m_totalSpots; i++) {
         if (m_parkingSpots[i] != nullptr) {
            m_parkingSpots[i]->setCsv(false);
            m_parkingSpots[i]->write(cout);
            cout << "-------------------------------" << endl;
            m_parkingSpots[i]->setCsv(true);
         }
      }
      pause();
   }
   void Parking::findVehicle()
   {
      cout << "Vehicle Search" << endl;
      int index = findVehicleLogic();
      if (index >= 0) {
         m_parkingSpots[index]->setCsv(false);
         cout << "Vehicle found:" << endl << *m_parkingSpots[index];
         m_parkingSpots[index]->setCsv(true);
      }
      pause();
   }
   int Parking::findVehicleLogic()
   {
      char temp_plate[9];
      int index = -1;
      cout << "Enter Licence Plate Number: ";
      do {
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
         }
         cin.getline(temp_plate, 9, '\n');
         if (cin.fail()) cout << "Invalid Licence Plate, try again: ";
      } while (cin.fail());
      for (int i = 0; index < 0 && i < m_totalSpots; i++) {
         if (m_parkingSpots[i] && *m_parkingSpots[i] == temp_plate) {
            index = i;
         }
      }
      cout << endl;
      if (index == -1) {
         cout << "License plate " << temp_plate << " Not found" << endl;
      }
      return index;
   }
   int Parking::findEmptySpot()
   {
      int index = -1;
      for (int i = 0; index < 0 && i < m_totalSpots; i++) {
         if (!m_parkingSpots[i]) {
            index = i;
         }
      }
      return index;
   }
   bool Parking::closeParking()
   {
      bool ret = false;
      if (m_totalOccupied == 0)
      {
         cout << "Closing Parking" << endl;
         ret = true;
      }
      else {
         cout << "This will Remove and tow all remaining Vehicles from the Parking!" <<endl;
         cout << "Are you sure? (Y)es/(N)o: ";
         ret = yesno();
         if (ret) {
            cout << "Closing Parking" << endl;
            for (int i = 0; i < m_totalSpots; i++) {
               if (m_parkingSpots[i] != nullptr) {
                  m_parkingSpots[i]->setCsv(false);
                  cout << endl << "Towing request" << endl;
                  cout << "*********************" << endl;
                  m_parkingSpots[i]->write(cout) << endl;
                  delete[] m_parkingSpots[i];
                  m_parkingSpots[i] = nullptr;
               }
            }
         }
      }
      return ret;
   }
   bool Parking::exitParking()
   {
      cout << "This will terminate the application and save the data!" << endl;
      cout << "Are you sure? (Y)es/(N)o: ";
      return yesno();
   }
}
