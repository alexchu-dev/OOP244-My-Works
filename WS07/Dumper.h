/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 9 Nov 2022
Section: NAA
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"
namespace sdds
{
	class Dumper : public VehicleBasic
	{
		double m_capacity;
		double m_currentLoad;
	public:
		Dumper();
		Dumper(const char* plate, const int year, const double capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator << (std::ostream& ostr, const Dumper& dumper);
	std::istream& operator >> (std::istream& istr, Dumper& dumper);



}
#endif

