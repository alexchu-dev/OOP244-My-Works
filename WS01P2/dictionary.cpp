#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
using namespace std;
namespace sdds {
   FILE* fptr = nullptr;
   int LoadDictionary(const char* filename){
      //The following part is using fstream
      int flag;
      Dictionary dict[MAX_WORD_FILE] = { 0 };
      Word word[MAX_WORD_FILE] = { 0 };
      string line;
      string type;
      string definition;
      string linetab;
      string linebreak;
      ifstream myfile(filename);
      if (myfile.is_open())
      {
         flag = 0;
         while (getline(myfile, line))
         {
            if(!myfile.eof()){
               for (int i = 0; i < MAX_WORD_FILE; i++)
               {
                  
                  while (getline(myfile, linetab, '\t'))
                  {
                     cout << 2 << linetab << endl;
                     while (getline(myfile, type, '\n'))
                     {
                        cout << 3 << type << endl;
                        cout << 4 << definition << endl;
                     }
                  }
               }
            }
         }
         myfile.close();

         
         /*
         while (getline(myfile, line))
         {
            cout << 1 << line << endl;
            while (getline(myfile,linetab,'\t'))
            {
               cout << 2 << linetab << endl;
               while (getline(myfile, type, '\n'))
               {
                  cout << 3 << type << endl;
                  cout << 4 << definition << endl;
               }
            }
         }
         */
         
         /*while (getline(myfile, line,'\n')
            && getline(myfile, linetab, '\t')
            && getline(myfile, type, ':')
            && getline(myfile, definition, '\n')
            && getline(myfile, linebreak, '\t')
            )
         {
            cout << 1 << line << endl;
            cout << 2 << linetab << endl;
            cout << 3 << type << endl;
            cout << 4 << definition << endl;
            cout << 2 << linetab << endl;
         }
         myfile.close();*/
      }
      else {
         flag = 1;
      }
      return flag;
       
      
      /*fptr = fopen(filename, "r+");
      int flag;
      if (fptr != NULL) {
         flag = 0;
      }
      else
      {
         flag = 1;
      }
      return flag;
      if (fptr)
         fclose(fptr);*/
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