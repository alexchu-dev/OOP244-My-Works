/*
*****************************************************************************
                    OOP244NAA - WS01 Part 2 @ Sep 21 2022
Full Name  : Alex Chu
Student ID#: 153954219
Email      : kchu30@myseneca.ca

Citation:
My teacher has offered assistance in the LoadDictionary, readTypeDef, readWord, readDict etc to help me proceed further with my work.
Otherwise, I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_WORD_H
#define SDDS_WORD_H
#define MAX_DEF 8
namespace sdds {
   struct TypeDef {
      char m_type[64];
      char m_definition[1024];
   };
   struct Word {
      char m_word[64];
      int m_tdCount;
      TypeDef defs[MAX_DEF];
   };

}
#endif