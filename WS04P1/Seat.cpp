#include <iostream>
#include "Seat.h"
namespace sdds {
   bool Seat::validate(int row, char letter)const {
      bool seatValid = false;
      bool jcl = (row >= 1 && row <= 4);
      bool pey = (row >= 7 && row <= 15);
      bool ycl = (row >= 20 && row <= 38);
      if (jcl)
         if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F') { seatValid = true; }
         else seatValid = false;
      else if (pey || ycl)
         if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F') { seatValid = true; }
         else seatValid = false;
      else
         seatValid = false;
      return seatValid;
   }
   Seat& Seat::alAndCp(const char* str) {
      m_paxName = nullptr;
      return *this;
   }
   Seat& Seat::reset() {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
      return *this;
   }
   bool Seat::isEmpty() const {
      return true;
   }
   bool Seat::assigned() const {
      return true;
   }
   Seat::Seat() {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
   }
   Seat::Seat(const char* passengerName) {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
   }
   Seat::Seat(const char* passengerName, int row, char letter) {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
   }
   Seat::~Seat() {
      m_paxName[0] = 0;
      m_row = 0;
      m_seat = 0;
   }
   Seat& Seat::set(int row, char letter) {
      return *this;
   }
   int Seat::row()const {
      return 0;
   }
   char Seat::letter()const {
      return 0;
   }
   const char* Seat::passenger()const {
      return nullptr;
   }
   std::ostream& Seat::display(std::ostream& coutRef) const {
      return coutRef;
   }
   std::istream& Seat::read(std::istream& cinRef) {
      return cinRef;
   }
}