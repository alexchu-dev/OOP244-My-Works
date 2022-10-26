/******************************************************************************
//                    OOP244NAA - WS06 Part 2 @ Oct 24 2022
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds {
   struct Fruit
   {
      char m_name[30 + 1]; // the name of the fruit
      double m_qty;        // quantity in kilograms
   };
   class Basket
   {
      Fruit* m_fruits;
      int m_size;
      double m_price;
      bool isEmpty()const; //check empty
      void setEmpty(); //set empty state
      void deallocate(); //deallocate memory
   public:
      Basket(); //default constructor
      Basket(Fruit* fruits, int size, double price); //custom constructor
      Basket(const Basket& src); //copy constructor
      Basket& operator=(const Basket& src); //copy assignment operator
      ~Basket(); //destructor
      void setPrice(double price); //update price attribute
      operator bool() const; //conversion operator
      Basket& operator+=(const Fruit& src); //overload += add fruits
   };
}
#endif // !SDDS_BASKET_H_