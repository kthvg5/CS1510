//Kyle Hatfield
//04/28/2015
//LLQueue.h

#ifndef LLQUEUE_H
#define LLQUEUE_H
#include "abstractqueue.h"

template <class T>
class LLQueue: public AbstractQueue<T> {
public:
	T  m_data; //pointer to T (which will be a spaceship here)
	LLQueue<T>* m_next; //points to next element in the queue

	//Default constructor
	//INLINE
	LLQueue() : m_next(NULL), m_data() {}

	//Auxilary constuctor
	//INLINE
	LLQueue(const T x, LLQueue<T>* p)
		:m_data(x), m_next(p) {}

	//-------------------------Big 3----------------

	//Destructor
	//INLINE
	~LLQueue(){}

	//Operator=
	const LLQueue<T>& operator= (const LLQueue<T>& rhs);

	//copy constructor
	LLQueue(const LLQueue<T>& rhs);


	//---------------------queue functions

	//isEmpty
	virtual bool isEmpty() const;

	//front
	virtual const T& front() const throw (Oops);

	//back
	virtual const T& back() const throw (Oops);

	//enqueue
	virtual void enqueue(const T& x);

	//dequeue
	virtual void dequeue();

	//clear
	virtual void clear();
};

#include "llqueue.hpp"

#endif