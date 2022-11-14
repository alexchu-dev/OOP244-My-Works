/*
Name: Alex Chu
Email: kchu30@myseneca.ca
Student ID: 153954219
Data: 14 Nov 2022
Section: NAA
*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds 
{
   class Shape {
   public:
      virtual void draw(std::ostream& ostr) const = 0; //draw() is a pure virtual function returns void and receives a ref to ostream as argument)
      virtual  void getSpecs(std::istream& istr) = 0; //getSpecs() is a pure virtual function returns void and recieves a ref to istream as argument)
      virtual ~Shape() {}; //virtual empty destructor for shape interface to ensure any dynam allocated derived class from the shape interface pointed by a base class pointer will be removed when deleted
   };
   //Shape helper functions
   std::ostream& operator<<(std::ostream& ostr, const Shape& S);
   std::istream& operator>>(std::istream& istr, Shape& S);
}
#endif