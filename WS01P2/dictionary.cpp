#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"
using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   int LoadDictionary(const char* filename){
      fptr = fopen(filename, "w");
      return fptr != NULL;
   }
   void SaveDictionary(const char* filename) {

   }
   void DisplayWord(const char* word) {

   }
   void AddWord(const char* word, const char* type, const char* definition) {

   }
   int UpdateDefinition(const char* word, const char* type, const char* definition) {
      return 0;
   }
}