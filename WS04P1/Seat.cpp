#include <iostream>
#include "Seat.h"
namespace sdds {
   bool Seat::validate(int row, char letter)const {
      bool seatValid = false;
      bool jcl = (row >= 1 && row <= 4);
      bool pey = (row >= 7 && row <= 15);
      bool ycl = (row >= 20 && row <= 38);
      if (jcl)
         seatValid = (letter == 'A' || 'B' || 'E' || 'F');
      else if (pey || ycl)
         seatValid = (letter == 'A' || 'B' || 'C' || 'D' || 'E' || 'F');
      else
         seatValid = false;
      return seatValid;
   }
   /*bool validate(int row, char letter) {
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
   }*/
}