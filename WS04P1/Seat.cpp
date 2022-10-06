#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Seat.h"
namespace sdds {
   //Private method to return true if the row number and the seating letter, together correctly address a seat in the airplane. This method is a query, hence it does not modify the current object.
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
   //Allocate memory for passenger name and copy the value into the allocated memory. Return the reference of the current object in case it is needed in the caller function
   Seat& Seat::alAndCp(const char* str) {
      m_paxName = nullptr;
      if (str != nullptr) {
         m_paxName = new char[strlen(str) + 1];
         strcpy(m_paxName, str);
      }
      return *this;
   }
   //This function resets the object into a safe empty state
   Seat& Seat::reset() {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
      return *this;
   }
   //Returns if the object is in an empty state by returning true if the passenger name pointer attribute is nullptr and false otherwise
   bool Seat::isEmpty() const {
      return m_paxName == nullptr;
   }
   //Returns true if the seats are assigned and valid by returning the validate method call result
   bool Seat::assigned() const {
      return m_row != 0 && m_seat != 0;
   }
   //Sets the object to the safe empty state as in reset method.
   Seat::Seat() {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
   }
   //If passengerName argument is a valid and non-empty Cstring, this constructor will allocate memory for passenger name in the passenger name pointer attribute and then copies the content of the passenger name argument into the newly allocated memory.
   Seat::Seat(const char* passengerName) {
      delete[] m_paxName;
      m_paxName = nullptr;
      if (passengerName != nullptr && passengerName != "") {
         m_paxName = new char[strlen(passengerName) + 1];
         strcpy(m_paxName, passengerName);
      }
      m_row = 0;
      m_seat = 0;
   }
   //Set corresponding values of pax name and seat after validation. If not, set to 0.
   Seat::Seat(const char* passengerName, int row, char letter) {
      delete[] m_paxName;
      m_paxName = nullptr;
      if (passengerName != nullptr && passengerName != "") {
         m_paxName = new char[strlen(passengerName) + 1];
         strcpy(m_paxName, passengerName);
         set(row, letter);
      }
      else {
         m_row = 0;
         m_seat = 0;
      }
   }
   Seat::~Seat() {
      delete[] m_paxName;
      m_paxName = nullptr;
      m_row = 0;
      m_seat = 0;
   }
   Seat& Seat::set(int row, char letter) {
      if (validate(row, letter)) {
         m_row = row;
         m_seat = letter;
      }
      else {
         m_row = 0;
         m_seat = 0;
      }
      return *this;
   }
   int Seat::row()const {
      return m_row;
   }
   char Seat::letter()const {
      return m_seat;
   }
   const char* Seat::passenger()const {
      return m_paxName;
   }
   std::ostream& Seat::display(std::ostream& coutRef) const {
      if (isEmpty()) {
         coutRef << "Invalid Seat!";
      }
      else {
         char temp_paxName[41];
         strncpy(temp_paxName, m_paxName, sizeof(temp_paxName));
         temp_paxName[sizeof(temp_paxName) - 1] = '\0';
         coutRef.width(40);
         coutRef.fill('.');
         coutRef.setf(std::ios::left);
         coutRef << temp_paxName;
         coutRef.unsetf(std::ios::left);
         if (assigned()){
            coutRef << " " << m_row << m_seat;
         }
         else {
            coutRef << " ___";
         }
      }
      return coutRef;
   }
   std::istream& Seat::read(std::istream& cinRef) {
      reset();
      char temp_paxName[71];
      int temp_row;
      char temp_seat;
      cinRef.getline(temp_paxName, 71, ',');

      
      return cinRef;
   }
}