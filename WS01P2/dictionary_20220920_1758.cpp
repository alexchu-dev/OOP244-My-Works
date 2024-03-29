#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "dictionary.h"

using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   struct Dictionary dict;

   /* Pseudocodes by Fardad
   readTypeDef:
      skip a tab, read upto ':', skip a colon and a space, read the definition up to '\n', skip the '\n'
      fscanf(...,"\t%[^:]: %[\n]\n",...) == 2;

      read a word:
      read a the word up to '\n', skip '\n.
      while readTypeDef has not failed and less than 8, keep going
   read the dictionary
      while readword has not failed and less than 100, keep going

         for (i = 0; i <MAX_WORDS; i++) {
            fscanf(fptr, "%[^\n]\n",dict.m_words[i].m_word);
            fscanf(fptr, "\t%[^:]: %[^\n]\n", dict.m_words[i].defs->m_type, dict.m_words[i].defs->m_definition);
            cout << i << dict.m_words[i].m_word << endl;
            cout << i << dict.m_words[i].defs->m_type << endl;
            cout << i << dict.m_words[i].defs->m_definition << endl;

         }

      */
   int readTypeDef(const char* word, int wordIndex, int tdIndex) {
      int flag;
      flag = fscanf(fptr, "\t%[^:]: %[^\n]\n", dict.m_words[wordIndex].defs[tdIndex].m_type, dict.m_words[wordIndex].defs[tdIndex].m_definition); //returns 2 if successful
      return flag;
   }
   int readWord(const char* word, int wordIndex) {
      dict.m_words[wordIndex].m_tdCount = 0;
      int flag;
      int tdIndex = 0;
      flag = fscanf(fptr, "%[^\n]\n", dict.m_words[wordIndex].m_word); // returns 1 if successful
      do {
         readTypeDef(word, wordIndex, tdIndex);
         tdIndex++;
         dict.m_words[wordIndex].m_tdCount++;
      } while (readTypeDef(word, wordIndex, tdIndex) == 2 && tdIndex < MAX_DEF);

      return flag;
   }
   int readDict(const char* word) {
      dict.m_wordCount = 0;
      int flag;  //initially this flag is meant to receive one and return, but LoadDictionary needs a 0 to work.
      int wordIndex;
      for (wordIndex = 0; wordIndex < MAX_WORDS; wordIndex++) {
         flag = readWord(word, wordIndex);
         if (flag == 1) {
            dict.m_wordCount++;
         }
      }
      return 0;
   }

   int LoadDictionary(const char* filename) {
      fptr = fopen(filename, "r+");
      int flag;
      if (fptr != NULL) {
         flag = readDict(filename);  //readDict would return 0 no matter what in this case

         //Testing Output, failed to output properly which means my input logic has sth wrong?
         cout << "wordCount is " << dict.m_wordCount << endl;
         for (int i = 0; i < dict.m_wordCount; i++)
            cout << "word " << i << " is " << dict.m_words[i].m_word << endl;
         cout << "Testing Output of Word 0" << endl;
         cout << "Word 0:\t" << dict.m_words[0].m_word << endl;
         cout << "Def 0:\t" << dict.m_words[0].defs[0].m_type << endl;
         cout << "Type 0:\t" << dict.m_words[0].defs[0].m_definition << "\n" << endl;
         cout << "Testing Output of Word 1" << endl;
         cout << "Word 0:\t" << dict.m_words[0].m_word << endl;
         cout << "Def 1:\t" << dict.m_words[0].defs[1].m_type << endl;
         cout << "Type 1:\t" << dict.m_words[0].defs[1].m_definition << endl;
         cout << "Testing Output of Word 1" << endl;
         cout << "Word 1:\t" << dict.m_words[1].m_word << endl;
         cout << "Def 1:\t" << dict.m_words[1].defs[1].m_type << endl;
         cout << "Type 1:\t" << dict.m_words[1].defs[1].m_definition << endl;

         /*for (int i = 0; i < dict.m_wordCount; i++) {
            cout << "Testing Output of Word " << i << endl;
            cout << "Word " << i << ":\t" << dict.m_words[i].m_word << endl;
            for (int j = 0; j < dict.m_words[i].m_tdCount; j++) {
               cout << "tdCount is " << dict.m_words[i].m_tdCount << endl;
               cout << "Def " << j << ":\t" << dict.m_words[i].defs[j].m_type << endl;
               cout << "Type " << j << ":\t" << dict.m_words[i].defs[j].m_definition << "\n" << endl;
               cout << "Testing Output of Word 1" << endl;
               cout << "Word 1:\t" << dict.m_words[1].m_word << endl;
               cout << "Def 0:\t" << dict.m_words[1].defs[0].m_type << endl;
               cout << "Type 0:\t" << dict.m_words[1].defs[0].m_definition << endl;
            }
         }*/

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

/*
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