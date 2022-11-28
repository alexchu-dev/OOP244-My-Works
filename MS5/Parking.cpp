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
      cout << "Press <ENTER> to continue...." << endl;
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
      char ch;
      if (!isEmpty()) {
         ifstream fin(m_filename);
         if (fin.is_open()) {
            while (fin.get(ch)) {
               fin.ignore();
               if (ch == 'M' || ch == 'm') {
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
               else if (ch == 'C' || ch == 'c') {
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
      int selection = 0;
      m_vehicleMenu.display();
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
      cout << "*** List of parked vehicles ***" << endl;
      for (int i = 0; i < m_noOfSpots; i++) {
         if (m_parkingSpots[i] != nullptr) {
            m_parkingSpots[i]->setCsv(false);
            m_parkingSpots[i]->write(cout);
            cout << "-------------------------------" << endl;
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
         temp_plate[8] = '\0';
         if (cin.fail()) cout << "Invalid Licence Plate, try again: ";
      } while (cin.fail());
      for (int i = 0; index < 0 &&  i < m_noOfSpots; i++) {
         if(m_parkingSpots[i]) clog << *m_parkingSpots[i] << endl;
         if (m_parkingSpots[i]  && *m_parkingSpots[i] == temp_plate) {
            index = i;
            cout << "Found :" << index << endl;
         }
      }
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