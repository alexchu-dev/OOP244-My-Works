/******************************************************************************
//                    OOP244NAA - WS10 @ 30 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
#include "Collection.h"
namespace sdds {
   template <typename T>
   bool search(const T arr[], const int size, const char* key, Collection<T>& res) {
      bool ret = false;
      for (int i = 0; i < size; i++) {
         if (arr[i] == key) {
            res.add(arr[i]);
            ret = true;
         }
      }
      return ret;
   }   
}

#endif