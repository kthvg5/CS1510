//Kyle Hatfield
//calcWithFuncs.h

#ifndef CALCWITHFUNCS_H
#define CALCWITHFUNCS_H

#include "llstack.h"

using namespace std;

template <class T>
class calcWithFuncs: public LLStack<T>{
public:
  T m_data;                  // Data to be stored
  calcWithFuncs<T>* m_next;     // Pointer to the next element in the list


    // Purpose: Default constructor
    // Postconditions: next pointer set to NULL
    // ---INLINE---
  calcWithFuncs() : m_next(NULL), m_data(0) {}

    // Purpose: Auxiliaty constructor, construct from parameters
    // Postconditions: data and next pointer set to parameters
    // ---INLINE---
  calcWithFuncs(const T& x, calcWithFuncs<T>* p) 
             : m_data(x), m_next(p) {}
  // Purpose: pop the stack
  // Postconditions: the element formerly at the top of the stack has
  // been removed
  // Note: Poping an empty stack results in an empty stack.
  virtual void pop();

    // Purpose: looks at the top of the stack
  // Returns: a const reference to the element currently on top of the stack
  // Exception: if the stack is empty, THROW a 'Oops' object with an error message!!!
  virtual const T& top() const throw ( Oops );

   // Purpose: clears the stack
  // Postconditions: the stack is now empty
  virtual void clear();
  // Purpose: push an element into the stack
  // Parameters: x is the value to push into the stack
  // Postconditions: x is now the element at the top of the stack,
  virtual void push(const T& x);

	// +
	void add();

	// -
	void minus();

	// *
	void multiply();

	// /
	void iCutChuUp();//divison

	// %
	void allThatRemains();//modulo

	// !
	void emoBand(); //mult by -1

	// SUM
	void addEmUp(); //adds up everything

	// R
	void backAsswards(); //reverses

	// #
	void spitThatOutRightNow(); //prints

	// &
	void omNomNom(); //clears data



};

template <typename T>                 
std::ostream& operator<< (std::ostream& out, const calcWithFuncs<T>& xlist)
{
  out << "[ ";
  const calcWithFuncs<T>* p = &xlist;
  while ( p->m_next != NULL ){
    out << p->m_data << ", ";
    p = p->m_next;
  } 
  out << "]"; 
  
  return out;
}


#include "calcWithFuncs.hpp"
#endif
/*The input will consist of a series of integer expressions in post-fix notation. Elements of the expression are separated by spaces. 
You will implement the following robot integer expression operators:
Binary operators ‘+’, ‘-’, ‘*’, ‘/’, ‘%’   with their usual meanings.
Unary operator ‘!’ negation... (Example... 5 !  produces  -5 )
Aggregate operator ‘SUM’ : the sum all the elements in the stack.
Stack operator ‘R’ : reverses the content of the stack.
Stack operator ‘#’ : prints the content of the stack.
Stack operator ‘$’ : clears the stack.

Character ‘@’ will denote the end of the input.*/