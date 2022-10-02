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
   class NameTag {
      char m_name[51];
      int m_nameLen;
   public:
      void set(const char* name);
      char* getName();
      int getLen();
      NameTag();
      ~NameTag();
   };
}


#endif // !SDDS_NAMETAG_H_