#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
namespace sdds {
   class Seat {
      char* m_paxName;
      int m_row;
      char m_seat;
   private:
      bool validate(int row, char letter)const;
   };
}
#endif // !SDDS_SEAT_H_


