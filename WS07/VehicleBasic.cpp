/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 9 Nov 2022
Section: NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
   VehicleBasic::VehicleBasic()
   {
      setEmpty();
   }
   VehicleBasic::VehicleBasic(const char* plate, const int year)
   {
      if (plate != nullptr && year > 0)
      {
         strcpy(m_plate, plate);
         strcpy(m_address, "Factory");
         m_year = year;
      }
      else {
         setEmpty();
      }
   }
   void VehicleBasic::setEmpty()
   {
      m_plate[0] = '\0';
      m_address[0] = '\0';
      m_year = 0;
   }
   void VehicleBasic::NewAddress(const char* address)
   {
      if (address != nullptr)
      {
         cout << "|";
         cout.width(8);
         cout.setf(ios::right);
         cout << m_plate;
         cout.unsetf(ios::right);
         cout << "| |";
         cout.width(20);
         cout.setf(ios::right);
         cout << m_address;
         cout.unsetf(ios::right);
         cout << " ---> ";
         cout.width(20);
         cout.setf(ios::left);
         cout << address;
         cout << "|" << endl;
         cout.unsetf(ios::left);
         strcpy(m_address, address);
      }
      else {
         setEmpty();
      }
   }
   std::ostream& VehicleBasic::write(std::ostream& os)const
   {
      return os << "| " << m_year << " | " << m_plate << " | " << m_address;
   }
   std::istream& VehicleBasic::read(std::istream& in)
   {
      cout << "Built year: ";
      in >> m_year;
      cout << "License plate: ";
      in >> m_plate;
      cout << "Current location: ";
      in >> m_address;
      return in;
   }
   std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& vehicle)
   {
      return vehicle.write(ostr);
   }
   std::istream& operator>>(std::istream& istr, VehicleBasic& vehicle)
   {
      return vehicle.read(istr);
   }
}
