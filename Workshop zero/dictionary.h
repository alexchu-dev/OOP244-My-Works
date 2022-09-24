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
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#define MAX_WORDS 100
#include "word.h"
namespace sdds {
   struct Dictionary {
      int m_wordCount;
      Word m_words[MAX_WORDS];
   };
   bool readTypeDef( int wordIndex, int defIndex);
   bool readWord( int wordIndex);
   bool readDict();
   int LoadDictionary(const char* filename);
   void SaveDictionary(const char* filename);
   int SearchFor(const char* word);
   void DisplayTypeDef(const int index);
   void DisplayWord(const char* word);
   void AddWord(const char* word, const char* type, const char* definition);
   int UpdateDefinition(const char* word, const char* type, const char* definition);
   
}
#endif // !SDDS_DICTIONARY_H
