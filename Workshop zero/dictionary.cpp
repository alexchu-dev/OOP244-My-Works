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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "dictionary.h"

using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   struct Dictionary dict;

   bool readTypeDef( int wordIndex, int tdIndex) {
      char ch = fgetc(fptr);
      bool ret = false;
      if(ch == '\t') {
         ret = fscanf(fptr, "%[^:]: %[^\n]",
                dict.m_words[wordIndex].defs[tdIndex].m_type,
                dict.m_words[wordIndex].defs[tdIndex].m_definition) == 2 && fgetc(fptr) == '\n'; //returns 2 if successful
      }
      return ret;
   }
   bool readWord( int wordIndex) {
      int& tdCount = dict.m_words[wordIndex].m_tdCount;
      tdCount = 0;
      bool flag = fscanf(fptr, "%[^\n]", dict.m_words[wordIndex].m_word) == 1 && fgetc(fptr) == '\n'; // returns 1 if successful
      while (flag && readTypeDef( wordIndex, tdCount) && tdCount < MAX_DEF)
         tdCount++;
      return flag && tdCount > 0;
   }

   bool readDict() {
      int& wordIndex = dict.m_wordCount = 0;
      for(wordIndex = 0; readWord( wordIndex) && wordIndex < MAX_WORDS; wordIndex++);
      return wordIndex > 0;
   }

   int LoadDictionary(const char* filename) {
      fptr = fopen(filename, "r");
      bool flag{};
      if(fptr != NULL) {
         flag = readDict();  //readDict would return 0 no matter what in this case
         fclose(fptr);
      }
      return !flag;  // zero for success
   }
   void SaveDictionary(const char* filename) {
      //the line below is trying to use ofstream. I tried to use fprintf but it didn't work, this one is much faster and easier.
      ofstream myfile;
      myfile.open(filename);
      for (int i = 0; i < dict.m_wordCount; i++) {
         myfile << dict.m_words[i].m_word << endl;
         for (int j = 0; j < dict.m_words[i].m_tdCount; j++) {
            myfile << "\t" << dict.m_words[i].defs[j].m_type;
            myfile << ": " << dict.m_words[i].defs[j].m_definition << endl;
         }
         myfile <<endl;
      }
      myfile.close();
      memset(&dict, 0, sizeof(dict)); //Memory Reset!!
   }
   int SearchFor(const char* word) {
      int index = -1;
      for (int i = 0; i < dict.m_wordCount; i++)
      {
         if (strcmp(word, dict.m_words[i].m_word) == 0) {
            index = i;
         }
      }
      return index;
   }
   void DisplayTypeDef(const int index) {
      for (int tdIndex = 0; tdIndex < dict.m_words[index].m_tdCount; tdIndex++) {
         cout << tdIndex + 1 << ". {" << dict.m_words[index].defs[tdIndex].m_type << "} " << dict.m_words[index].defs[tdIndex].m_definition << endl;
      }
   }
   void DisplayWord(const char* word) {
      int index = SearchFor(word);
      if (index >= 0) {
         cout << "FOUND: [" << dict.m_words[index].m_word << "] has [" << dict.m_words[index].m_tdCount << "] definitions:" << endl;
         DisplayTypeDef(index);
      }
      else
         cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
   }
   void AddWord(const char* word, const char* type, const char* definition) {
      /*sdds::AddWord("fine", "verb", "clarify (beer or wine) by causing the precipitation of sediment during production.");
      sdds::AddWord("fine", "verb", "make or become thinner.");*/
      int index = SearchFor(word);
      if (index >= 0) {
         int tdIndex = dict.m_words[index].m_tdCount;
         strcpy(dict.m_words[index].defs[tdIndex].m_type, type);
         strcpy(dict.m_words[index].defs[tdIndex].m_definition, definition);
         dict.m_words[index].m_tdCount++;
      }
      else {
         index = dict.m_wordCount;
         strcpy(dict.m_words[index].m_word, word);
         int tdIndex = dict.m_words[index].m_tdCount;
         strcpy(dict.m_words[index].defs[tdIndex].m_type, type);
         strcpy(dict.m_words[index].defs[tdIndex].m_definition, definition);
         dict.m_wordCount++;
         dict.m_words[index].m_tdCount++;
      }
      
   }
   int UpdateDefinition(const char* word, const char* type, const char* definition) {
      /*Func call is UpdateDefinition("apple", "noun", "the tree which bears apples.");*/
      int index = SearchFor(word);
      int tdIndex=0;
      if (index >= 0)
      {
         if (dict.m_words[index].m_tdCount > 1)
         {
            cout << "The word [" << word << "] has multiple definitions:" << endl;
            DisplayTypeDef(index);
            cout << "Which one to update? ";
            cin >> tdIndex;
            tdIndex--;
            strcpy(dict.m_words[index].defs[tdIndex].m_type, type);
            strcpy(dict.m_words[index].defs[tdIndex].m_definition, definition);
         }
      }
    return 0;
   }
  
}

/* Pseudocodes by Fardad
fine
   adjective: of high quality.
   adjective: (of a thread, filament, or person's hair) thin.
   noun: very small particles found in mining, milling, etc.
   adverb: in a satisfactory or pleasing manner; very well.

fine
   adjective: of high quality.
   adjective: (of a thread, filament, or person's hair) thin.
   noun: very small particles found in mining, milling, etc.
   adverb: in a satisfactory or pleasing manner; very well.

fine
   adjective: of high quality.
   adjective: (of a thread, filament, or person's hair) thin.
   noun: very small particles found in mining, milling, etc.
   adverb: in a satisfactory or pleasing manner; very well.


   readTypeDef:
      skip a tab, read upto ':', skip a colon and a space, read the definition up to '\n', skip the '\n'
      fscanf(...,"\t%[^:]: %[\n]\n",...) == 2;

   read a word:
      read a the word up to '\n', skip '\n.
      while readDef has not failed and less than 8, keep going

   read the dictionary
      while readword has not failed and less than 100, keep going


*/