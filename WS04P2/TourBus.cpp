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
      m_paxNum = 0;
      m_board = false;
      if (num == 4 || num == 16 || num == 22) {
         m_tickets = new TourTicket[num];
         m_paxNum = num;
      }
   }
   TourBus::~TourBus() {
      delete[] m_tickets;
      m_tickets = nullptr;
   }
   bool TourBus::validTour() const{
      return m_tickets != nullptr && (m_paxNum == 4 || m_paxNum == 16 || m_paxNum == 22);
   }
   TourBus& TourBus::board() {
      int i;
      m_board = false;
      char temp_name[41];
      cout << "Boarding " << m_paxNum << " Passengers:" << endl;
      for (i = 0; i < m_paxNum; i++) {
         cout << i + 1 << "/" << m_paxNum << "- " << "Passenger Name: ";
         cin.getline(temp_name,41);
         m_tickets[i].issue(temp_name);
      }
      if (i == m_paxNum) {
         m_board = true;
      }
      return *this;
   }
   void TourBus::startTheTour() const{
      int i;
      if (m_board == true) {
         cout << "Starting the tour...." << endl;
         cout << "Passenger List:" << endl;
         cout << "|Row | Passenger Name                           | Num |" << endl;
         cout << "+----+------------------------------------------+-----+" << endl;
         for (i = 0; i < m_paxNum; i++) {
            cout << "| ";
            cout.width(2);
            cout << i + 1;
            cout << " ";
            m_tickets[i].display();
            cout << endl;
         }
         cout << "+----+------------------------------------------+-----+" << endl;
      }
      else {
         cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
      }
   }
}



