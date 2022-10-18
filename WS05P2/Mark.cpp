/******************************************************************************
//                    OOP244NAA - WS05 Part 2 @ Oct 16 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"
#include <iostream>
using namespace std;
namespace sdds
{
   //Constructors
   Mark::Mark() {
      m_value = 0;
   }
   Mark::Mark(int value) {
      if (isValid(value))
      {
         m_value = value;
      }
      else
      {
         m_value = 0;
         m_invalid = 1;  //invalid empty state
      }
   }
   bool Mark::isValid(int value) {
      return value >= 0 && value <= 100;
   }
   Mark::operator bool() const {
      return m_invalid==0;
   }
   Mark::operator int() const {
      return m_value;
   }
   Mark::operator double() const {
      double ret;
      if (m_value >= 0 && m_value <= 49)
      {
         ret = 0.0;
      }
      else if (m_value >= 50 && m_value <= 59)
      {
         ret = 1.0;
      }
      else if (m_value >= 60 && m_value <= 69)
      {
         ret = 2.0;
      }
      else if (m_value >= 70 && m_value <= 79)
      {
         ret = 3.0;
      }
      else if (m_value >= 80 && m_value <= 100)
      {
         ret = 4.0;
      }
      else
      {
         ret = 0.0;
      }
      return ret;
   }
   Mark::operator char() const {
      char ret;
      if (m_value >= 0 && m_value <= 49)
      {
         ret = 'F';
      }
      else if (m_value >= 50 && m_value <= 59)
      {
         ret = 'D';
      }
      else if (m_value >= 60 && m_value <= 69)
      {
         ret = 'C';
      }
      else if (m_value >= 70 && m_value <= 79)
      {
         ret = 'B';
      }
      else if (m_value >= 80 && m_value <= 100)
      {
         ret = 'A';
      }
      else
      {
         ret = 'X';
      }
      return ret;
   }
  
   bool Mark::operator>(int value)const {
      return m_value > value;
   }
   bool Mark::operator<(int value)const {
      return m_value < value;
   }
   bool Mark::operator>=(int value)const {
      return m_value >= value;
   }
   bool Mark::operator<= (int value)const {
      return m_value <= value;
   }
   bool Mark::operator== (int value)const {
      return m_value == value;
   }
   bool Mark::operator!= (int value)const {
      return m_value != value;
   }
   Mark& Mark::operator++() {
      if (isValid(m_value + 1))
      {
         m_value++;
      }
      else {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark Mark::operator++(int) {
      Mark m = *this;
      if (isValid(m_value + 1))
      {
         ++(*this);
      }
      else {
         m_value = 0;
         m_invalid = 1;
      }
      return m;
   }
   Mark& Mark::operator--() {
      if (isValid(m_value - 1))
      {
         m_value--;
      }
      else {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark Mark::operator--(int) {
      Mark m = *this;
      if (isValid(m_value - 1))
      {
        --(*this);
      }
      else {
         m_value = 0;
         m_invalid = 1;
      }
      return m;
   }
   bool Mark::operator~()const {
      return m_value >= 50 && m_value <= 100;
   }
   Mark& Mark::operator=(int value) {
      if (isValid(value))
      {
         m_value = value;
         m_invalid = 0;
      }
      else
      {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark& Mark::operator+=(int value) {
      if (isValid(m_value + value))
      {
         m_value += value;
      }
      else
      {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark& Mark::operator-=(int value) {
      if (isValid(m_value - value))
      {
         m_value -= value;
      }
      else
      {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark& Mark::operator<<(Mark& rhs) {
      if (isValid(m_value + rhs.m_value))
      {
         m_value = m_value + rhs.m_value;
         rhs.m_value = 0;
      }
      else
      {
         m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark& Mark::operator>>(Mark& rhs) {
      if (isValid(m_value + rhs.m_value))
      {
         rhs.m_value = rhs.m_value + m_value;
         m_value = 0;
      }
      else
      {
         rhs.m_value = 0;
         m_invalid = 1;
      }
      return *this;
   }
   Mark operator+(const Mark& mark, const int value) {
      Mark temp = mark;
      if (mark.getMark() + value >= 0 && mark.getMark() + value <= 100)
      {
         temp += value;
      }
      else
      {
         temp = -1;
      }
      return temp;
   }
   Mark operator+(const int value, const Mark& mark) {
      Mark temp = mark;
      if (mark.getMark() + value >= 0 && mark.getMark() + value <= 100)
      {
         temp += value;
      }
      else
      {
         temp = -1;
      }
      return temp;
   }
   Mark operator+(const Mark& lhs, const Mark& rhs) {
      Mark temp = lhs;
      if (lhs.getMark() + rhs.getMark() >= 0 && lhs.getMark() + rhs.getMark() <= 100)
      {
         temp += rhs.getMark();
      }
      else
      {
         temp = -1;
      }
      return temp;
   }
   int operator+=(int& value, const Mark& mark) {
      return value += mark.getMark();
   }
   int operator+=(const Mark& mark, int& value) {
      return value += mark.getMark();
   }
   int operator-=(int& value, const Mark& mark) {
      return value -= mark.getMark();
   }
   int operator-=(const Mark& mark, int& value) {
      return value -= mark.getMark();
   }

} 