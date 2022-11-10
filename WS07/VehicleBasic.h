/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 9 Nov 2022
Section: NAA
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>
namespace sdds
{
   class VehicleBasic {
      char m_plate[9];
      char m_address[64];
      int m_year;

   public:
      VehicleBasic();
      VehicleBasic(const char* plate, const int year);
      void setEmpty();
      void NewAddress(const char* address);
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);
   };
   std::ostream& operator << (std::ostream& ostr, const VehicleBasic& vehicle);
   std::istream& operator >> (std::istream& istr, VehicleBasic& vehicle);
}
#endif