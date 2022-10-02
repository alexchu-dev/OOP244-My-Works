/******************************************************************************
//                    OOP244NAA - WS03 Part 2 @ Sep 30 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
namespace sdds {
   //create a NameTag class to hold a name up to 50 chars (not dynamic) and print it with a frame around it.
   class NameTag {
      char m_name[51];
   public:
      void set(const char* name);
   };
}


#endif // !SDDS_NAMETAG_H_