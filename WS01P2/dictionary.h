#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include "word.h"
namespace sdds {
   int LoadDictionary(const char* filename);
   void SaveDictionary(const char* filename);
   void DisplayWord(const char* word);
   void AddWord(const char* word, const char* type, const char* definition);
   int UpdateDefinition(const char* word, const char* type, const char* definition);
   const int MAX_WORD_FILE = 100;
   struct Dictionary {
      int wordQty = 0;
      Word* words = nullptr;
   };




}
#endif // !SDDS_DICTIONARY_H
