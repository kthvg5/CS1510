//Kyle Hatfield 12396364
//calcWithFuncs.hpp

using namespace std;
  //top
template <class T>
const T& calcWithFuncs<T>::top() const throw ( Oops )
{
	return m_data;
}

//pop
template <class T>
void calcWithFuncs<T>::pop()
{
 	calcWithFuncs* tmp = m_next;
 	if(m_next != NULL)
 	{
 		m_data = tmp -> m_data;
		m_next = tmp -> m_next;
		delete tmp;
	}
	return;
}

//push
template <class T>
void calcWithFuncs<T>::push(const T& x)
{
  calcWithFuncs * tmp = new calcWithFuncs;
 	tmp->m_next = m_next;
	m_next = tmp;
	tmp->m_data = m_data;
	m_data = x;
	return;
}

//clear
template <class T>
void calcWithFuncs<T>::clear()
{
  while(m_next!= NULL)
  	pop();
}

// +
template <class T>
void calcWithFuncs<T>::add()
{
	T Smitty = top();
	pop();
	T werbenjagermanjensen = top();
	pop();
	T Number_ONE = Smitty + werbenjagermanjensen;
	this->push(Number_ONE);
	return;
}

// -
template <class T>
void calcWithFuncs<T>::minus()
{
	T subtractMe = top();
	pop();
	T fromMe = top();
	pop();
	T toGetMe = fromMe-subtractMe;
	this->push(toGetMe);
	return;
}

// *
template <class T>
void calcWithFuncs<T>::multiply()
{
	T mult1 = top();
	pop();
	T mult2 = top();
	pop();
	T product = mult2 * mult1;
	this->push(product);
	return;
}

// /
template <class T>
void calcWithFuncs<T>::iCutChuUp()
{
	T byMe = top();
	pop();
	T devideMe = top();
	pop();
	T toGetMe = devideMe / byMe;
	this->push(toGetMe);
	return;
}

// %
template <class T>
void calcWithFuncs<T>::allThatRemains()
{
	T modedByMe = top();
	pop();
	T Me = top();
	pop();
	T iAm = Me /modedByMe;
	this->push(iAm);
	return;
}

// !
template <class T>
void calcWithFuncs<T>::emoBand()
{
	T becomeNegative = top();
	pop();
	becomeNegative *= -1;
	this->push(becomeNegative);
	return;
}

// SUM
template <class T>
void calcWithFuncs<T>::addEmUp()
{
	T running_total = INIT_TO_ZERO;
	calcWithFuncs * get_sum = this;
	while(get_sum->m_next != NULL)
	{
		running_total += get_sum -> m_data;
		get_sum = get_sum -> m_next;
	}
	this->push(running_total);
	return;
}

// R
template <class T>
void calcWithFuncs<T>::backAsswards()
{
	const calcWithFuncs * rooler = this;
	int counter = INIT_TO_ZERO;
	while (rooler->m_next != NULL)
	{
	  rooler = rooler->m_next;
	  counter++;
	}
  T * dataRip = new T[counter];
  calcWithFuncs * scribe = this;
  for (int i = INIT_TO_ZERO; i < counter; i++)
  {
    dataRip[i] = scribe->m_data;
    scribe = scribe->m_next;
  }
  scribe = this;
  for (int i = counter; i > INIT_TO_ZERO; i--)
  {
    scribe->m_data = dataRip[i - 1];
    scribe = scribe->m_next;
  }
  delete[] dataRip;
  return;
}

// #
template <class T>
void calcWithFuncs<T>::spitThatOutRightNow()
{
	cout << *this << endl;
	return;
}

// &
template <class T>
void calcWithFuncs<T>::omNomNom()
{
	clear();
	return;
}