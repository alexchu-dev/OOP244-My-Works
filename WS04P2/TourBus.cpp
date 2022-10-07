/******************************************************************************
//                    OOP244NAA - WS04 Part 2 @ Oct 5 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include "TourBus.h"
using namespace std;
namespace sdds {
   TourBus::TourBus(int num) {
      m_tickets = nullptr;
      m_rows = 0;
   }
   TourBus::~TourBus() {
      delete[] m_tickets;
      m_tickets = nullptr;
   }
   bool validTour() {
      return true;
   }
}
