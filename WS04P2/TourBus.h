/******************************************************************************
//                    OOP244NAA - WS04 Part 2 @ Oct 5 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include "TourTicket.h"
namespace sdds {
   class TourBus {
      TourTicket* m_tickets;
      int m_paxNum;
      bool m_board;
   public:
      TourBus(int num);
      ~TourBus();
      bool validTour()const;
      TourBus& board();
      void startTheTour()const;
   };









}
#endif // !SDDS_TOURBUS_H_

