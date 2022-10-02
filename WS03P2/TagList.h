/******************************************************************************
//                    OOP244NAA - WS03 Part 2 @ Sep 30 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
namespace sdds {
   class TagList {
      NameTag* m_NameTag;
      int m_noOfTags;
   public:
      void set();
      void set(int num);
      void add(const NameTag& nt);
      void print();
      void cleanup();
   };
}
#endif // !SDDS_TAGLIST_H_