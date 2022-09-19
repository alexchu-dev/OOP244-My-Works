#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   struct Word word[MAX_WORD_FILE];
   int LoadDictionary(const char* filename){
      fptr = fopen(filename, "r+");
      int flag, i;
      if (fptr != NULL) {
         for (i = 0; i < MAX_WORD_FILE;i++){
            fscanf(fptr, "%s",word[i].m_word);
            do {
            fscanf(fptr, "\t%[^:]: %[^\n]", word[i].m_type, word[i].m_definition);
            } while (fscanf(fptr, "%s") != '\t');
            cout << word[i].m_word << endl;
            
         }
         
         flag = 0;
         fclose(fptr);
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
      /*while (getline(myfile, line, '\t')
         && getline(myfile, type, ':')
         && getline(myfile, definition, '\n')
         )
      {
         cout << line << '\t' << type << ':' << definition << '\n';
      }*/
      //cout << "Enter word to search for: ";
      //cin >> search;
      //getline(inFile, line); // get line from file
      //pos = line.find(search); // search
      //if (pos != string::npos) // string::npos is returned if string is not found
      //{
      //   cout << "Found!";
      //   break;
      //}
      
   }
   void AddWord(const char* word, const char* type, const char* definition) {

   }
   int UpdateDefinition(const char* word, const char* type, const char* definition) {
      return 0;
   }
  
}