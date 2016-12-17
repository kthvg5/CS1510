//Kyle Hatfield
//04/28/2015
//llqueue.hpp

using namespace std;

//isEmpty

template <class T>
bool LLQueue<T>::isEmpty() const
{
  bool empty = true;
  if (m_next != NULL)
    empty = false;
  return empty;
}

//front
template <class T>
const T& LLQueue<T>::front() const throw (Oops)
{
	return m_next -> m_next -> m_data;
}

//back
template <class T>
const T& LLQueue<T>::back() const throw (Oops)
{
	return m_next -> m_data;
}

//enqueue
template <class T>
void LLQueue<T>::enqueue(const T& x)
{
	if (m_next == NULL) //empty queue
	{
		m_next = new LLQueue;
		m_next -> m_data = x;
		m_next -> m_next = m_next;
	}
	else
	{
		LLQueue* tmp = new LLQueue;
		tmp -> m_data = x;
		tmp -> m_next = m_next -> m_next;
		m_next -> m_next = tmp;
		m_next = tmp;
	}
	return;
}

//dequeue
template <class T>
void LLQueue<T>::dequeue()
{
	if (m_next != NULL)
	{
		if (m_next == m_next -> m_next)
		{
			delete m_next;
			m_next = NULL;
		}
		else
		{
			LLQueue* tmp = m_next -> m_next -> m_next;
			delete m_next -> m_next;
			m_next -> m_next = tmp;
		}
	}
	return;
}

//clear
template <class T>
void LLQueue<T>::clear()
{
	LLQueue* scout = m_next -> m_next;
	LLQueue* killer = scout;
	while(killer != m_next)
	{
		scout = scout -> m_next;
		delete killer;
		killer = scout;
	}
	return;
}
