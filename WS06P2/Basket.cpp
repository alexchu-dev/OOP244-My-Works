/******************************************************************************
//                    OOP244NAA - WS06 Part 2 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include "Basket.h"
using namespace std;
namespace sdds {
   Basket::Basket()
   {
      setEmpty();
   }
   Basket::Basket(Fruit* fruits, int size, double price)
   {
      setEmpty();
      if (fruits != nullptr && size > 0 && price > 0) {
         m_size = size;
         m_price = price;
      }
   }
   Basket::Basket(const Basket& src)
   {
      setEmpty();
      *this = src; // calls assignment operator
   }
   Basket& Basket::operator=(const Basket& src)
   {
      // check for self-assignment
      if (this != &src) {
         // deallocate previous allocated dynamic memory
         deallocate();
         setEmpty();
         if (src.m_fruits != nullptr) {
            m_fruits = new Fruit[src.m_size];
            for (int i = 0; i < src.m_size; i++) {
               m_fruits[i] = src.m_fruits[i];
            }
            m_size = src.m_size;
            m_price = src.m_price;
         }
      }
      return *this;
   }
   Basket::~Basket()
   {
   }
   void Basket::setPrice(double price)
   {
   }
   Basket::operator bool() const
   {
      return true;
   }
   Basket& Basket::operator+=(const Fruit& src)
   {
      return *this;
   }
   bool Basket::isEmpty() const
   {
      return m_fruits == nullptr;
   }

   void Basket::setEmpty()
   {
      m_fruits = nullptr;
      m_size = 0;
      m_price = 0;
   }

   void Basket::deallocate()
   {
      delete[] m_fruits;
   }
}