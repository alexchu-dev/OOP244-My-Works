/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 9 Nov 2022
Section: NAA
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
	Dumper::Dumper()
	{
		m_capacity = 0;
		m_currentLoad = 0;
	}
   Dumper::Dumper(const char* plate, const int year, const double capacity, const char* address) : VehicleBasic(plate, year)
	{
		if (plate != nullptr && year > 0 && capacity > 0 && address != nullptr)
		{
			m_capacity = capacity;
			m_currentLoad = 0;
			NewAddress(address);
		}
		else {
			setEmpty();
			m_capacity = 0;
			m_currentLoad = 0;
		}
	}

	bool Dumper::loaddCargo(double cargo)
	{
		bool load = false;
		if (cargo > 0 && (m_currentLoad + cargo <= m_capacity))
		{
			m_currentLoad += cargo;
			load = true;
		}
		else {
			load = false;
		}
		return load;
	}

	bool Dumper::unloadCargo()
	{
		bool unload = false;
		if (m_currentLoad > 0)
		{
			m_currentLoad = 0;
			unload = true;
		}
		else {
			unload = false;
		}
		return unload;
	}

	std::ostream& Dumper::write(std::ostream& os) const
	{
      VehicleBasic::write(os);
      os << " | " << m_currentLoad << "/" << m_capacity;
		return os;
	}

	std::istream& Dumper::read(std::istream& in)
	{
		VehicleBasic::read(in);
		cout << "Capacity: ";
      in >> m_capacity;
		cout << "Cargo: ";
      in >> m_currentLoad;
		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const Dumper& dumper)
	{
		return dumper.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Dumper& dumper)
	{
		return dumper.read(istr);
	}

}

