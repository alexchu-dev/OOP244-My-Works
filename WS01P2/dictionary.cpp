#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"
using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   int LoadDictionary(const char* filename){
      fptr = fopen(filename, "r+");
      int flag;
      if (fptr != NULL) {
         flag = 0;
         //fclose(fptr);
      }
      else
      {
         flag = 1;
      }
      return flag;
   }
   void SaveDictionary(const char* filename) {

   }
   void DisplayWord(const char* word) {
      //fgets(word, 100, pFile);
      //puts(word);
   }
   void AddWord(const char* word, const char* type, const char* definition) {

   }
   int UpdateDefinition(const char* word, const char* type, const char* definition) {
      return 0;
   }
   
}