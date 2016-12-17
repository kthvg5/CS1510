//Kyle Hatfield
//04/20/2015
//llstack

#ifndef LLSTACK_H
#define LLSTACK_H
#include "abstractstack.h"
using namespace std;

template <class T>
class LLStack: public AbstractStack<T> {
public:
  T m_data;                  // Data to be stored
  LLStack<T>* m_next;     // Pointer to the next element in the list


    // Purpose: Default constructor
    // Postconditions: next pointer set to NULL
    // ---INLINE---
  LLStack() : m_next(NULL), m_data(0) {}

    // Purpose: Auxiliaty constructor, construct from parameters
    // Postconditions: data and next pointer set to parameters
    // ---INLINE---
  LLStack(const T& x, LLStack<T>* p) 
             : m_data(x), m_next(p) {}

 

  //-------------------Big 3----------------
  
  //Destructor
  //---INLINE---
  ~LLStack(){}

  //operator=
  const LLStack<T>& operator= (const LLStack<T>& rhs);

  //copy constructor
  LLStack(const LLStack<T>& rhs);


  //-------------------clear--------------


  //isEmpty
  virtual bool isEmpty() const;

  // Purpose: looks at the top of the stack
  // Returns: a const reference to the element currently on top of the stack
  // Exception: if the stack is empty, THROW a 'Oops' object with an error message!!!
  virtual const T& top() const throw ( Oops ) =0;

  // Purpose: push an element into the stack
  // Parameters: x is the value to push into the stack
  // Postconditions: x is now the element at the top of the stack,
  virtual void push(const T& x)=0;

  // Purpose: pop the stack
  // Postconditions: the element formerly at the top of the stack has
  // been removed
  // Note: Poping an empty stack results in an empty stack.
  virtual void pop()=0;


  // Purpose: clears the stack
  // Postconditions: the stack is now empty
  virtual void clear()=0;


};

// ---------------  Utility Function for Printing
// BONUS BONUS BONUS !!!!!!!
// Purpose: prints a LinkedList...err...Stack
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LLStack<T>& xlist)
{
  out << "[ ";
  const LLStack<T>* p = &xlist;
  while ( p->m_next != NULL ){
    out << p->m_data << ", ";
    p = p->m_next;
  } 
  out << "]"; 
  
  return out;
}

#include "llstack.hpp"

#endif