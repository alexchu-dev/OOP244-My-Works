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
   /* Constructor with 2 args */
   Parking::Parking(const char* filepath, int noOfSpots) {
      setEmpty();
      if (filepath!=nullptr && filepath[0]!='\0' && noOfSpots >= 10 && noOfSpots <= MAX_PARKING_SPOTS)
      {
         m_noOfSpots = noOfSpots;
         setFilename(filepath);
         if (loadData()) {
            m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
            m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
         }
         else {
            cout << "Error in data file" << endl;
         }
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
      m_noOfSpots = 0;
      m_noOfParked = 0;
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
      if (!isEmpty()) {
         ifstream fin(m_filename);
         if (fin.is_open()) {
            while (fin.get(type)) {
               fin.ignore();
               if (type == 'M' || type == 'm') {
                  delete[] m_parkingSpots[m_noOfParked];
                  m_parkingSpots[m_noOfParked] = new Motorcycle;
                  m_parkingSpots[m_noOfParked]->setCsv(true);
                  m_parkingSpots[m_noOfParked]->read(fin);
                  if (m_parkingSpots[m_noOfParked] != nullptr) {
                     m_noOfParked++;
                     flag = true;
                  }
                  else {
                     delete[] m_parkingSpots[m_noOfParked];
                     flag = false;
                  }
               }
               else if (type == 'C' || type == 'c') {
                  delete[] m_parkingSpots[m_noOfParked];
                  m_parkingSpots[m_noOfParked] = new Car;
                  m_parkingSpots[m_noOfParked]->setCsv(true);
                  m_parkingSpots[m_noOfParked]->read(fin);
                  if (m_parkingSpots[m_noOfParked]!=nullptr) {
                     m_noOfParked++;
                     flag = true;
                  }
                  else {
                     delete[] m_parkingSpots[m_noOfParked];
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
            for (int i = 0; i < m_noOfSpots; i++) {
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
      cout << m_noOfSpots - m_noOfParked << " *****" << endl;
      cout.unsetf(ios::left);
   }
   void Parking::parkVehicle()
   {
      if (m_noOfParked == m_noOfSpots) {
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
            m_noOfParked++;
            cout << endl << "Parking Ticket" << endl;
            tmpV->write(cout);
            pause();
            break;
         case 2:
            tmpV = new Motorcycle;
            tmpV->setCsv(false);
            tmpV->read(cin);
            m_parkingSpots[index] = tmpV;
            m_parkingSpots[index]->setParkingSpot(index + 1);
            m_noOfParked++;
            cout << endl << "Parking Ticket" << endl;
            tmpV->write(cout);
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
      cout << "---------------------------------" << endl;
      cout << "Returning Vehicle" << endl;
      cout << "---------------------------------" << endl;
      cout << endl;
   }
   void Parking::listParkedVehicle()
   {
      cout << "*** List of parked vehicles ***" << endl;
      for (int i = 0; i < m_noOfSpots; i++) {
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
      char temp_plate[9] ="\0";
      int index = -1;
      cout << "Vehicle Search" << endl;
      cout << "Enter Licence Plate Number: ";
      do {
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
         }
         cin.getline(temp_plate, 9, '\n');
         if (cin.fail()) cout << "Invalid Licence Plate, try again: ";
      } while (cin.fail());
      for (int i = 0; index < 0 &&  i < m_noOfSpots; i++) {
         if (m_parkingSpots[i]  && *m_parkingSpots[i] == temp_plate) {
            index = i;
         }
      }
      cout << endl;
      if (index == -1) {
         cout << "License plate " << temp_plate << " Not found" << endl;
      }
      else {
         m_parkingSpots[index]->setCsv(false);
         cout << "Vehicle found:" << endl << *m_parkingSpots[index];
         m_parkingSpots[index]->setCsv(true);
      }
      pause();
   }
   int Parking::findEmptySpot()
   {
      int index = -1;
      for (int i = 0; index < 0 && i < m_noOfSpots; i++) {
         if (!m_parkingSpots[i]) {
            index = i;
         }
      }
      return index;
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
}