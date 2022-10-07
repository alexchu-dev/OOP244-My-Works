/******************************************************************************
//                    OOP244NAA - WS04 Part 1 @ Oct 5 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>
namespace sdds {
   class Seat {
      char* m_paxName;
      int m_row;
      char m_seat;
      bool validate(int row, char letter)const;
      Seat& alAndCp(const char* str);
   public:
      Seat& reset();
      bool isEmpty() const;
      bool assigned() const;
      Seat();
      Seat(const char* passengerName);
      Seat(const char* passengerName, int row, char letter);
      ~Seat();
      Seat& set(int row, char letter);
      int row()const;
      char letter()const;
      const char* passenger()const;
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      std::istream& read(std::istream& cinRef = std::cin);
   };
}
#endif // !SDDS_SEAT_H_


