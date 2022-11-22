/***********************************************************************
// ReadWritable Module
// File  ReadWritable.cpp
// Version 0.12
// Date  16 Nov 2022
// Author   Alex Chu
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Alex Chu        22 Nov 2022     Removed m_parkingSpot=0 in Vehicle(2 args) constructor and added descriptions
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   //Combined Vehicle constructors with no arg and 2 args
   Vehicle::Vehicle(const char* plate, const char* makeModel)
   {
      setEmpty(); //set to invalid empty state if plate and makeModel are null or invalid
      if (plate != nullptr && plate[0] != '\0' && strlen(plate) <9 && makeModel != nullptr && makeModel[0] != '\0' && strlen(makeModel) >= 2) {
         strcpy(m_plate, plate);
         setMakeModel(makeModel);
      }
   }
   //Rules of three below - Copy Constructor, Copy Assignment Operator & Destructor
   //Default base class Destructor which inherits to Car and Motorcycle as well.
   Vehicle::~Vehicle()
   {
      delete[] m_makeModel;
   }
   //Copy Constructor of Vehicle class, it relies on the Copy Assignment Operator
   Vehicle::Vehicle(const Vehicle& v)
   {
      *this = v; //calls copy assignment operator
   }
   //Copy Assignment Operator
   Vehicle& Vehicle::operator=(const Vehicle& v)
   {
      if (this != &v) {
         //Shallow copy fist
         if (v.m_plate != nullptr) {
            strcpy(m_plate, v.m_plate);
         }
         setParkingSpot(v.m_parkingSpot);
         setCsv(v.isCsv());
         //DMA starts, call setMakeModel to copy resource data
         setMakeModel(v.m_makeModel);        
      }
      return *this;
   }
   //Opeartor== overloading, LHS is Vehicle object, RHS is plate char array
   bool Vehicle::operator==(const char* plate) const
   {
      //Using toUpper. In case if the assigned value of the Vehicle "a" or the input plate sttring is not in upper case, two strings are to be copied to temp values first then compare.
      char temp_plate1[9] = { '\0' };
      char temp_plate2[9] = { '\0' };
      strcpy(temp_plate1, plate);
      toUpper(temp_plate1);
      strcpy(temp_plate2, m_plate);
      toUpper(temp_plate2);
      return !strcmp(temp_plate1, temp_plate2);
   }
   //Opeartor== overloading, LHS is Vehicle object, RHS is another Vehicle object
   bool Vehicle::operator==(const Vehicle& b) const
   {
      //Note: Check if it can use the other operator overloading
      char temp_plate1[9] = { '\0' };
      char temp_plate2[9] = { '\0' };
      strcpy(temp_plate1, m_plate);
      toUpper(temp_plate1);
      strcpy(temp_plate2, b.m_plate);
      toUpper(temp_plate2);
      return !strcmp(temp_plate1, temp_plate2);
   }
   //PROTECTED MEMBER: Clean up all values and set to safe empty states (can be used by the derived classes)
   void Vehicle::setEmpty()
   {
      m_plate[0] = '\0';
      delete[] m_makeModel;
      m_makeModel = nullptr;
      m_parkingSpot = 0;
   }
   //PROTECTED MEMBER: Check if the value of the Vehicle is empty (can be used by the derived classes)
   bool Vehicle::isEmpty() const
   {
      return (m_makeModel == nullptr || m_plate[0] == '\0');
   }
   //PROTECTED MEMBER: Return the plate value (can be used by the derived classes)
   const char* Vehicle::getLicensePlate() const
   {
      return m_plate;
   }
   //PROTECTED MEMBER: Return the makeModel value (can be used by the derived classes)
   const char* Vehicle::getMakeModel() const
   {
      return m_makeModel;
   }
   //PROTECTED MEMBER: Alcpy the makeModel (can be used by the derived classes)
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
   //Return parking spot value
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
   //Input information by CSV or User input. 
   std::istream& Vehicle::read(std::istream& istr)
   {
      char temp_makeModel[61];
      if (isCsv()) {
         istr >> m_parkingSpot;
         istr.ignore();
         istr.getline(m_plate, 9, ',');
         toUpper(m_plate);
         istr.getline(temp_makeModel, 61, ',');
         setMakeModel(temp_makeModel);
      }
      else {
         cout << "Enter License Plate Number: ";
         //Loop input validation by istream fail
         do {
            if (istr.fail()) {
               istr.clear();
               istr.ignore(1000, '\n');
            }
            istr.getline(m_plate, 9, '\n');
            if (istr.fail()) cout << "Invalid License Plate, try again: ";
         } while (istr.fail());
         toUpper(m_plate);

         cout << "Enter Make and Model: ";
         bool minLen; //Minimum Length Failure boolean to flag if lower than min length
         do {
            if (istr.fail()) {
               istr.clear();
               istr.ignore(1000, '\n');
            }
            istr.getline(temp_makeModel, 61, '\n');
            minLen = strlen(temp_makeModel) < 2;
            if (istr.fail() || minLen) cout << "Invalid Make and model, try again: ";
         } while (istr.fail() || minLen);
         setMakeModel(temp_makeModel);

      }
      if (istr.fail())
      {
         setEmpty();
      }
      return istr;
   }
   //Ouput information by CSV or User Input
   std::ostream& Vehicle::write(std::ostream& ostr) const
   {
      if (isEmpty()) {
         ostr << "Invalid Vehicle Object" << endl;
      }
      else {
         writeType(ostr);
         if (isCsv()) {
            ostr << m_parkingSpot << "," << m_plate << "," << m_makeModel << ",";
         }
         else {
            ostr << "Parking Spot Number: ";
            if (m_parkingSpot == 0) {
               ostr << "N/A" << endl;
            }
            else {
               ostr << m_parkingSpot << endl;
            }
            ostr << "License Plate: " << m_plate << endl;
            ostr << "Make and Model: " << m_makeModel << endl;
         }
      }
      return ostr;
   }
}