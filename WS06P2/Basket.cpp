/******************************************************************************
//                    OOP244NAA - WS06 Part 2 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
         m_fruits = fruits;
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
         if (src.m_fruits != nullptr) {
            deallocate();
            m_fruits = new Fruit[src.m_size];
            for (int i = 0; i < src.m_size; i++) {
               m_fruits[i] = src.m_fruits[i];
            }
            m_size = src.m_size;
            m_price = src.m_price;
         }
         else {
            setEmpty();
            deallocate();
         }
      }
      return *this;
   }
   Fruit& Basket::operator=(const Fruit& src)
   {
      strcpy(m_fruits->m_name, src.m_name);
      m_fruits->m_qty = src.m_qty;
      return *m_fruits;
   }
   Basket::~Basket()
   {
      //deallocate();
   }
   void Basket::setPrice(double price)
   {
      if (price)
         m_price = price;
   }
   Basket::operator bool() const
   {
      return (m_fruits != nullptr);
   }
   Basket& Basket::operator+=(const Fruit& src)
   {
         Fruit* temp = new Fruit[m_size + 1];
         for (int i = 0; i < m_size; i++) {
            temp[i] = m_fruits[i];
         }
         temp[m_size] = src;
         m_size++;
         delete[] m_fruits;
         m_fruits = temp;
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
      m_fruits = nullptr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Basket& src)
   {
      if (src.m_fruits != nullptr) {
         ostr << "Basket Content:" << endl;
         ostr.setf(ios::right);
         for (int i = 0; i < src.m_size; i++) {
            ostr.width(10);
            ostr << src.m_fruits[i].m_name << ": ";
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << src.m_fruits[i].m_qty << "kg" << endl;
            ostr.unsetf(ios::fixed);
         }
         ostr.unsetf(ios::right);
         ostr.setf(ios::fixed);
         ostr.precision(2);
         ostr << "Price: " << src.m_price << endl;
         ostr.unsetf(ios::fixed);
      }
         
      else
         ostr << "The basket is empty!" <<endl;
      return ostr;
   }
}