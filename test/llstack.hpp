//Kyle Hatfield
//llstack.hpp


using namespace std;
const int INIT_TO_ZERO = 0;

//---------------------------Big Three (destructor inline)----------

//operator=
template <class T>
const LLStack<T>& LLStack<T>::operator=(const LLStack<T>& rhs)
{
  clear();
  LLStack * scanIt = rhs.m_next;
  LLStack * sendIt = this;
  sendIt->m_data = rhs.m_data;
  while (scanIt != NULL)
  {
    sendIt->m_next = new LLStack;
    sendIt = sendIt->m_next;
    sendIt->m_data = scanIt->m_data;
    scanIt = scanIt->m_next;
  }
  return *this;
}

//copy constructor
template <class T>
LLStack<T>::LLStack(const LLStack& rhs)
{
  LLStack * scanIt = rhs.m_next;
  LLStack * sendIt = this;
  sendIt->m_data = rhs.m_data;
  while (scanIt != NULL)
  {
    sendIt->m_next = new LLStack;
    sendIt = sendIt->m_next;
    sendIt->m_data = scanIt->m_data;
    scanIt = scanIt->m_next;
  }
}
  //---------------------------given in abstrackstack.h---------

//isEmpty
template <class T>
bool LLStack<T>::isEmpty() const
{
 	bool empty = false;
 	if (m_next == NULL)
 		empty = true;
 	return empty;
}

/*
  //top
template <class T>
const T& LLStack<T>::top() const throw ( Oops )
{
	return m_data;
}


//push
template <class T>
void LLStack<T>::push(const T& x)
{
  LLStack * tmp = new LLStack;
 	tmp->m_next = m_next;
	m_next = tmp;
	tmp->m_data = m_data;
	m_data = x;
	return;
}


//pop
template <class T>
void LLStack<T>::pop()
{
 	LLStack* tmp = m_next;
 	if(m_next != NULL)
 	{
 		m_data = tmp -> m_data;
		m_next = tmp -> m_next;
		delete tmp;
	}
	return;
}

//clear
template <class T>
void LLStack<T>::clear()
{
  if (m_next == NULL)
    return;
  else
  {
    LLStack * tmpNext = m_next;
    LLStack * tmpCurrent = m_next;
    while (tmpNext->m_next != NULL)
    {
      tmpNext = tmpNext->m_next;
      delete tmpCurrent;
      tmpCurrent = tmpNext;
    }
    delete tmpNext;
    m_next = NULL;
    m_data = 0;
    return;
  }
}*/