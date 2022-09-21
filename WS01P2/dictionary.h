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
   void DisplayWord(const char* word);
   void AddWord(const char* word, const char* type, const char* definition);
   int UpdateDefinition(const char* word, const char* type, const char* definition);
   
}
#endif // !SDDS_DICTIONARY_H
