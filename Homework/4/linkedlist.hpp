//Kyle Hatfield 12396364
//Date: Pi Day 2015

using namespace std;
const int INIT_TO_ZERO = 0;
//-----------------Big Three (destructor inline)----------------

//operator=
template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  clear();
  LinkedList * scanIt = rhs.m_next;
  LinkedList * sendIt = this;
  sendIt->m_data = rhs.m_data;
  while (scanIt != NULL)
  {
    sendIt->m_next = new LinkedList;
    sendIt = sendIt->m_next;
    sendIt->m_data = scanIt->m_data;
    scanIt = scanIt->m_next;
  }
  return *this;
}

//copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList& rhs)
{
  LinkedList * scanIt = rhs.m_next;
  LinkedList * sendIt = this;
  sendIt->m_data = rhs.m_data;
  while (scanIt != NULL)
  {
    sendIt->m_next = new LinkedList;
    sendIt = sendIt->m_next;
    sendIt->m_data = scanIt->m_data;
    scanIt = scanIt->m_next;
  }
}

//------------------------Basic Accessor------------------------

//size
template <class T>
int LinkedList<T>::size() const
{
  const LinkedList * runner = this;
  int counter = INIT_TO_ZERO;

  while (runner->m_next != NULL)
  {
    runner = runner->m_next;
    counter++;
  }
  return counter;
}

//isEmpty
template <class T>
bool LinkedList<T>::isEmpty() const
{
  bool empty = false;
  if (m_next == NULL)
    empty = true;
  return empty;
}

//getFirstPtr
template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if (this->m_next == NULL)
  {
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list" << endl;
    return NULL;
  }
  return this;
}

//getLastPtr
template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  if (this->m_next == NULL)
  {
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list" << endl;
    return NULL;
  }
  else
  {
    LinkedList * tmp = this;
    while (tmp->m_next->m_next != NULL)
      tmp = tmp->m_next;
    cout << "GIVE ME AN ERROR MESSAGE!!!" << endl;
    return tmp;
  }
}

//getAtPtr
template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  int trueIndex = size();
  LinkedList * pointerExtractionSpecialist = this;
  int kitchenCounter = INIT_TO_ZERO;
  if (i >= trueIndex)
  {
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index";
    cout << endl;
    return NULL;
  }
  while (kitchenCounter < i && pointerExtractionSpecialist->m_next != NULL)
  {
    pointerExtractionSpecialist = pointerExtractionSpecialist->m_next;
    kitchenCounter++;
  }
  return pointerExtractionSpecialist;
}

//-------------------------Basic Mutator-----------------------

//clear
template <class T>
void LinkedList<T>::clear()
{
  if (m_next == NULL)
    return;
  else
  {
    LinkedList * tmpNext = m_next;
    LinkedList * tmpCurrent = m_next;
    while (tmpNext->m_next != NULL)
    {
      tmpNext = tmpNext->m_next;
      delete tmpCurrent;
      tmpCurrent = tmpNext;
    }
    delete tmpNext;
    m_next = NULL;
    m_data = NULL;
    return;
  }
}

//insert_front
template <class T>
void LinkedList<T>::insert_front(const T& x)
{
  LinkedList * tmp = new LinkedList;
  tmp->m_next = m_next;
  m_next = tmp;
  tmp->m_data = m_data;
  m_data = x;
  return;
}

//insert
template <class T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList * tmp = new LinkedList;
  tmp->m_data = pos->m_data;
  tmp->m_next = pos->m_next;
  pos->m_data = x;
  pos->m_next = tmp;
  return;
}

//remove
template <class T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList<T> * scapegoat = pos->m_next;
  pos->m_next = scapegoat->m_next;
  pos->m_data = scapegoat->m_data;
  delete scapegoat;
  return;
}

//---------------------------Complex Operations-----------------

//operator==
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
  const LinkedList * anythingYouCanDo = this;
  const LinkedList * iCanDoBetter = NULL;
  bool weAreOne = true;
  if (anythingYouCanDo->m_data != rhs.m_data)
  {
    weAreOne = false;
    return weAreOne;
  }
  else if (rhs.m_next != NULL && anythingYouCanDo->m_next != NULL)
  {
    anythingYouCanDo = anythingYouCanDo->m_next;
    iCanDoBetter = rhs.m_next;
    while (anythingYouCanDo->m_next != NULL && iCanDoBetter->m_next != NULL)
    {
      if (anythingYouCanDo->m_data != iCanDoBetter->m_data)
      {
        weAreOne = false;
        return weAreOne;
      }
      anythingYouCanDo = anythingYouCanDo->m_next;
      iCanDoBetter = iCanDoBetter->m_next;
    }
  }
  if ((anythingYouCanDo == NULL && iCanDoBetter != NULL) ||
    (anythingYouCanDo != NULL && iCanDoBetter == NULL))
    weAreOne = false;
  return weAreOne;
}

//find
template <class T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList * theGreatPointerDetective = this;
  while (theGreatPointerDetective->m_data != x && theGreatPointerDetective
    ->m_next->m_next != NULL)
    theGreatPointerDetective = theGreatPointerDetective->m_next;
  if (theGreatPointerDetective->m_data == x)
    return theGreatPointerDetective;
  else
  {
    cout << "It would appear that value x could not be found in me" << endl;
    return NULL;
  }
}

//reverse
template <class T>
void LinkedList<T>::reverse()
{
  int rooler = size();
  T * dataRip = new T[rooler];
  LinkedList * scribe = this;
  for (int i = INIT_TO_ZERO; i < rooler; i++)
  {
    dataRip[i] = scribe->m_data;
    scribe = scribe->m_next;
  }
  scribe = this;
  for (int i = rooler; i > INIT_TO_ZERO; i--)
  {
    scribe->m_data = dataRip[i - 1];
    scribe = scribe->m_next;
  }
  delete[] dataRip;
}

//append
template <class T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  LinkedList * becomeImmense = new LinkedList;
  LinkedList * delve = this;
  *becomeImmense = xlist;
  while (delve->m_next->m_next != NULL)
    delve = delve->m_next;
  delete delve->m_next;
  delve->m_next = becomeImmense;
  return;
}