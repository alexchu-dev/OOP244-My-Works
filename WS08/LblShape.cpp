/******************************************************************************
//                    OOP244NAA - WS08 @ 14 Nov 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   const char* LblShape::label() const
   {
      return m_label;
   }
   LblShape::LblShape()
   {
      m_label = nullptr;
   }
   LblShape::LblShape(const char* label)
   {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }
   LblShape::~LblShape()
   {
      delete[] m_label;
      m_label = nullptr;
   }
   void LblShape::getSpecs(std::istream& istr)
   {
      char label[256];
      istr.get(label, 256, ',');
      istr.ignore(256, ',');
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }
}
